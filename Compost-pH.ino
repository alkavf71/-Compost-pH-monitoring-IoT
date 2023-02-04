#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define analogInPin V0
#define BLYNK_PRINT Serial

LiquidCrystal_I2C lcd(0x27,20,4); 

int sensorValue = 0; 
float outputValue = 0.0;
WidgetLCD wlcd(V0);

char auth[] = "";

char ssid[] = "";
char pass[] = "";

BlynkTimer timer;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  lcd.init();
  lcd.begin(20,4);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("     Welcome to        ");
  lcd.setCursor(0, 1);
  lcd.print("     Bromo Team         ");
  delay(2000);
  lcd.clear();
  
}

void loop()
{
  lcd.print("Bromo Team");
  sensorValue = analogRead(analogInPin);
  outputValue = (-0.0693*sensorValue)+7.3855;
  lcd.setCursor(0,1);
  lcd.print("pH Value :");
  lcd.print(outputValue);
  delay(1000);
  lcd.clear();

  wlcd.print(0,0,"Bromo Team");
  sensorValue = analogRead(analogInPin);
  outputValue = (-0.0693*sensorValue)+7.3855;
  wlcd.print(0,1,"pH Value :");
  wlcd.print(9,1,outputValue);
  delay(1000);
  wlcd.clear();
  Blynk.run();

}
