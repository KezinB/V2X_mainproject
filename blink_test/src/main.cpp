#include <Arduino.h>

struct finddistance {
  int dist1;
  int dist2;
  int dist3;
};

// Define separate serial ports for communication
HardwareSerial mySerial(2); // Serial port 2 (TX pin: GPIO17, RX pin: GPIO16)

void setup() {
  Serial.begin(9600); // Begin hardware serial for debugging
  mySerial.begin(9600); // Begin separate hardware serial for communication
}

void loop() {
  if (mySerial.available() >= sizeof(finddistance)) {
    finddistance distance;
    mySerial.readBytes((char *)&distance, sizeof(finddistance));

    // Process received data
    Serial.print("Distance 1: ");
    Serial.print(distance.dist1);
    Serial.println(" cm");
    Serial.print("Distance 2: ");
    Serial.print(distance.dist2);
    Serial.println(" cm");
    Serial.print("Distance 3: ");
    Serial.print(distance.dist3);
    Serial.println(" cm");
  }
}
