//iniciamos libreria y parametros para LCD
#include<LiquidCrystal.h>
LiquidCrystal pantalla(2, 3, 4, 5, 6, 7);

#include<Servo.h>
Servo Carlitos;

//variable
int posicion = 0;
int button = 12;

void setup() {

  Carlitos.attach(11);
  pinMode(button, INPUT_PULLUP);
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
  pantalla.print("Servo - Carlitos");
  delay(3000);

}

void loop() {
  if (digitalRead(button) == LOW)
  {
    for (posicion = 0; posicion <= 180; posicion++)
    {
      Carlitos.write(posicion);
      delay (20);
    }

    for (posicion = 180; posicion >= 0; posicion--)
    {
      Carlitos.write(posicion);
      delay (20);
    }
  }
  
  else {
  }


}
