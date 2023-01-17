/*
  LED Bluetooth
  Este codigo enciende un grupo de LEDS utilizando el modulo bluetooth incluido en el kit, esto utilizando una app para smartphone.
  Nota: para el modulo bluetooth HC-05/HC-06 no es necesario cablear una interrupcion (INT)

  Ultima modificacion 26 de mayo 2017
  Por Daniel Santos
*/

//Declaramos las librerias que utilizaremos para el codigo
#include <SoftwareSerial.h>
#include "EB_Bluetooth.h"


//Declaramos los puertos TX y RX como RX = 11; TX = 10; la interrupcion la manejamos con el pin 9
EB_Bluetooth miBT(11, 10);

//Declaramos variables que utilizaremos en el codigo
char mensaje[250];
int i = 0;

void setup() {

  pinMode(7, OUTPUT);//LED azul
  pinMode(6, OUTPUT);//LED verde
  pinMode(5, OUTPUT);//LED Amarillo

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
    //Si la conexion esta disponible se correra el codigo
    if (miBT.available())
    {
      //Tomamos el mensaje que se escriba desde la consola del dispositivo movil y la almacenamos en la variable dato
      dato = miBT.read();

      //Convertimos la variable "dato" en un arreglo de variables char 
      mensaje[i] = dato;
      i++;

      //Si la variable "dato" tiene un caracter retorno de carro (\n) se interpreta el codigo
      if (dato == '\n')
      {
        //Si la variable "dato" es igual al mensaje se enciende unicamente el LED azul
        if (strstr(mensaje, "enciende led azul") != 0)
        {
          Serial.println(mensaje);
          digitalWrite(7, HIGH);
          digitalWrite(6, LOW);
          digitalWrite(5, LOW);
        }
        //Si la variable "dato" es igual al mensaje se enciende unicamente el LED verde
        if (strstr(mensaje, "enciende led rojo") != 0)
        {
          Serial.println(mensaje);
          digitalWrite(7, LOW);
          digitalWrite(6, HIGH);
          digitalWrite(5, LOW);
        }
        //Si la variable "dato" es igual al mensaje se enciende unicamente el LED amarillo
        if (strstr(mensaje, "enciende led amarillo") != 0)
        {
          Serial.println(mensaje);
          digitalWrite(7, LOW);
          digitalWrite(6, LOW);
          digitalWrite(5, HIGH);
        }
        //Si la variable "dato" es igual al mensaje se encienden todos los LEDs
        if (strstr(mensaje, "enciende todo") != 0)
        {
          Serial.println(mensaje);
          digitalWrite(7, HIGH);
          digitalWrite(6, HIGH);
          digitalWrite(5, HIGH);
        }
        //Si la variable "dato" es igual al mensaje se apagan todos los LEDS
        if (strstr(mensaje, "apaga todo") != 0)
        {
          Serial.println(mensaje);
          digitalWrite(7, LOW);
          digitalWrite(6, LOW);
          digitalWrite(5, LOW);
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
