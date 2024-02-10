#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
  const uint64_t pipeOut = 000322;         // NOTE: The same as in the receiver 000322 | Alıcı kodundaki adres ile aynı olmalı
  RF24 radio(4, 5);                       // select CE,CSN pin | CE ve CSN pinlerin seçimi

  struct Signal {
  byte throttle;
  byte pitch;
  byte roll;
  byte yaw;
  byte aux1;
  byte aux2;
  byte aux3;
  byte aux4;
  
};
  Signal data;

  void setup()
{
                                       //Configure the NRF24 module  | NRF24 modül konfigürasyonu
  radio.begin();
  radio.openWritingPipe(pipeOut);
  radio.setChannel(100);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);    // The lowest data rate value for more stable communication  | Daha kararlı iletişim için en düşük veri hızı.
  radio.setPALevel(RF24_PA_MAX);      // Output power is set for maximum |  Çıkış gücü maksimum için ayarlanıyor.
  radio.stopListening();              // Start the radio comunication for Transmitter | Verici için sinyal iletişimini başlatır.
  Serial.begin(115200);
 
}

  void loop()
{
   
  //radio.write(&data, sizeof(Signal));  
  data.throttle = 100;
  data.pitch = 127;
  data.roll = 127;
  data.yaw = 127;
  data.aux1 = 2;                       // Signal lost position | Sinyal kesildiğindeki pozisyon
  data.aux2 = 3;
  data.aux3 = 4;
  data.aux4 = 5;
  
for(int i=0; i<10; i++) {
    data.aux1 = i;
    data.aux2 = i + 10;
    data.aux3 = i + 8;
    data.aux4 = i + 40;
    
    Serial.println(data.roll);
    Serial.println(data.pitch);
    Serial.println(data.throttle);
    Serial.println(data.yaw);
    Serial.println(data.aux1);
    Serial.println(data.aux2);
    Serial.println(data.aux3);
    Serial.println(data.aux4);

    radio.write(&data, sizeof(Signal));
    delay(500);
  }

  //delay(2000);
  
}