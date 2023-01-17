//pad
const int a = 3;
const int b = 4;
const int c = 5;
const int d = 7;
const int e = 6;
const int f = 9;
const int g = 8;
//leds
const int B = 13;
const int G = 2;
const int Y = 11;
const int O = 12;
const int R = 10;
//potenciometro
int valor = 0;

void setup() {
  //pad
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);

  //led
  pinMode(B, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(O, OUTPUT);
  pinMode(R, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  valor = analogRead(4);
  Serial.println(valor);

  if (valor <= 100)
  {
    //leds
    digitalWrite(R, LOW);
    digitalWrite(O, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }


  if (valor > 100 && valor < 207)
  {
    //leds
    digitalWrite(R, HIGH);
    digitalWrite(O, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    //UNO
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (valor >= 207 && valor < 411)
  {
    //leds
    digitalWrite(R, HIGH);
    digitalWrite(O, HIGH);
    digitalWrite(Y, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    //DOS
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  if (valor >= 411 && valor < 615)
  {
    //leds
    digitalWrite(R, HIGH);
    digitalWrite(O, HIGH);
    digitalWrite(Y, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    //TRES
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);

  }
  if (valor >= 615  && valor < 818)
  {
    //leds
    digitalWrite(R, HIGH);
    digitalWrite(O, HIGH);
    digitalWrite(Y, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, LOW);
    //CUATRO
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (valor >= 818 && valor < 1023)
  {
    //leds
    digitalWrite(R, HIGH);
    digitalWrite(O, HIGH);
    digitalWrite(Y, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, HIGH);
    //CINCO5
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }

}
