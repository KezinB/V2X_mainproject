#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h" 

DFRobotDFPlayerMini myDFPlayer;

void printDetail(uint8_t type, int value);
unsigned int f;
SoftwareSerial mySoftwareSerial(9,10);

void setup()
{
  
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);
  Serial.println();
  Serial.println(F("Initializing DFPlayer..."));

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.volume(30);

}

void loop()
{
  f = analogRead(1);
  Serial.println(f);
  if (f > 320)                      
  {
    Serial.println("Please Give Me Water");
    myDFPlayer.play(1);
    delay(1000);
  }
  else if ((f < 320) && (f > 280))  
  {
    Serial.println("Please Give Me Food");
    myDFPlayer.play(2);
    delay(1000);
  }
  else if ((f < 200) && (f > 100))  
  {
    Serial.println("Give Me Water");
    myDFPlayer.play(3);
    delay(1000);
  }
  else                            
  {
    if (f > 100)
      ;
  }
  delay(50);
}