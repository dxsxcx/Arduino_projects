
int contador = 0;

void setup() {
  pinMode(3, OUTPUT); //a
  pinMode(4, OUTPUT); //b
  pinMode(5, OUTPUT); //c
  pinMode(7, OUTPUT); //d
  pinMode(6, OUTPUT); //e
  pinMode(9, OUTPUT); //f
  pinMode(8, OUTPUT); //g
  pinMode(12, INPUT_PULLUP);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
}

void loop() {

  if (digitalRead(12) == LOW)
  {
    contador = contador + 1;
    delay (500);
  }

  switch (contador)
  {
    case 1:
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      break;

    case 2:
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
      break;

    case 3:
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
      break;

    case 4:
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      break;

    case 5:
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      break;

    case 6:
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      break;

    case 7:
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      break;

    case 8:
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      break;

    case 9:
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      break;
      
    case 10:
      contador = 0;
      break;
      
    case 0:
      //SECUENCIA
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      delay (50);

      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      delay (50);

      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      delay (50);

      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      delay (100);

      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      delay (50);

      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
      delay (50);

      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
      delay (50);

      break;
  }


}
