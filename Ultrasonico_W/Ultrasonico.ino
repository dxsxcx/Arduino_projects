#include <Ultrasonic.h>
Ultrasonic ultrasonico(11, 10); //trigger, echo
long distancia;

void setup() {
  Serial.begin(9600);
}
void loop() {
  
  distancia = ultrasonico.Ranging(1);
  Serial.println(distancia);
}
