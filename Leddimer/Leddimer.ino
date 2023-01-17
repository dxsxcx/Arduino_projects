int R = 9;
int G = 10;
int B = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (R, OUTPUT);
  pinMode (G, OUTPUT);
  pinMode (B, OUTPUT);

  digitalWrite(R, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(B, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {

    int rojo = Serial.parseInt();
    int verde = Serial.parseInt();
    int azul = Serial.parseInt();

    rojo = 255 - constrain(rojo, 0, 255);
    verde = 255 - constrain(verde, 0, 255);
    azul = 255 - constrain(azul, 0, 255);

    analogWrite(R, rojo);
    analogWrite(G, verde);
    analogWrite(B, azul);

    Serial.print (rojo, HEX);
    Serial.print (verde, HEX);
    Serial.println (azul, HEX);

  }
}
