#include <Servo.h>
#include <SoftwareSerial.h> //se declara la libreria SoftwareSerial.h.

SoftwareSerial RFID(2, 3); //se le da a la variable "RFID" las propiedades de la libreria y se declaran los puertos Rx y Tx.
int dato = 0; //se define la una variable "dato" como int.
int ok = -1; //se define la una variable "ok" como int.
int fg; //se define la una variable "fg" como int.
int c; //se define la una variable "c" como int.
int d; //se define la una variable "d" como int.

Servo servo1;
int pos = 0;

//se define la una variable "tag" como int y se le iguala al numero "2,48,52,48,48,54,68,57,65,70,54,48,53,3".
int tag[14] = {2, 48, 49, 48, 48, 56, 49, 56, 70, 69, 57, 69, 54, 3};

//se define la una variable "nuevotag" como int y se le iguala al numero "0,0,0,0,0,0,0,0,0,0,0,0,0,0".
int nuevotag[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup()
{
  RFID.begin(9600); //se inicializa el serial al lector RFID.
  Serial.begin(9600); //se inicializa el Monitor Serial.
  pinMode(6, OUTPUT); //LED AZUL
  pinMode(5, OUTPUT); //LED ROJO

  servo1.attach(4);
  servo1.write(0);

}

//se define la variable "comparartag" como int y se le definen las variables "a" y "b" en ellas se definen como int y se les ortga que estan definidas en 14 secciones.
boolean comparartag(int a[14], int b[14])
{
  boolean ff = false;//se define la variable "ff" como int y se iguala a false.
  fg = 0; //se define la variable "fg" como int y se iguala a cero.
  for (c = 0 ; c < 14 ; c++) //se usa un for para que la variable "c" que esta definida como int se iguala a cero y si es menor que 14 se aunmentara de uno en uno.
  {
    if (a[c] == b[c]) //si la variable "a" que toma el aumento de la variable "c" es igual a la variable "b" que tomo el mismo aumento de la variable "c" si se cumple la funcion If.
    {
      fg++; //la variable "fg" aumenta de uno en uno.
    }
  }
  if (fg == 14) //si la variable "fg" es igual a 14
  {
    ff = true; //la variable "ff" es igual a true
  }
  return ff; // devuelve la variable ff.
}


void checarmitag() // checa cada etiqueta con la etiqueta que acaba de leer
{
  ok = 0; // Esta variable ayuda a la toma de decisiones si la variable "ok" es igual a 0.
  // si es mas 1 tenemos una coincidencia
  if (comparartag(nuevotag, tag) == true) //si la variable "comparartag", la variable "nuevotag" y "tag" son igual a true.
  {
    ok++; // la variable tag aumentara de uno en uno.
  }
}


void leertag() // lee cada etiqueta con la etiqueta que acaba de checar
{
  ok = -1; //la variable "ok" es igual a -1
  if (RFID.available() > 0) //si RFID esta disponible y es mayor a cero.
  {
    // lee los números de etiqueta
    delay(100); //el delay es necesario para dar tiempo a que los datos entren desde el buffer en serie.
    for (d = 0 ; d < 14 ; d++) //se pone una funcion for para leer el resto de la etiqueta, si la variable "d" es igual a cero y menor a 14 aumenta de uno en uno.
    {
      dato = RFID.read();//la variable "dato" se iguala a la lectura de RFID.
      nuevotag[d] = dato; //la variable "dato" de iguala a la variable "nuevotag" asigando el valor tomado de la variable "d".
    }
    RFID.flush(); //detiene las lecturas de RFID.
    checarmitag(); //se verifica si coinciden las etiquetas.
  }
  // ahora se acciona algo basado en el tipo de etiqueta.
  if (ok > 0) // si la variable "ok" es mayor a cero.
  {
    Serial.println("Bienvenido");// se imprime en el Monitor Serial la palabra "Bienvenido".
    digitalWrite(6, HIGH);//el pin 13 se activa.
    servo1.attach(4);

    for (pos = 0; pos < 60; pos += 1)
    {
      servo1.write(pos);
      delay(50);
    }

    delay(5000);

    digitalWrite(6, LOW); //el pin 13 se desactiva
    for (pos = 60; pos >= 0; pos -= 1)
    {
      servo1.write(pos);
      delay(50);
    }

    ok = -1; //la variable "ok" se iguala a -1
  }
  else if (ok == 0) // si la variable "ok" no es igual a cero.
  {
    Serial.println("Acceso denegado"); // se imprime en el Monitor Serial la palabra "Aceso denegado".
    digitalWrite(5, HIGH); //el pin 12 se activa.
    delay(5000); //se espera 3000 milisegundos.
    digitalWrite(5, LOW); //el pin 12 se desactiva
    ok = -1; //la variable "ok" se iguala a -1

  }
}

void loop()
{
  leertag(); //se mantiene en espera para leer un codigo de tag.
  servo1.detach();
}
