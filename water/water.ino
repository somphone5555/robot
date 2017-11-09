int sensorPin = A0;
int sensorValue = 0;
int ledred = 11;
int ledwhite = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledred, OUTPUT);
  pinMode(ledwhite, OUTPUT);
  pinMode(sensorValue, OUTPUT);

}

void loop() {
  Serial.print("sensor=");
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if (sensorValue > 500)
    digitalWrite(ledred, HIGH);
  digitalWrite(ledwhite, LOW);
  digitalWrite(sensorValue, LOW);
  delay(500);
  if (sensorValue < 500)
    digitalWrite(ledred, HIGH);
  digitalWrite(ledwhite, LOW);
  digitalWrite(sensorValue, HIGH);
  delay(500);
  if (sensorValue > 350 && sensorValue < 500)
    digitalWrite(ledred, LOW);
  digitalWrite(ledwhite, HIGH);
  digitalWrite(sensorValue, LOW);
  delay(500);
}
