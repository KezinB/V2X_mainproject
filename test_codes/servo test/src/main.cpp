#include <Arduino.h>
#include <Servo.h> // include servo library to use its related functions
#define Servo_PWM 6 // A descriptive name for D6 pin of Arduino to provide PWM signal
Servo MG995_Servo;  // Define an instance of of Servo with the name of "MG995_Servo"
  

void setup() {
  Serial.begin(9600); // Initialize UART with 9600 Baud rate
  MG995_Servo.attach(Servo_PWM);  // Connect D6 of Arduino with PWM signal pin of servo motor

}

void loop() {
  Serial.println("0");// You can display on the serial the signal value
  MG995_Servo.write(60); //Turn clockwise at high speed
  delay(300);
  MG995_Servo.detach();//Stop. You can use deatch function or use write(x), as x is the middle of 0-180 which is 90, but some lack of precision may change this value
  delay(2000);
  MG995_Servo.attach(Servo_PWM);//Always use attach function after detach to re-connect your servo with the board
  Serial.println("0");//Turn left high speed
  MG995_Servo.write(120);
  delay(300);
  MG995_Servo.detach();//Stop
  delay(2000);
  MG995_Servo.attach(Servo_PWM);
  MG995_Servo.

      
}