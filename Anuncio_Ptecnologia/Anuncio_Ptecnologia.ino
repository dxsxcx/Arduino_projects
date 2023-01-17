#include <LiquidCrystal.h>
LiquidCrystal pantalla(2, 3, 4, 5, 6, 7);

void setup() {
pantalla.begin(16, 2);
}

void loop() {
  
  pantalla.print(" Lo mejor");
  pantalla.setCursor(0,1);
  pantalla.print("las mejores ofertas, puesto 20");
  for(int a; a < 25; a++){
  pantalla.scrollDisplayLeft();
  delay(500);
  }
  pantalla.clear();
}
