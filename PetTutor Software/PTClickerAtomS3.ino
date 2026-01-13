#include <M5Unified.h>
#include "boot_image.h"

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEClient.h>
#include "esp_sleep.h"

// ================= BLE UUIDs =================
#define SERVICE_UUID        "B0E6A4BF-CCCC-FFFF-330C-0000000000F0"
#define CHARACTERISTIC_UUID "B0E6A4BF-CCCC-FFFF-330C-0000000000F1"

// ================= Wake Button =================
#define WAKE_BUTTON GPIO_NUM_39

// ================= BLE Objects =================
BLEClient* pClient = nullptr;
BLERemoteCharacteristic* pRemoteCharacteristic = nullptr;

// ================= State =================
bool buzzerState = false;
bool isPressed = false;
bool holdIndicated = false;

unsigned long pressStartTime = 0;
unsigned long lastActivityTime = 0;
unsigned long lastReconnectAttempt = 0;

const unsigned long RECONNECT_INTERVAL = 5000;
const unsigned long SLEEP_AFTER_IDLE   = 180000; // 3 minutes

// =================================================
// ================= DISPLAY =======================
// =================================================
void showBootImage() {
  M5.Display.fillScreen(TFT_BLACK);
  M5.Display.drawBitmap(
    0, 0,
    128, 128,
    (const uint16_t*)bootImage
  );
}

void setScreen(uint16_t bg, const char* title, const char* status) {
  M5.Display.fillScreen(bg);
  M5.Display.setTextDatum(MC_DATUM);

  // Yellow screen uses black text
  if (bg == TFT_YELLOW) {
    M5.Display.setTextColor(TFT_BLACK);
  } else {
    M5.Display.setTextColor(TFT_WHITE);
  }

  M5.Display.setTextSize(2);
  M5.Display.drawString(title, 64, 40);

  M5.Display.setTextSize(1);
  M5.Display.drawString(status, 64, 78);
}

// =================================================
// ================= SLEEP =========================
// =================================================
void goToSleep() {
  setScreen(TFT_BLACK, "SLEEP", "");
  delay(300);

  esp_sleep_enable_ext0_wakeup(WAKE_BUTTON, 0);
  esp_deep_sleep_start();
}

// =================================================
// ================= BLE ===========================
// =================================================
bool connectToFeeder() {
  setScreen(TFT_YELLOW, "CONNECTING", "");

  BLEScan* scan = BLEDevice::getScan();
  scan->setActiveScan(true);

  BLEScanResults results = scan->start(5, false);

  for (int i = 0; i < results.getCount(); i++) {
    BLEAdvertisedDevice device = results.getDevice(i);

    if (device.haveServiceUUID() &&
        device.isAdvertisingService(BLEUUID(SERVICE_UUID))) {

      if (pClient->connect(&device)) {
        BLERemoteService* service =
          pClient->getService(BLEUUID(SERVICE_UUID));

        if (service) {
          pRemoteCharacteristic =
            service->getCharacteristic(BLEUUID(CHARACTERISTIC_UUID));

          if (pRemoteCharacteristic) {
            lastActivityTime = millis();
            setScreen(
              TFT_BLUE,
              "CONNECTED",
              buzzerState ? "BUZZER: ON" : "BUZZER: OFF"
            );
            return true;
          }
        }
      }
    }
  }

  return false;
}

void sendCommand(const char* cmd) {
  if (!pClient || !pClient->isConnected()) return;

  lastActivityTime = millis();

  if (cmd[0] == 's') {
    setScreen(TFT_RED, "FEED", "");
    pRemoteCharacteristic->writeValue((uint8_t*)cmd, 1, true);
    delay(2000);
  } else {
    pRemoteCharacteristic->writeValue((uint8_t*)cmd, 1, true);
  }

  setScreen(
    TFT_BLUE,
    "CONNECTED",
    buzzerState ? "BUZZER: ON" : "BUZZER: OFF"
  );
}

// =================================================
// ================= SETUP =========================
// =================================================
void setup() {
  auto cfg = M5.config();
  M5.begin(cfg);
  Serial.begin(115200);

  showBootImage();
  delay(2000);

  BLEDevice::init("PTClicker");
  pClient = BLEDevice::createClient();

  lastActivityTime = millis();
  connectToFeeder();
}

// =================================================
// ================= LOOP ==========================
// =================================================
void loop() {
  M5.update();

  // -------- Auto reconnect --------
  if (!pClient->isConnected()) {
    if (millis() - lastReconnectAttempt > RECONNECT_INTERVAL) {
      lastReconnectAttempt = millis();
      connectToFeeder();
    }

    if (millis() - lastActivityTime > SLEEP_AFTER_IDLE) {
      goToSleep();
    }

    delay(50);
    return;
  }

  // -------- Button pressed --------
  if (M5.BtnA.isPressed() && !isPressed) {
    pressStartTime = millis();
    isPressed = true;
    holdIndicated = false;
  }

  // -------- Hold preview --------
  if (isPressed && !holdIndicated &&
      millis() - pressStartTime >= 2000) {

    if (buzzerState) {
      setScreen(TFT_BLUE, "BUZZER OFF", "RELEASE");
    } else {
      setScreen(TFT_GREEN, "BUZZER ON", "RELEASE");
    }
    holdIndicated = true;
  }

  // -------- Button released --------
  if (M5.BtnA.wasReleased()) {
    unsigned long pressDuration = millis() - pressStartTime;
    isPressed = false;
    lastActivityTime = millis();

    if (pressDuration >= 2000) {
      buzzerState = !buzzerState;
      sendCommand(buzzerState ? "B" : "b");
    } else {
      sendCommand("s");
    }
  }

  if (millis() - lastActivityTime > SLEEP_AFTER_IDLE) {
    goToSleep();
  }

  delay(50);
}

