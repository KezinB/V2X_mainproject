#include <NewPing.h>
#include<Wire.h>

#define slaveAddress 9

#define TRIGGER_PIN_0  2
#define ECHO_PIN_0     2

// Sensor 1
#define TRIGGER_PIN_1  3
#define ECHO_PIN_1     3

// Sensor 2
#define TRIGGER_PIN_2  4
#define ECHO_PIN_2     4

// Sensor 3
#define TRIGGER_PIN_3  5
#define ECHO_PIN_3     5

// Maximum Distance is 400 cm
#define MAX_DISTANCE 400

// Create objects for ultrasonic sensors
NewPing sensor0(TRIGGER_PIN_0, ECHO_PIN_0, MAX_DISTANCE);
NewPing sensor1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sensor2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing sensor3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);

// Variables to represent distances
float distance0, distance1, distance2, distance3;

void requestEvent(){
  
}

void setup() {
  Wire.begin(slaveAddress);
  Wire.onRequest(requestEvent);
  // Serial monitor for testing
  Serial.begin(9600);
   
}

void loop() {
   
  // Read sensors in CM 
  // Sensor 0
  distance0 = sensor0.ping_cm();
  delay(20);
  
  // Sensor 1
  distance1 = sensor1.ping_cm();
  delay(20);
  
  // Sensor 2
  distance2 = sensor2.ping_cm();
  delay(20);
  
  // Sensor 3
  distance3 = sensor3.ping_cm();
  delay(20);
  
   
  // Send results to Serial Monitor
  // Sensor 0
  Serial.print("Distance 0 = ");
  if (distance0 >= 400 || distance0 <= 2) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance0);
    Serial.println(" cm");
    delay(50);
  }
  // Sensor 1
  Serial.print("Distance 1 = ");
  if (distance1 >= 400 || distance1 <= 2) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance1);
    Serial.println(" cm");
    delay(50);
  }
  // Sensor 2
  Serial.print("Distance 2 = ");
  if (distance2 >= 400 || distance2 <= 2) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance2);
    Serial.println(" cm");
    delay(50);
  }
  // Sensor 3
  Serial.print("Distance 3 = ");
  if (distance3 >= 400 || distance3 <= 2) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance3);
    Serial.println(" cm");
    delay(50);
  }
  
  
  //delay(250);
}