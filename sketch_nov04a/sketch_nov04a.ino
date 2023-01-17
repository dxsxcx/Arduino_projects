/*controlador de ventilador
Este programa simula la funcion de un ventilador con control digital
*/

int Cont = 0;
int Boton = 0;

void setup() {
  //Modos del pin leds
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  //Aqui esta el Boton
  pinMode (7, INPUT);
}

void loop() {

  Boton = digitalRead(7);

  if (Boton == 1 )
  {
    Cont = Cont + 1;
    delay (1);
    Boton = 0;

    if (Cont == 5)
    {
      Cont = 1;
    }
  }

  if (Cont == 1)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }

  if (Cont == 2)
  {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }

  if (Cont == 3)
  {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }

  if (Cont == 4)
  {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }

  delay (500);
}

