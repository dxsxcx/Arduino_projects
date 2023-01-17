#include <LiquidCrystal.h>
LiquidCrystal pantalla(2, 3, 4, 5, 6, 7);
void setup() {
  Serial.begin(9600);
  pantalla.begin(16, 2);
}

void loop() {
  pantalla.display();
  pantalla.setCursor(0, 0);
  pantalla.print("hola");
  pantalla.setCursor(2, 1);
  pantalla.print("heyyy");
  delay(500);
  pantalla.noDisplay();
  delay(500);
}
