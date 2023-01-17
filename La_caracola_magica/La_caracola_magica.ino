/*La Caracola Magica
   Al agitar el dispositivo, se mostrara un mensaje en el display,
   el mensaje sera aleatorio dependiendo del numero random que se indique

   Conexiones:
    Pines de conexion LCD : D1-D4 (pines 4,5,6 y 7 respectivamente)
    LCD E y RS(respectivamenteu: pines 2 y 3

    SW200d: pin 8
*/

#include <LiquidCrystal.h>
LiquidCrystal pantalla(2, 3, 4, 5, 6, 7);

const int sensor = 8;
int numero = 0;

void setup() {
  pantalla.begin(16, 2);
  pinMode(sensor, INPUT);

}

void loop() {

  pantalla.print("Caracola Magica");

  if ( digitalRead(sensor))
  {
    numero = random(12);
  }

  switch (numero)
  {
    case 1:
      pantalla.print("Es cierto");
      break;

    case 2:
      pantalla.print("Probablemente");
      break;

    case 3:
      pantalla.print("Buen pronostico");
      break;

    case 4:
      pantalla.print("Sin duda");
      break;

    case 5:
      pantalla.print("SI");
      break;

    case 6:
      pantalla.print("no cuentes");
      pantalla.setCursor(0, 1);
      pantalla.print("con ello");
      break;

    case 7:
      pantalla.print("Mi respuesta");
      pantalla.setCursor(0, 1);
      pantalla.print("es NO");
      break;

    case 8:
      pantalla.print("Definitivamente ");
      pantalla.setCursor(0, 1);
      pantalla.print("NO");
      break;

    case 9:
      pantalla.print("Muy dudoso");
      break;

    case 10:
      pantalla.print("Mis fuentes me");
      pantalla.setCursor(0, 1);
      pantalla.print("dicen que no");
      break;

    default:
      pantalla.print("Vuelve");
      pantalla.setCursor(0, 1);
      pantalla.print("a preguntar");
      break;
  }

  delay(1000);
  pantalla.home();
  pantalla.clear();

}

