#include <M5Atom.h>
#include <BLEDevice.h>
#include <BLEClient.h>
#include <BLEUtils.h>
#include "esp_sleep.h"

// UUIDs must match the feeder
#define SERVICE_UUID        "B0E6A4BF-CCCC-FFFF-330C-0000000000F0"
#define CHARACTERISTIC_UUID "B0E6A4BF-CCCC-FFFF-330C-0000000000F1"

// Atom button GPIO (Atom & Atom S3)
#define WAKE_BUTTON GPIO_NUM_39

// BLE objects
BLEClient* pClient;
BLERemoteCharacteristic* pRemoteCharacteristic;

// Button tracking
unsigned long pressStartTime = 0;
bool isPressed = false;
bool holdIndicated = false;

// States
bool buzzerState = false;

// Timing
unsigned long lastActivityTime = 0;
unsigned long lastReconnectAttempt = 0;

const unsigned long reconnectInterval = 5000;
const unsigned long SLEEP_AFTER_IDLE = 60000; // 1 minute

// ---------------- LED Helper ----------------
void setLED(uint32_t color) {
  M5.dis.drawpix(0, color);
}

// ---------------- Deep Sleep ----------------
void goToSleep() {
  Serial.println("Going to deep sleep...");
  setLED(0xFF8000); // orange
  delay(300);

  setLED(0x000000); // off
  esp_sleep_enable_ext0_wakeup(WAKE_BUTTON, 0); // wake on button LOW
  esp_deep_sleep_start();
}

// ---------------- Send Command ----------------
void sendCommand(const char* cmd) {
  if (pRemoteCharacteristic && pClient->isConnected()) {
    lastActivityTime = millis();
    setLED(0xFF0000); // red = sending
    pRemoteCharacteristic->writeValue((uint8_t*)cmd, strlen(cmd), true);
    delay(300);
    setLED(buzzerState ? 0x00FF00 : 0x0000FF);
  } else {
    setLED(0x800080); // purple = error
  }
}

// ---------------- Connect to Feeder ----------------
bool connectToFeeder() {
  setLED(0xFFFF00); // yellow = scanning

  BLEScan* pScan = BLEDevice::getScan();
  pScan->setActiveScan(true);
  BLEScanResults results = pScan->start(5);

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
            setLED(buzzerState ? 0x00FF00 : 0x0000FF);
            lastActivityTime = millis();
            pScan->clearResults();
            return true;
          }
        }
      }
    }
  }

  pScan->clearResults();
  return false;
}

// ---------------- Setup ----------------
void setup() {
  M5.begin(true, false, true);
  Serial.begin(115200);

  setLED(0xFFFFFF); // white = boot

  BLEDevice::init("");
  pClient = BLEDevice::createClient();

  lastActivityTime = millis();
  connectToFeeder();
}

// ---------------- Loop ----------------
void loop() {
  M5.update();

  // Auto-reconnect
  if (!pClient->isConnected()) {
    if (millis() - lastReconnectAttempt > reconnectInterval) {
      lastReconnectAttempt = millis();
      connectToFeeder();
    }

    if (millis() - lastActivityTime > SLEEP_AFTER_IDLE) {
      goToSleep();
    }

    delay(50);
    return;
  }

  // Button pressed
  if (M5.Btn.isPressed() && !isPressed) {
    pressStartTime = millis();
    isPressed = true;
    holdIndicated = false;
  }

  // While holding button → preview buzzer toggle result
  if (isPressed && !holdIndicated) {
    if (millis() - pressStartTime >= 2000) {
      if (buzzerState) {
        setLED(0x0000FF); // blue = buzzer will turn OFF
      } else {
        setLED(0x00FF00); // green = buzzer will turn ON
      }
      holdIndicated = true;
    }
  }

  // Button released
  if (M5.Btn.wasReleased()) {
    unsigned long pressDuration = millis() - pressStartTime;
    isPressed = false;
    lastActivityTime = millis();

    if (pressDuration >= 2000) {
      buzzerState = !buzzerState;
      sendCommand(buzzerState ? "B" : "b");
    } else {
      sendCommand("s");
    }

    // Final LED state
    setLED(buzzerState ? 0x00FF00 : 0x0000FF);
  }

  // Sleep after idle
  if (millis() - lastActivityTime > SLEEP_AFTER_IDLE) {
    goToSleep();
  }

  delay(50);
}
