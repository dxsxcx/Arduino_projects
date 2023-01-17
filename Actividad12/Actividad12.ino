#include <Stepper.h>
int Pasos = 0;
int mov; 
Stepper motorP(Pasos, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  motorP.setSpeed(60);
  Serial.println("Numero de pasos del motor");
}

void loop() {
  while (Serial.available() > 0)
  {
  Pasos = Serial.parseInt();
  motorP.step(Pasos);
 
  }
}
