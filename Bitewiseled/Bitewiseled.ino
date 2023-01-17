int Led1 = 2;
int Led2 = 3;
int Led3 = 4;
int Led4 = 5;
int Led5 = 6;
int Led6 = 7;
int Valor;


void setup() {
  Serial.begin(9600);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
  pinMode(Led6, OUTPUT);
}

void loop() {
  for (int i = 1; i < 8; i++) {
    Valor = 128 >> i;
    digitalWrite(Led1, bitRead(Valor, 0));
    digitalWrite(Led2, bitRead(Valor, 1));
    digitalWrite(Led3, bitRead(Valor, 2));
    digitalWrite(Led4, bitRead(Valor, 3));
    digitalWrite(Led5, bitRead(Valor, 4));
    digitalWrite(Led6, bitRead(Valor, 5));
    delay(100);a
  }

  for (int i = 1; i < 8 ; i++) {
    Valor = 1 << i;
    digitalWrite(Led1, bitRead(Valor, 0));
    digitalWrite(Led2, bitRead(Valor, 1));
    digitalWrite(Led3, bitRead(Valor, 2));
    digitalWrite(Led4, bitRead(Valor, 3));
    digitalWrite(Led5, bitRead(Valor, 4));
    digitalWrite(Led6, bitRead(Valor, 5));
    delay(100);
  }
}
