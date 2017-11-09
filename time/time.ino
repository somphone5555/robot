
//#define SCK_PIN 4
//#define IO_PIN 3
//#define RST_PIN 2

#include <DS1302.h>
#include <RTClib.h>
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//#define I2C_ADDR 0x3F  //or  0x27
//#define BACKLIGHT_PIN 3
//LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,6,7);

LiquidCrystal_I2C lcd(0x3F, 16, 2);

//DS1302 rtc(RST_PIN, IO_PIN SCK_PIN);
DS1302 rtc(2, 3, 4);

Time t; //
void setup(){

//lcd.begin(16,2);  // initializa o lcd
  lcd.begin();
//lcd.backlight();  // acende a luz de fundo no lcd
//lcd.setBackligth(BACKLIGHT_PIN,POSITIVE);
//lcd.setBackligth(HIGH);

Serial.begin(9600);
//Serial.println();

pinMode(7, OUTPUT);

rtc.halt(false);
rtc.writeProtect(false);

}

void loop(){

//Get data from the DS1302
t=rtc.getTime();  //


//rtc.setDOW(1); //Define o dia da semana
//rtc.setTime(00, 00, 00); //Define o horario
//rtc.setDate(1, 5, 2017); //Define o dia, mes e ano

Serial.print("\n");
if(t.hour < 10){Serial.print(0);}
Serial.print(t.hour, DEC);
Serial.print(":");
if(t.min < 10){Serial.print(0);}
Serial.print(t.min, DEC);
Serial.print(":");
if(t.sec < 10){Serial.print(0);}
Serial.print(t.sec, DEC);

lcd.setCursor(0,0);
lcd.print("Time");
lcd.setCursor(5,0);
lcd.print(rtc.getTimeStr());

lcd.setCursor(0, 1);
lcd.print("Day");
lcd.setCursor(5,1);
lcd.print(rtc.getDateStr(FORMAT_SHORT));

if ((t.hour == 23)&&(t.min == 56)&&(t.sec == 00))
{
digitalWrite(7,HIGH);
}
if ((t.hour == 23)&&(t.min == 57)&&(t.sec == 00))
{
digitalWrite(7, LOW);
}
if ((t.hour == 23)&&(t.min == 58)&&(t.sec == 00))
{
digitalWrite(7,HIGH);
}
else if ((t.hour == 23)&&(t.min == 59)&&(t.sec == 00))
{
digitalWrite(7, LOW);
}
delay (1000);
}﻿
