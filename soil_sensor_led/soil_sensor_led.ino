int led1 = 4;

void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
}

String str = "";
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);

  if (sensorValue >= 100 && sensorValue <= 900) {
    //Serial.println(sensorValue);
    digitalWrite(led1, HIGH);
    str = "Soil moisture ";
    Serial.println(str + "="+sensorValue );
  }
  else {
    //Serial.println(sensorValue);
    digitalWrite(led1, LOW);
    str = "Soil moisture";
    Serial.println(str + "="+sensorValue);
  }
  delay(1000);
}

