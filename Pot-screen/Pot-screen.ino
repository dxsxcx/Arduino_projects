const int pinRojo = A0;
const int pinVerde = A1;
const int pinAzul = A2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(analogRead(pinRojo));
  Serial.print(", ");
  Serial.print(analogRead(pinVerde));
  Serial.print(", ");
  Serial.println(analogRead(pinAzul));
  delay (100);
}
