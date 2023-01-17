/*Temporizador de subida de escaleras
   El codigo detectara la presecencia de una persona al inicio de unas esclaeras,
   iniciara un contador y si la persona logra escalar en el tiempo dictado
   Se otorgara un codigo promocional

   29 de noviembre 2017
*/

//iniciamos libreria y parametros para LCD
#include<LiquidCrystal.h>
LiquidCrystal pantalla(2, 3, 4, 5, 6, 7);

//variables
int tiempoEscala = 10000; // tiempo en milisegundos 1000mS= 1s
int contador = 0;


//señales del push boton
int start = 10;
int finishit = 11;

void setup() {
  pinMode(start, INPUT);
  pinMode(finishit, INPUT);
  Serial.begin(9600);
  pantalla.begin(16, 2);
  pantalla.setCursor(0, 0);
  pantalla.print("ITESM");
  delay(4000);
  pantalla.clear();
  randomSeed(124); //semilla del codigo random
}

void loop() {



  if (digitalRead(start) == HIGH) {

    pantalla.print("Inicia el juego");
    contador = 0;

    do {
      pantalla.setCursor(0, 2);
      contador= contador + 1;
      pantalla.print(contador);

      if(contador == tiempoEscala){
        break;}

    } while (digitalRead(finishit) != HIGH);

    if (contador != tiempoEscala) {
      pantalla.clear();
      pantalla.setCursor(0, 0);
      pantalla.print("ganaste!");
      delay(2000);
    } else {
      pantalla.clear();
      pantalla.setCursor(0, 0);
      pantalla.print("Intentando de nuevo");
      delay(2000);
    }

  } else {
    pantalla.print("Welcome");
    pantalla.setCursor(0, 2);
    pantalla.print("press to start");
    delay(10);
    pantalla.clear();
  }

}

