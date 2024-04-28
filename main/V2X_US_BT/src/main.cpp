#include <Arduino.h>
#include <BluetoothSerial.h> 
#include <Wire.h> 

//HC-SR04 pins
#define  triggerPin1  26  
#define  echoPin1 25
#define  triggerPin2  33  
#define  echoPin2 35
#define  triggerPin3  32  
#define  echoPin3 34

#define Mot11 13
#define Mot12 12
#define Mot21 14
#define Mot22 27
// init Class:
BluetoothSerial ESP_BT; 

// Parameters for Bluetooth interface and timing
int incoming;                           // variable to store byte received from phone 
int frontDist, leftDist, rightDist;
int ADXL345 = 0x53;
float X_out, Y_out, Z_out;

int checkDist1(int trigPin,int echoPin);
int checkDist2(int trigPin,int echoPin);
int checkDist3(int trigPin,int echoPin);

void reset_rx_BT();
void forward();
void backward();
void left();
void right();
void stop();

void setup() {
  Serial.begin(115200);
  ESP_BT.begin(" Tezza ");

  Wire.begin(); // Initiate the Wire library
  // Set ADXL345 in measuring mode
  Wire.beginTransmission(ADXL345); // Start communicating with the device 
  Wire.write(0x2D); // Access/ talk to POWER_CTL Register - 0x2D
  // Enable measurement
  Wire.write(8); // (8dec -> 0000 1000 binary) Bit D3 High for measuring enable 
  Wire.endTransmission();
  delay(10);

  pinMode(Mot11, OUTPUT);
  pinMode(Mot12, OUTPUT);
  pinMode(Mot21, OUTPUT);
  pinMode(Mot22, OUTPUT);
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

  Wire.beginTransmission(ADXL345);
  Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  X_out = ( Wire.read()| Wire.read() << 8); // X-axis value
  X_out = X_out/256; //For a range of +-2g, we need to divide the raw values by 256, according to the datasheet
  Y_out = ( Wire.read()| Wire.read() << 8); // Y-axis value
  Y_out = Y_out/256;
  Z_out = ( Wire.read()| Wire.read() << 8); // Z-axis value
  Z_out = Z_out/256;

  Serial.print("Xa= ");
  Serial.print(X_out);
  Serial.print("   Ya= ");
  Serial.print(Y_out);
  Serial.print("   Za= ");
  Serial.println(Z_out);

  incoming = 0;
  // -------------------- Receive Bluetooth signal ----------------------
  if (ESP_BT.available()) 
  {
    incoming = 0;
    incoming = ESP_BT.read();           // Read what we receive and store in "incoming"
    Serial.println(incoming);
    if (incoming == 128)
    {
      forward(); 
    }
    else if (incoming == 129)
    {
      backward();
    }
    else if (incoming == 130)
    {
      right();
      delay(250);
      stop();
    }
    else if (incoming == 131) 
    {
      left();
      delay(250);
      stop();
    }
    else{
      incoming = 0;
      stop();
    }
  }
  if(frontDist < 15){
    ESP_BT.write(10);
    Serial.println("obstacle alert!");   
  }
  else if(leftDist < 10){
    ESP_BT.write(20);
    Serial.println("obstacle alert!"); 
  }
  else if(rightDist < 10){
    ESP_BT.write(30);
    Serial.println("obstacle alert!"); 
  }
  else{
    ESP_BT.write(0);
    Serial.println("path clear !");
  }
}

void reset_rx_BT() {                    // function to erase all bytes (set to -1)
  incoming = 0;
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
