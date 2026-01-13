#include <M5Atom.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <AccelStepper.h>

// ================= PINS =================
#define MOTOR_PIN1 22
#define MOTOR_PIN2 19
#define MOTOR_PIN3 23
#define MOTOR_PIN4 33

#define BUZZER1 21   // G21 HIGH
#define BUZZER2 25   // G25 LOW

// ================= STEPPER =================
AccelStepper stepper(AccelStepper::FULL4WIRE,
                     MOTOR_PIN1, MOTOR_PIN3,
                     MOTOR_PIN2, MOTOR_PIN4);

int stepsPerFeed = 200;
bool motorDirection = true;
bool motorRunning = false;
unsigned long motorStartTime = 0;

// ================= BUZZER =================
bool buzzerEnabled = false;   // controlled by B / b

// ================= BLE =================
#define SERVICE_UUID        "B0E6A4BF-CCCC-FFFF-330C-0000000000F0"
#define CHARACTERISTIC_UUID "B0E6A4BF-CCCC-FFFF-330C-0000000000F1"

BLEServer* pServer = nullptr;
BLECharacteristic* pCharacteristic = nullptr;

// ================= BLE CALLBACK =================
class MyCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic* characteristic) override {
    std::string value = characteristic->getValue();
    if (value.length() == 0) return;

    String rxValue = String(value.c_str());
    Serial.print("Received: ");
    Serial.println(rxValue);

    // ---- FEED ----
    if (rxValue == "s") {
      motorRunning = true;
      motorStartTime = millis();

      stepper.setMaxSpeed(600);
      stepper.setAcceleration(300);
      stepper.moveTo(motorDirection ? stepsPerFeed : -stepsPerFeed);
      motorDirection = !motorDirection;

      M5.dis.drawpix(0, 0xFF0000); // red during feed
    }

    // ---- BUZZER ENABLE ----
    else if (rxValue == "B") {
      buzzerEnabled = true;
      Serial.println("Buzzer enabled");
    }

    // ---- BUZZER DISABLE ----
    else if (rxValue == "b") {
      buzzerEnabled = false;
      digitalWrite(BUZZER1, LOW);
      digitalWrite(BUZZER2, LOW);
      Serial.println("Buzzer disabled");
    }

    // ---- CHANGE STEPS ----
    else {
      int newSteps = rxValue.toInt();
      if (newSteps > 0 && newSteps < 20000) {
        stepsPerFeed = newSteps;
        Serial.print("Steps per feed set to ");
        Serial.println(stepsPerFeed);
      }
    }
  }
};

void setup() {
  Serial.begin(115200);
  M5.begin(true, false, true);

  pinMode(BUZZER1, OUTPUT);
  pinMode(BUZZER2, OUTPUT);
  digitalWrite(BUZZER1, LOW);
  digitalWrite(BUZZER2, LOW);

  stepper.setMaxSpeed(600);
  stepper.setAcceleration(300);

  // BLE setup
  BLEDevice::init("PTFeeder");
  pServer = BLEDevice::createServer();
  BLEService* service = pServer->createService(SERVICE_UUID);

  pCharacteristic = service->createCharacteristic(
    CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_WRITE
  );

  pCharacteristic->setCallbacks(new MyCallbacks());
  service->start();

  BLEAdvertising* advertising = BLEDevice::getAdvertising();
  advertising->addServiceUUID(SERVICE_UUID);
  advertising->start();

  M5.dis.drawpix(0, 0xFFFFFF); // white = idle
  Serial.println("PTFeeder BLE ready");
}

void loop() {
  M5.update();

  // ---- MOTOR RUN ----
  if (motorRunning) {
    if (stepper.distanceToGo() != 0) {
      stepper.run();

      // ---- BUZZER DURING FEED ----
      if (buzzerEnabled && millis() - motorStartTime < 5000) {
        digitalWrite(BUZZER1, HIGH); // G21 HIGH
        digitalWrite(BUZZER2, LOW);  // G25 LOW
      } else {
        digitalWrite(BUZZER1, LOW);
        digitalWrite(BUZZER2, LOW);
      }
    } else {
      // Feed finished
      motorRunning = false;
      digitalWrite(BUZZER1, LOW);
      digitalWrite(BUZZER2, LOW);
      M5.dis.drawpix(0, 0x0000FF); // blue idle
    }
  }
}
