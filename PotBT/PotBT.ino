/*
  Potenciometro bluetooth
  Este codigo lee el valor de un potenciometro y lo imprime en la consola serial de la app para smartphone
  Nota: para el modulo bluetooth HC-05/HC-06 no es necesario cablear una interrupcion (INT)

  Ultima modificacion 26 de mayo 2017
  Por Daniel Santos
*/

//Declaramos las librerias que utilizaremos para el codigo
#include "EB_Bluetooth.h"
#include <SoftwareSerial.h>

//Declaramos los puertos TX y RX como RX = 11; TX = 10; la interrupcion la manejamos con el pin 9
EB_Bluetooth miBT(11, 10);

//Declaramos variables que utilizaremos en el codigo
int pot = 0;
char dato;

void setup() {

  //Iniciamos el Serial y el modulo bluetooth a 9600 baudios
  Serial.begin(9600);
  miBT.begin();

  //configuramos el nombre de nuestro modulo bluetooth
  if (miBT.setName("miBT"))
  {
    delay (4000);
    Serial.println("Configuracion de nombre: ok");
  }
  else {
    delay (4000);
    Serial.println("Configuracion de nombre fallo");
  }
  Serial.println("Esperando a ser conectado...");
}


void loop() {
  //Utilizamos una condicion para comprobar la conexion con el modulo bluetooth.
  if (miBT.available())
  {
    //Almacenamos los datos que recibimos del potenciometro en la variable "pot".
    pot = analogRead(A 5);

    //Esta linea de codigo convierte el rango del potenciometro a un valor de 0 a 255.
    dato = map (pot, 0, 1023, 0, 255);

    //Imprime el valor del potenciometro en la consola serial y la consola de la app.
    miBT.print(dato);
    Serial.print(dato);
    miBT.print('\n');
  }
}
