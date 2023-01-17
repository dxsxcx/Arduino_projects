//LEDS
int RED = 3;
int ORANGE = 5;
int YELLOW = 6;
int GREEN = 9;

//boton & potentiometer
int aPin = 1;
int val = 0;
int boton = 11;
int CON = 0;


void setup()
{

  pinMode(RED, OUTPUT);
  pinMode(ORANGE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  pinMode(boton, INPUT_PULLUP);

  
}

void loop()

{
  if (digitalRead(boton) == LOW)
  {
    CON = CON + 1;
    
  }

  switch (CON)
  {
    case 0:
      val = analogRead(aPin);
      analogWrite(RED, val / 4);
      analogWrite(ORANGE, 0);
      analogWrite(YELLOW, 0);
      analogWrite(GREEN, 0);
      break;

    case 1:
      val = analogRead(aPin);
      analogWrite(ORANGE, val / 4);
      analogWrite(RED, 0);
      analogWrite(YELLOW, 0);
      analogWrite(GREEN, 0);
      break;

    case 2:
      val = analogRead(aPin);
      analogWrite(YELLOW, val / 4);
      analogWrite(ORANGE, 0);
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      break;

    case 3:
      val = analogRead(aPin);
      analogWrite(GREEN, val / 4);
      analogWrite(ORANGE, 0);
      analogWrite(YELLOW, 0);
      analogWrite(RED, 0);
      break;

    case 5:
      CON = 0;
      break;
  }

}



