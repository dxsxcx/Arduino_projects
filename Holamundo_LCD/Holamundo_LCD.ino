#include <LiquidCrystal.h>
LiquidCrystal pantalla(2,3,4,5,6,7);

void setup() {
pantalla.begin(16,2);
pantalla.print("Hola mundo");  
}

void loop() {
}
