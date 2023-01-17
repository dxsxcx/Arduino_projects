/*
  Potenciometro bluetooth
  Este codigo controla un servo motor via bluetooth
  Nota: para el modulo bluetooth HC-05/HC-06 no es necesario cablear una interrupcion (INT)

  Ultima modificacion 26 de mayo 2017
  Por Daniel Santos
*/

//Declaramos las librerias que utilizaremos para el codigo
#include <SoftwareSerial.h>
#include "EB_Bluetooth.h"
#include <Servo.h>

//nombramos la funcion servo
Servo servo1;

//Declaramos los puertos TX y RX como RX = 11; TX = 10; la interrupcion la manejamos con el pin 9
EB_Bluetooth miBT(11, 10);

//Declaramos variables que utilizaremos en el codigo
char mensaje[250];
int i = 0;

void setup() {
  //declaremos el pin del servo
  servo1.attach(6);


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
  //Creamos una variable para guardar el mensaje que escribamos en la consola
  char dato;

  //Utilizamos una condicion para comprobar la conexion con el modulo bluetooth
  if (miBT.connected()) {
    //Tomamos el mensaje que se escriba desde la consola del dispositivo movil y la almacenamos en la variable dato
    if (miBT.available())
    {
      //Convertimos la variable "dato" en un arreglo de variables char
      dato = miBT.read();
      mensaje[i] = dato;
      i++;

      //Si la variable "dato" tiene un caracter retorno de carro (\n) se interpreta el codigo
      if (dato == '\n')
      {
        //Si la variable "dato" es igual al mensaje se activa el servo motor
        if (strstr(mensaje, "dispara") != 0)
        {
          Serial.println(mensaje);
          servo1.write(90); //No aumentar el valor a mas de 180
          delay(1000);
          servo1.write(0); //No disminuir el valor a mas de 0
        }
        //este ciclo se utiliza para el arreglo de datos char
        i = 0;
        for (int j = 0; j > 255; j++)
        {
          mensaje[j] = "";
        }
      }
    }
  }
}
