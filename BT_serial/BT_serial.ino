/*
  LED Bluetooth
  Este codigo enciende un led utilizando el modulo bluetooth incluido en el kit, esto utilizando una app para smartphone.
  Nota: para el modulo bluetooth HC-05/HC-06 no es necesario cablear una interrupcion (INT)

  Ultima modificacion 26 de mayo 2017
  Por Daniel Santos
*/

//Declaramos las librerias que utilizaremos para el codigo
#include "EB_Bluetooth.h"
#include <SoftwareSerial.h>

//Declaramos los puertos TX y RX como RX = 11; TX = 10; la interrupcion la manejamos con el pin 9
EB_Bluetooth miBT(11, 10, 9);

void setup() {
  //Iniciamos el Serial y el modulo bluetooth a 9600 baudios
  Serial.begin(9600);
  miBT.begin();

  //configuramos el nombre de nuestro modulo bluetooth
  if (miBT.setName("miBT")) {
    Serial.println("Configuracion de nombre: vale");
  } else {
    Serial.println("Confuguracion de nombre: not ok");
  }
  Serial.println("Esperando ser conectado...");
}

void loop() {
  //Creamos una variable para guardar el mensaje que escribamos en la consola
  char dato;

  //Utilizamos una condicion para comprobar la conexion con el modulo bluetooth
  if (miBT.connected()) {
    //Si la conexion con el bluetooth esta disponible se correra el codigo
    if (miBT.available()) {
      //Tomamos el mensaje que se escriba desde la consola del dispositivo movil y la imprimimos en la consola de IDE
      dato = MiBT.read();
      Serial.print(dato);
    }
    //Si la conexion con el bluetooth esta disponible se correra el codigo
    if (Serial.available()) {
      //Tomamos el mensaje que se escriba desde la consola del IDE y la imprimimos en la consola del dispositivo movil
      dato = Serial.read();
      miBT.print(dato);
    }
  }
}
