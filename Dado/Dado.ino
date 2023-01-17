//Pines de los leds
int const L1 = 2;
int const L2 = 3;
int const L3 = 4;
int const L4 = 5;
int const L5 = 6;
int const L6 = 7;

//configuracion el pin de inclinacion
int const dado = 10;

//valores del dado
int valor = 0;

void setup() {
  Serial.begin(9600);
  //pines de entrada/salida
  pinMode (L1, OUTPUT);
  pinMode (L2, OUTPUT);
  pinMode (L3, OUTPUT);
  pinMode (L4, OUTPUT);
  pinMode (L5, OUTPUT);
  pinMode (L6, OUTPUT);
  pinMode (dado, INPUT);
}

void loop() {

  //valor del dado
  randomSeed(0);
  if (digitalRead (dado) == HIGH)
  {
    digitalWrite (L1, LOW);
    digitalWrite (L2, LOW);
    digitalWrite (L3, LOW);
    digitalWrite (L4, LOW);
    digitalWrite (L5, LOW);
    digitalWrite (L6, LOW);
    delay (100);
    valor = random(1, 7);
  }
  Serial.println(valor);

  //enciende leds conforme el numero
  switch (valor)
  {
    case 1:
      digitalWrite (L1, HIGH);
      digitalWrite (L2, LOW);
      digitalWrite (L3, LOW);
      digitalWrite (L4, LOW);
      digitalWrite (L5, LOW);
      digitalWrite (L6, LOW);
      break;

    case 2:
      digitalWrite (L1, HIGH);
      digitalWrite (L2, HIGH);
      digitalWrite (L3, LOW);
      digitalWrite (L4, LOW);
      digitalWrite (L5, LOW);
      digitalWrite (L6, LOW);
      break;

    case 3:
      digitalWrite (L1, HIGH);
      digitalWrite (L2, HIGH);
      digitalWrite (L3, HIGH);
      digitalWrite (L4, LOW);
      digitalWrite (L5, LOW);
      digitalWrite (L6, LOW);
      break;

    case 4:
      digitalWrite (L1, HIGH);
      digitalWrite (L2, HIGH);
      digitalWrite (L3, HIGH);
      digitalWrite (L4, HIGH);
      digitalWrite (L5, LOW);
      digitalWrite (L6, LOW);
      break;

    case 5:
      digitalWrite (L1, HIGH);
      digitalWrite (L2, HIGH);
      digitalWrite (L3, HIGH);
      digitalWrite (L4, HIGH);
      digitalWrite (L5, HIGH);
      digitalWrite (L6, LOW);
      break;

    case 6:
      digitalWrite (L1, HIGH);
      digitalWrite (L2, HIGH);
      digitalWrite (L3, HIGH);
      digitalWrite (L4, HIGH);
      digitalWrite (L5, HIGH);
      digitalWrite (L6, HIGH);
      break;

  }
}
