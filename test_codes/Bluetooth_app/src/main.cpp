#include <Arduino.h>
#include "BluetoothSerial.h" 

#define Mot11 13
#define Mot12 12
#define Mot21 14
#define Mot22 27
// init Class:
BluetoothSerial ESP_BT; 

// Parameters for Bluetooth interface and timing
int incoming;                           // variable to store byte received from phone 
int id = -1;                            // received identification byte
int val_byte1 = -1;                     // most significant byte of data value
int val_byte2 = -1;                     // least significant byte of data value

void reset_rx_BT();
void forward();
void backward();
void left();
void right();
void stop();

void setup() {
  Serial.begin(115200);
  ESP_BT.begin(" Tezza ");
  pinMode(Mot11, OUTPUT);
  pinMode(Mot12, OUTPUT);
  pinMode(Mot21, OUTPUT);
  pinMode(Mot22, OUTPUT);
}

void loop() {
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
    
    /*switch (incoming)
    {
    case 128:
      forward(); 
      break;
    case 129:
      backward();
      break;
    case 130:
      left();
      break;
    case 131:
      right();
      break;
    default:
      stop();
      break;
    } 
    }*/
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