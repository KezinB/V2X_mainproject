#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

static const uint8_t image_data_Saraarray[1024] = {
    0x3c, 0x00, 0x00, 0x18, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xa8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x2c, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x08, 0x00, 0x00, 0x00, 0x1a, 0x40, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x09, 0x81, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x30, 0x40, 0x08, 0x00, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xd9, 0x80, 0x14, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x10, 0x00, 0xd3, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x50, 0x00, 0x00, 0x06, 0x64, 0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x05, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xe0, 0x00, 0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xe0, 0x60, 0x00, 0x00, 0x0c, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xc0, 0x80, 0x00, 0x82, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x9d, 0x00, 0x04, 0x00, 0x03, 0x80, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xbe, 0xe8, 0x01, 0x80, 0x9c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xf0, 0x06, 0x67, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xfc, 0x0f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
    0xfd, 0xff, 0xff, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xf0, 0x00, 0x00, 0x01, 0x00, 
    0xf3, 0x9b, 0xfa, 0x0f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x03, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
    0xc7, 0xe6, 0x3c, 0x07, 0xff, 0x80, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
    0xd7, 0xe3, 0xff, 0x5d, 0xff, 0x80, 0x00, 0x00, 0x00, 0x07, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 
    0xef, 0x81, 0xfe, 0x9e, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 
    0xe7, 0xc1, 0xfc, 0x03, 0xff, 0x80, 0x00, 0x00, 0x02, 0x00, 0x30, 0xfe, 0x00, 0x00, 0x00, 0x00, 
    0xf7, 0xc3, 0xec, 0x31, 0x87, 0x80, 0x00, 0x00, 0x00, 0x01, 0x30, 0x06, 0x00, 0x00, 0x00, 0x00, 
    0xfb, 0xe1, 0xfa, 0x6e, 0xff, 0x80, 0x00, 0x00, 0x00, 0x03, 0x38, 0xcf, 0x00, 0x00, 0x00, 0x00, 
    0x07, 0x39, 0xfc, 0x42, 0xdf, 0xc0, 0x00, 0x00, 0x00, 0x09, 0xfe, 0xfe, 0x20, 0x00, 0x00, 0x00, 
    0xf7, 0xc9, 0xf8, 0x43, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xfe, 0x30, 0x00, 0x00, 0x00, 
    0xf8, 0x05, 0xf8, 0x21, 0xff, 0x80, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xfe, 0x20, 0x00, 0x00, 0x00, 
    0xfc, 0x39, 0xfe, 0x13, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x0f, 0x7f, 0xfe, 0x60, 0x00, 0x00, 0x00, 
    0xfe, 0x3b, 0xfc, 0x7f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x06, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 
    0xfe, 0x59, 0xfc, 0x76, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x00, 
    0xfc, 0x28, 0xc0, 0xfd, 0x5f, 0xc0, 0x00, 0x00, 0x00, 0x04, 0x0e, 0x78, 0x00, 0x00, 0x01, 0x00, 
    0xfc, 0x28, 0xce, 0x6f, 0xdf, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x20, 0x78, 0x00, 0x00, 0x01, 0x02, 
    0xfe, 0xf0, 0x3f, 0x3b, 0xbf, 0x80, 0x00, 0x00, 0x00, 0x01, 0x3f, 0xf0, 0x00, 0x00, 0x00, 0x00, 
    0xf9, 0xd0, 0x2c, 0xf7, 0xbf, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 
    0xdb, 0x44, 0x39, 0xc7, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xfb, 0x07, 0x70, 0x07, 0x3f, 0x9c, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xc9, 0x19, 0xb3, 0x1f, 0xe2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xd0, 0x08, 0x18, 0x3d, 0x7f, 0xe2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xef, 0xc6, 0x44, 0x39, 0xff, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x1f, 0xe0, 0xc7, 0xbf, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 
    0x7f, 0xc4, 0x13, 0x9f, 0xbf, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe3, 0xb0, 0x00, 0x00, 0x00, 
    0xff, 0x80, 0x50, 0x0c, 0x3d, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x07, 0xdf, 0xb0, 0x00, 0x00, 0x00, 
    0xff, 0x00, 0x02, 0xbc, 0x81, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xa0, 0x00, 0x00, 0x00, 
    0xfc, 0x7c, 0x43, 0xff, 0xa0, 0xde, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 
    0x01, 0xfc, 0xc7, 0xed, 0xfd, 0xde, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xc0, 0x09, 0x81, 0xde, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0x00, 0x1f, 0xff, 0xfb, 0xce, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xe2, 0xff, 0xff, 0xff, 0xee, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xfb, 0x07, 0xff, 0xff, 0xe6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xfe, 0xe0, 0x06, 0x0b, 0x1b, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xfb, 0xc8, 0xf0, 0x26, 0x07, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xf8, 0x00, 0x07, 0x3b, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xfc, 0xe0, 0x18, 0x13, 0x3f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xf1, 0xc0, 0x03, 0x07, 0x3d, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xf0, 0x40, 0x01, 0x9b, 0x1d, 0xff, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xb0, 0x02, 0x77, 0xff, 0xef, 0x00, 0x00, 0x00, 0x03, 0xe1, 0xfe, 0x00, 0x00, 0x00, 0x00, 
    0xb9, 0xc0, 0x00, 0x47, 0xef, 0xbf, 0x00, 0x00, 0x00, 0x19, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x04, 0x04, 0x7f, 0xef, 0xef, 0x00, 0x00, 0x00, 0x31, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 
    0x08, 0x09, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0xe3, 0xf7, 0xff, 0xfc, 0x00, 0x00, 0x00
};

void setup() {
  Serial.begin(115200);
 
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000); // Pause for 2 seconds
 
  // Clear the buffer.
  display.clearDisplay();
  
  // Draw bitmap on the screen
  display.drawBitmap(0, 0, image_data_Saraarray, 128, 64, 1);
  display.display();
}
 
void loop() {
  
}