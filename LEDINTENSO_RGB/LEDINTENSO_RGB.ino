//leds
int rojo = 8;
int azul = 9;
int verd = 10;

//ledvariable
int R = 6;
int B = 3;
int G = 5;

//push
int push = 2;

//potentiometer
int pot = 0;

//Valores
int val = 0;
int CON = 0;

void setup() {

  pinMode(R, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(G, OUTPUT);

  pinMode(rojo, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verd, OUTPUT);

  pinMode(push, INPUT_PULLUP);

}

void loop() {
  
  analogWrite(R, 255);
  analogWrite(B, 255);
  analogWrite(G, 255);
  
}
