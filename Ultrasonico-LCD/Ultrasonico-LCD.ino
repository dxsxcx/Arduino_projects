/*Medidor de distancia
  Este Software muestra en el display la distancia en centimetros
  entre un objeto y el sensor
  Daniel Santos Calderón
*/

#include <Ultrasonic.h> //Librería Ultrasocico.
#include <LiquidCrystal.h> //Librería LiquidCrystal

int cm = 1;
int inc = 0;
Ultrasonic miultra(10, 11);
double distancia = 0;

LiquidCrystal pantalla(2, 3, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  pantalla.begin(16, 2);
  pantalla.print("Medidor de distancia");
}

void loop() {

  pantalla.setCursor(0, 1);
  distancia = miultra.Ranging(cm);

  Serial.print(distancia);
  Serial.println(" cms");
  pantalla.print(distancia);
  pantalla.print(" cms");
  delay(300);

  pantalla.clear();

}

