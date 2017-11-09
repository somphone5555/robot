
#define Lamp_pin 11
#define Lamp_on LOW
#define Lamp_off HIGH

String str = "";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Lamp_pin,OUTPUT);
  digitalWrite(Lamp_pin,Lamp_off);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Lamp_pin,Lamp_on);
  str = "Logic control lamp is" + digitalRead(Lamp_pin);
  Serial.println(str);
  delay(10000);
  digitalWrite(Lamp_pin,Lamp_off);
  str = "Logiccccc control lamp is" + digitalRead(Lamp_pin);
  Serial.println(str);
  delay(10000);
}
