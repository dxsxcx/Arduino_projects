void setup() {
  //Denominamos que el pin 1 es una salida
  pinMode (1, OUTPUT);
  pinMode (2, OUTPUT);
}

void loop() {
  // En este apartado recreamos la señal cuadrada
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  delayMicroseconds(8267);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  delayMicroseconds(8267);
}
