void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() {
  byte brillo;

  if (Serial.available())
  {
  brillo = Serial.read();
  analogWrite(3, brillo);
  }

  
}
