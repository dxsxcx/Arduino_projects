int pot = 0;

void setup() {
Serial.begin(9600);
}

void loop() {
  pot = analogRead(A0); 
  Serial.println(pot);
  delay (500);
}
