#include <NimBLEDevice.h>

// BLE UUIDs
#define SERVICE_UUID        "0000DEAD-0000-1000-8000-00805f9b34fb"
#define CHARACTERISTIC_UUID "0000BEEF-0000-1000-8000-00805f9b34fb"

// Motor pins
#define MOTOR_IN1 21
#define MOTOR_IN2 25

// Buzzer pins (using motor driver)
#define BUZZER_IN1 19
#define BUZZER_IN2 22

NimBLECharacteristic* pCharacteristic;
bool motorDirection = false;
unsigned long motorRunTime = 2000; // in milliseconds
bool buzzerEnabled = false;

// Clean input
std::string cleanInput(const std::string& input) {
  std::string cleaned;
  for (char c : input) {
    if (c >= 32 && c <= 126) {
      cleaned += c;
    }
  }
  return cleaned;
}

// Motor and buzzer functions
void runClockwise() {
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
}

void runCounterClockwise() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);
}

void stopMotor() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
}

void buzz() {
  digitalWrite(BUZZER_IN1, HIGH);
  digitalWrite(BUZZER_IN2, LOW);
  delay(500);
  digitalWrite(BUZZER_IN1, LOW);
  digitalWrite(BUZZER_IN2, LOW);
}

class CharacteristicCallbacks : public NimBLECharacteristicCallbacks {
  void onWrite(NimBLECharacteristic* pCharacteristic) override {
    std::string raw = pCharacteristic->getValue();
    Serial.print("Raw received: ");
    for (char c : raw) {
      Serial.print("[");
      Serial.print((int)c);
      Serial.print("]");
    }
    Serial.println();

    std::string value = cleanInput(raw);
    Serial.print("Cleaned input: ");
    Serial.println(value.c_str());

    if (value == "ON") {
      buzzerEnabled = true;
      Serial.println("Buzzer enabled.");
      pCharacteristic->setValue("buzzer on");
      pCharacteristic->notify();
      return;
    }

    if (value == "OFF") {
      buzzerEnabled = false;
      Serial.println("Buzzer disabled.");
      pCharacteristic->setValue("buzzer off");
      pCharacteristic->notify();
      return;
    }

    if (value == "f") {
      if (buzzerEnabled) {
        Serial.println("Buzzing before feed...");
        buzz();
      }

      if (motorDirection) {
        Serial.println("Running motor: COUNTERCLOCKWISE");
        runCounterClockwise();
      } else {
        Serial.println("Running motor: CLOCKWISE");
        runClockwise();
      }

      motorDirection = !motorDirection;
      delay(motorRunTime);
      stopMotor();
      Serial.println("Motor stopped.");

      pCharacteristic->setValue("done");
      pCharacteristic->notify();
      return;
    }

    // Try to parse as float for duration
    char* end;
    float seconds = strtof(value.c_str(), &end);
    if (end != value.c_str() && *end == '\0') {
      motorRunTime = (unsigned long)(seconds * 1000.0f);
      Serial.print("Updated motor duration to: ");
      Serial.print(motorRunTime);
      Serial.println(" ms");

      std::string response = "duration set to " + std::to_string(seconds) + " s";
      pCharacteristic->setValue(response);
      pCharacteristic->notify();
    } else {
      Serial.println("Unknown command");
      pCharacteristic->setValue("unknown command");
      pCharacteristic->notify();
    }
  }
};

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE PTMini");

  // Motor pins
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  stopMotor();

  // Buzzer pins
  pinMode(BUZZER_IN1, OUTPUT);
  pinMode(BUZZER_IN2, OUTPUT);
  digitalWrite(BUZZER_IN1, LOW);
  digitalWrite(BUZZER_IN2, LOW);

  // BLE setup
  NimBLEDevice::init("PTMini");
  NimBLEServer* pServer = NimBLEDevice::createServer();
  NimBLEService* pService = pServer->createService(SERVICE_UUID);

  pCharacteristic = pService->createCharacteristic(
    CHARACTERISTIC_UUID,
    NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::WRITE | NIMBLE_PROPERTY::NOTIFY
  );

  pCharacteristic->setCallbacks(new CharacteristicCallbacks());
  pCharacteristic->setValue("Ready");

  pService->start();
  NimBLEAdvertising* pAdvertising = NimBLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->start();

  Serial.println("BLE advertising as PTMini started...");
}

void loop() {
  // Nothing in loop
}
