#include <Arduino.h>
#define trigPin1 2
#define echoPin1 3
#define trigPin2 5
#define echoPin2 4
#define trigPin3 7
#define echoPin3 6

#define motlft1 A0
#define motlft2 A1
#define motryt1 A2
#define motryt2 A3


struct finddistance
{
  int dist1;
  int dist2;
  int dist3;
};

int checkDist(int trigPin, int echoPin);

void setup() {
  Serial.begin(9600); 
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT); 
  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT); 
  pinMode(trigPin3, OUTPUT); 
  pinMode(echoPin3, INPUT); 
  pinMode(motlft1,OUTPUT);
  pinMode(motlft2,OUTPUT);
  pinMode(motryt1,OUTPUT);
  pinMode(motryt2,OUTPUT);

}
void forward(){
  digitalWrite(motlft1, HIGH);
  digitalWrite(motlft2, LOW);
  digitalWrite(motryt1, HIGH);
  digitalWrite(motryt2, LOW);
  Serial.println("moving forward");
}
void backward(){
  digitalWrite(motlft1, LOW);
  digitalWrite(motlft2, HIGH);
  digitalWrite(motryt1, LOW);
  digitalWrite(motryt2, HIGH);
  Serial.println("moving backward");
}
void left(){
  digitalWrite(motlft1, HIGH);
  digitalWrite(motlft2, LOW);
  digitalWrite(motryt1, LOW);
  digitalWrite(motryt2, LOW);
  Serial.println("moving left");
}
void right(){
  digitalWrite(motlft1, LOW);
  digitalWrite(motlft2, LOW);
  digitalWrite(motryt1, HIGH);
  digitalWrite(motryt2, LOW);
  Serial.println("moving right");
}

void loop() {
  finddistance distance;
  distance.dist1 = checkDist(trigPin1, echoPin1);
  distance.dist2 = checkDist(trigPin2, echoPin2);
  distance.dist3 = checkDist(trigPin3, echoPin3);
  // Serial.print("Distance1: "); 
  // Serial.print(distance.dist1);
  // Serial.println(" cm");
  // Serial.print("Distance2: "); 
  // Serial.print(distance.dist2);
  // Serial.println(" cm");
  // Serial.print("Distance3: "); 
  // Serial.print(distance.dist3);
  // Serial.println(" cm");
  if(distance.dist1 < 20){
    backward();
  }
  else{
    forward();
  }
  delay(100);
}

int checkDist(int trigPin,int echoPin)
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
  