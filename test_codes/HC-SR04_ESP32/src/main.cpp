#include <Arduino.h>
#define  triggerPin1  26  
#define  echoPin1 25
#define  triggerPin2  33  
#define  echoPin2 35
#define  triggerPin3  32  
#define  echoPin3 34

int frontDist, leftDist, rightDist;
int checkDist1(int trigPin,int echoPin);
int checkDist2(int trigPin,int echoPin);
int checkDist3(int trigPin,int echoPin);

void setup() {
  Serial.begin(115200);
  for (int pin = 0; pin < 40; pin++) {
    digitalWrite(pin, LOW);
  }
  pinMode(triggerPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(triggerPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(triggerPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
}

void loop() {
  frontDist = checkDist1(triggerPin1, echoPin1);
  rightDist = checkDist2(triggerPin2, echoPin2);
  leftDist = checkDist3(triggerPin3, echoPin3);
  Serial.println("Front distance : ");
  Serial.println(frontDist);
  Serial.println("Left distance : ");
  Serial.println(leftDist);
  Serial.println("Right distance : ");
  Serial.println(rightDist);
  delay(500);
}

int checkDist1(int trigPin,int echoPin)
{
  long duration, distance; 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  
  duration = pulseIn(echoPin, HIGH);       
  distance = (duration * 0.0343) / 2;
  return distance;
}
int checkDist2(int trigPin,int echoPin)
{
  long duration, distance; 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  
  duration = pulseIn(echoPin, HIGH);       
  distance = (duration * 0.0343) / 2;
  return distance;
}
int checkDist3(int trigPin,int echoPin)
{
  long duration, distance; 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  
  duration = pulseIn(echoPin, HIGH);       
  distance = (duration * 0.0343) / 2;
  return distance;
}
