int R = 6;
int G = 5;
int B = 3;
int rojo = 0;
int verde = 0;
int azul = 0;

void setup() {
}

void loop() {

  rojo=random(0,255);
  verde=random(0,255);
  azul=random(0,255);
  analogWrite(R, rojo);
  analogWrite(G, verde);
  analogWrite(B, azul);
  delay (1000);
}
