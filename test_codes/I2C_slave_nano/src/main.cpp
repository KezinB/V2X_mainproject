#include <Arduino.h>
#include <Wire.h>

#define SLAVE_ADDRESS 9  // Change this to the desired slave address

void receiveEvent(int a) {
  // This function is called when the master sends data to the slave
  while (Wire.available()) {
    char receivedData = Wire.read();
    // Handle received data as needed
    Serial.print("Received data: ");
    Serial.println(receivedData);
  }
  }
  int i;
  void setup()
  {
    Wire.begin(SLAVE_ADDRESS);       // Initialize I2C as slave with the specified address
    Wire.onReceive(receiveEvent); // Register the event function for I2C data reception
    Wire.onRequest(requestEvent);    // Register the event function for I2C data request
    Serial.begin(9600);              // Start serial communication for debugging
}

void loop() {
  // Your main code goes here
}

void requestEvent() {
  // This function is called when the master requests data from the slave
  // You can send data back to the master in this function
  // For example, sending a constant value:
  Wire.write("Hello from Slave!");
}
