#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TinyGPS++.h>

#define GPS_BAUDRATE 9600  // The default baudrate of NEO-6M is 9600
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
TinyGPSPlus gps;
int ADXL345 = 0x53; // The ADXL345 sensor I2C address
float X_out, Y_out, Z_out;

struct GPSData {//GPS DATA AS STRUCT
  float latitude;
  float longitude;
  float altitude;
  float speed;
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
  bool isValid;
};

GPSData readGPSData();

void setup() {
  Serial.begin(9600);
  Serial2.begin(GPS_BAUDRATE);
  Serial.println(F("ESP32 - GPS module"));
  Wire.begin(); 
  Wire.beginTransmission(ADXL345); 
  Wire.write(0x2D); 
  Wire.write(8); 
  Wire.endTransmission();
  delay(10);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
}

void loop() {
  
  GPSData gpsData = readGPSData();

  Wire.beginTransmission(ADXL345);
  Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  X_out = ( Wire.read()| Wire.read() << 8); // X-axis value
  X_out = X_out/256; 
  Y_out = ( Wire.read()| Wire.read() << 8); // Y-axis value
  Y_out = Y_out/256;
  Z_out = ( Wire.read()| Wire.read() << 8); // Z-axis value
  Z_out = Z_out/256;

  // Display accelerometer values
  Serial.print("Xa= ");
  Serial.print(X_out);
  Serial.print("   Ya= ");
  Serial.print(Y_out);
  Serial.print("   Za= ");
  Serial.println(Z_out);
  
  if (gpsData.isValid) {
    // Access the GPS data variables as needed
    Serial.print(F("Latitude: "));
    Serial.println(gpsData.latitude);
   
    Serial.print(F("Longitude: "));
    Serial.println(gpsData.longitude);
    
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0,0);
  display.println("ADXL345 test project!");
  
  display.setCursor(0,10);
  display.print(F("X: ")); 
  display.print(X_out);
  display.setCursor(0,20);
  display.print(F("Y: ")); 
  display.print(Y_out);
  display.setCursor(0,30);
  display.print(F("Z: ")); 
  display.print(Z_out); 
  display.setCursor(0,40);
  display.print(F("Latitude: ")); 
  display.print(gpsData.latitude);
  display.setCursor(0,50);
  display.print(F("Longitude: ")); 
  display.print(gpsData.longitude);
  display.display();
  delay(500);
}

GPSData readGPSData() {
  GPSData data;
  data.isValid = false;

  if (Serial2.available() > 0) {
    if (gps.encode(Serial2.read())) {
      if (gps.location.isValid()) {
        data.latitude = gps.location.lat();
        data.longitude = gps.location.lng();

        //delay(200);
        if (gps.altitude.isValid())
          data.altitude = gps.altitude.meters();
        else
          data.altitude = -1; // Indicate invalid altitude
      } else {
        data.isValid = false;
      }

      if (gps.speed.isValid()) {
        data.speed = gps.speed.kmph();
      } else {
        data.speed = -1; // Indicate invalid speed
      }

      if (gps.date.isValid() && gps.time.isValid()) {
        data.year = gps.date.year();
        data.month = gps.date.month();
        data.day = gps.date.day();
        data.hour = gps.time.hour();
        data.minute = gps.time.minute();
        data.second = gps.time.second();
      } else {
        data.isValid = false;
      }

      data.isValid = true;
    }
  }

  if (millis() > 5000 && gps.charsProcessed() < 10)
    Serial.println(F("No GPS data received: check wiring"));

  return data;
}
