#include <Stepper.h>
int pasosxRev = 200; 
Stepper motorP(pasosxRev, 8, 10, 9, 11);

void setup() {

  Serial.begin(9600);
  motorP.setSpeed(60);

}

void loop() {
  Serial.println("Sentido del reloj");
  motorP.step(200);
  delay(500);

  Serial.println("Sentido contrario del reloj");
  motorP.step(-200);
  delay(500);

}
