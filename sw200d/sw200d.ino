
void setup() {
  //primero declaramos nuestros pines
  pinMode(6, INPUT);//conexion del sw200d
  pinMode(7, OUTPUT);// conexion del led
}

void loop() {
  if (digitalRead(6)) {
    digitalWrite(7, HIGH);
  }
  else {
    digitalWrite(7, LOW);
  }
}
