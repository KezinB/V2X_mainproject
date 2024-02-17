#include <Arduino.h>
#include "BluetoothSerial.h" 

#define Mot11 5
#define Mot12 18
#define Mot21 19
#define Mot22 21
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
  Serial.begin(19200);
  ESP_BT.begin("ESP32_Control");
  pinMode(5, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
}

void loop() {
 
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
      left();
      delay(500);
      stop();
    }
    else if (incoming == 131)
    {
      right();
      delay(500);
      stop();
    }
    else{
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


void backward(){
  digitalWrite(Mot11, HIGH);
  digitalWrite(Mot12, LOW);
  digitalWrite(Mot21, HIGH);
  digitalWrite(Mot22, LOW);
  incoming = 0;
}
void forward(){
  digitalWrite(Mot11, LOW);
  digitalWrite(Mot12, HIGH);
  digitalWrite(Mot21, LOW);
  digitalWrite(Mot22, HIGH);
  incoming = 0;
}
void left(){
  digitalWrite(Mot11, HIGH);
  digitalWrite(Mot12, LOW);
  digitalWrite(Mot21, LOW);
  digitalWrite(Mot22, HIGH);
  incoming = 0;
}
void right(){
  digitalWrite(Mot11, LOW);
  digitalWrite(Mot12, HIGH);
  digitalWrite(Mot21, HIGH);
  digitalWrite(Mot22, LOW);
  incoming = 0;
}
void stop(){
  digitalWrite(Mot11, LOW);
  digitalWrite(Mot12, LOW);
  digitalWrite(Mot21, LOW);
  digitalWrite(Mot22, LOW);
}