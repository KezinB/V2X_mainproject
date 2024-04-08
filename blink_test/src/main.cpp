#include <Arduino.h>
#define Mot11 27
#define Mot12 26
#define Mot21 25
#define Mot22 33

#define EchoBottom 15
#define TrigBottom 2
#define EchoTop 35
#define TrigTop 32

void forward();
void backward();
void left();
void right();
void stop();
int checkDist1(int trigPin, int echoPin);
int checkDist2(int trigPin, int echoPin);

void setup() {
  Serial.begin(9600);
  pinMode(Mot11, OUTPUT);
  pinMode(Mot12, OUTPUT);
  pinMode(Mot21, OUTPUT);
  pinMode(Mot22, OUTPUT);
  pinMode(TrigTop, OUTPUT); 
  pinMode(EchoTop, INPUT); 
  pinMode(TrigBottom, OUTPUT); 
  pinMode(EchoBottom, INPUT);
}

void loop() {
  int distTop = checkDist1(TrigTop, EchoTop);
  delay(10);
  int distBott = checkDist2(TrigBottom, EchoBottom);
  Serial.print("Sensor top : ");
  Serial.println(distTop);
  Serial.print("Sensor bottom : ");
  Serial.println(distBott);
  if (distBott < 50 && distTop < 20)
  {
    forward();
  }
  else if (distBott < 50 && distTop < 40){
    stop();
  }
  else {
    stop();
  }
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

void backward(){
  digitalWrite(Mot11, HIGH);
  digitalWrite(Mot12, LOW);
  digitalWrite(Mot21, HIGH);
  digitalWrite(Mot22, LOW);
  Serial.println(" backward ");
}

void forward(){
  digitalWrite(Mot11, LOW);
  digitalWrite(Mot12, HIGH);
  digitalWrite(Mot21, LOW);
  digitalWrite(Mot22, HIGH);
  Serial.println(" forward ");
}

void left(){
  digitalWrite(Mot11, HIGH);
  digitalWrite(Mot12, LOW);
  digitalWrite(Mot21, LOW);
  digitalWrite(Mot22, HIGH);
  Serial.println(" left ");
}

void right(){
  digitalWrite(Mot11, LOW);
  digitalWrite(Mot12, HIGH);
  digitalWrite(Mot21, HIGH);
  digitalWrite(Mot22, LOW);
  Serial.println(" right ");
}

void stop(){
  digitalWrite(Mot11, LOW);
  digitalWrite(Mot12, LOW);
  digitalWrite(Mot21, LOW);
  digitalWrite(Mot22, LOW);
  Serial.println(" stop ");
}