#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); 
void setup()
{
  lcd.begin(20, 4);
  lcd.init();
  lcd.backlight();                
  lcd.setCursor(0,0);
  lcd.print("testing....");

  lcd.setCursor(0,1);
  lcd.print("testing....");
  
  lcd.setCursor(0,2);
  lcd.print("array3");
  
  lcd.setCursor(0,3);
  lcd.print("line 4");
}
void loop()
{}