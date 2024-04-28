#include <Arduino.h>
#include "BluetoothSerial.h"

#define Mot11 5
#define Mot12 18
#define Mot21 19
#define Mot22 21

// Define tasks for the second core
TaskHandle_t CoreTask;

// Bluetooth object
BluetoothSerial ESP_BT;

// Parameters for Bluetooth interface and timing
volatile int incoming = -1; // volatile as it's accessed in interrupt
portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;

void forward();
void backward();
void left();
void right();
void stop();
void core_task(void *pvParameters);
void setup() {
  Serial.begin(115200);
  ESP_BT.begin("TEZZA");

  // Set pins for motor control
  pinMode(Mot11, OUTPUT);
  pinMode(Mot12, OUTPUT);
  pinMode(Mot21, OUTPUT);
  pinMode(Mot22, OUTPUT);

  // Create task for the second core
  xTaskCreatePinnedToCore(
    core_task,      // Function to execute
    "CoreTask",     // Task name
    10000,          // Stack size (bytes)
    NULL,           // Task parameters
    1,              // Priority (1 is higher)
    &CoreTask,      // Task handle
    1               // Core to run the task (core 1)
  );
}

void loop() {
  // Main loop can handle Bluetooth communication and primary motor control
  if (ESP_BT.available()) {
    portENTER_CRITICAL(&mux);
    incoming = ESP_BT.read();
    portEXIT_CRITICAL(&mux);
  }
}

// Task to handle motor control based on Bluetooth commands
void core_task(void *pvParameters) {
  for (;;) {
    portENTER_CRITICAL(&mux);
    switch (incoming) {
      case 128:
        forward();
        break;
      case 129:
        backward();
        break;
      case 130:
        left();
        delay(250);
        stop();
        break;
      case 131:
        right();
        delay(250);
        stop();
        break;
      default:
        stop();
        break;
    }
    incoming = -1; // Reset incoming command
    portEXIT_CRITICAL(&mux);
    vTaskDelay(10); // Delay to allow other tasks to run
  }
}

void forward() {
  digitalWrite(Mot11, LOW);
  digitalWrite(Mot12, HIGH);
  digitalWrite(Mot21, LOW);
  digitalWrite(Mot22, HIGH);
  Serial.println("forward");
}

void backward() {
  digitalWrite(Mot11, HIGH);
  digitalWrite(Mot12, LOW);
  digitalWrite(Mot21, HIGH);
  digitalWrite(Mot22, LOW);
  Serial.println("backward");
}

void left() {
  digitalWrite(Mot11, HIGH);
  digitalWrite(Mot12, LOW);
  digitalWrite(Mot21, LOW);
  digitalWrite(Mot22, HIGH);
  Serial.println("moving left");
}

void right() {
  digitalWrite(Mot11, LOW);
  digitalWrite(Mot12, HIGH);
  digitalWrite(Mot21, HIGH);
  digitalWrite(Mot22, LOW);
  Serial.println("moving right");
}

void stop() {
  digitalWrite(Mot11, LOW);
  digitalWrite(Mot12, LOW);
  digitalWrite(Mot21, LOW);
  digitalWrite(Mot22, LOW);
  Serial.println("stop");
}
