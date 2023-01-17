//iniciamos libreria y parametros para LCD
#include<LiquidCrystal.h>
LiquidCrystal pantalla(2, 3, 4, 5, 6, 7);

//variables
int sensor = 0;
int luz = 0;
int intensidad = 0;

void setup() {
  Serial.begin(9600);
  pantalla.begin(16, 2);
  pantalla.setCursor(0, 0);
  pantalla.print("MADE BY DSC");
  delay(3000);
}

void loop() {

  pantalla.clear();
  sensor = analogRead(1);
  Serial.println(sensor);
  luz = map(sensor, 573, 844, 0, 1023);
  luz = constrain (luz, 0, 1023);
  intensidad = (luz * 100) / 1023;

  pantalla.print("Luz: ");
  pantalla.print(luz);
  pantalla.setCursor(0, 1);
  pantalla.print("intensidad: ");
  pantalla.print(intensidad);
  pantalla.print("%");
  delay(1000);

}
