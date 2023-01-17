/*
  Bluetooth Configuracion
  Este codigo configura el modulo bluetooth, se debe correr antes de utilizar el modulo por primera vez.
  Nota: para el modulo bluetooth HC-05/HC-06 no es necesario cablear una interrupcion (INT)

  Ultima modificacion 26 de mayo 2017
  Por Daniel Santos
*/


//Declaramos las librerias que utilizaremos para el codigo
#include <SoftwareSerial.h>

//Declaramos los puertos TX y RX como RX = 11; TX = 10; la interrupcion la manejamos con el pin 9
SoftwareSerial miBT(11, 10); 

void setup() {

  //Iniciamos el Serial y el modulo bluetooth a 9600 baudios
  Serial.begin(9600);
  miBT.begin(9600);

  //Configuramos la velocidad de transferencia de datos en baudios
  miBT.print("AT+BAUD:");
  miBT.print("4");
  miBT.print("\r\n");
  delay(1000);

  //Asignamos un nombre a nuestro modulo bluetooth
  miBT.print("AT+NAME");
  miBT.print("miBT");
  miBT.print("\r\n");
  delay(1000);

  //Configuramos el Mode (maestro/esclavo) 
  miBT.print("AT+CMODE:");
  miBT.print("1");
  miBT.print("\r\n");

}
void loop() {
  //En esta ocasion no utilizaremos la funcion loop.
}
