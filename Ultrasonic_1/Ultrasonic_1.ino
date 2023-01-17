//iniciamos libreria y parametros para LCD
#include<LiquidCrystal.h>
LiquidCrystal pantalla(2, 3, 4, 5, 6, 7);

//iniciamos la libreria para el sensor ultrasonico
#include <Ultrasonic.h>
Ultrasonic ultra (9, 10); //disparador:9, echo:10

//variable


void setup() {

  //intro
  Serial.begin(9600);
  pantalla.begin(16, 2);
  pantalla.setCursor(1, 0);
  pantalla.print("Santos  Studio");
  pantalla.setCursor(1, 1);
  pantalla.print("Made by DxSxCx");
  delay(3000);
  pantalla.clear();
  pantalla.setCursor(0, 0);
  pantalla.print("Ultrasonic");
  delay(3000);

}

void loop() {

  pantalla.clear();
  pantalla.print("Distancia:");
  pantalla.setCursor(0, 1);
  Serial.println(ultra.Ranging(CM));
  pantalla.print(ultra.Ranging(CM));
  pantalla.print("cm");
  delay(300);


}
