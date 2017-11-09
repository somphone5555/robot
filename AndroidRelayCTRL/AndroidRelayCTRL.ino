#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

const int ry1=A3;
const int ry2=A2;
const int ry3=A1;
const int ry4=A0;
void setup() 
{
  pinMode(ry1,OUTPUT);
  pinMode(ry2,OUTPUT);
  pinMode(ry3,OUTPUT);
  pinMode(ry4,OUTPUT);
  digitalWrite(ry1,HIGH);
  digitalWrite(ry2,HIGH);
  digitalWrite(ry3,HIGH);
  digitalWrite(ry4,HIGH);
  mySerial.begin(9600);
}
char x;
void loop() 
{
  if (mySerial.available())
  {
    x=mySerial.read();
  }
  switch(x)
  {
    case 'A':
          digitalWrite(ry1,LOW);
          break;
    case 'a':
          digitalWrite(ry1,HIGH);
          break;
    case 'B':
          digitalWrite(ry2,LOW);
          break;
    case 'b':
          digitalWrite(ry2,HIGH);
          break;
    case 'C':
          digitalWrite(ry3,LOW);
          break;
    case 'c':
          digitalWrite(ry3,HIGH);
          break;
    case 'D':
          digitalWrite(ry4,LOW);
          break;
    case 'd':
          digitalWrite(ry4,HIGH);
          break;
  }
}
