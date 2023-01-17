#include <Servo.h>

Servo servo1;
int pos = 0;
int pot = 0;
int grados = 0;

void setup()
{
  Serial.begin(9600);
  servo1.attach(9);
}

void loop() {

  pot = analogRead(0);
  Serial.println(pot);
  grados = map (pot, 0, 1023, 0, 179);

  servo1.write(grados);
  delay(15);

}
