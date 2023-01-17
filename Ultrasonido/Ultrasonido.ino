#include <Ultrasonic.h>
int cm = 1;
int inc = 0;
double distancia = 0;
Ultrasonic misensor(10, 11); //trigger 10, Echo 11

void setup() {
  Serial.begin(9600);
}

void loop() {
  distancia = misensor.Ranging(cm);
  Serial.print(distancia);
  Serial.println(cm);
  delay(100);
}
