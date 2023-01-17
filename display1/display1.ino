#include<LiquidCrystal.h>
LiquidCrystal pantalla(2, 3, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  pantalla.begin(16, 2);

}

void loop() {
  if (Serial.available())
  {
    pantalla.write(Serial.read());
    delay(1000);
  }
  else 
  {
    delay (2000);
    pantalla.clear();
  }

}
