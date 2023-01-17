/*Servo con Potenciometro.
  Es un motor que funciona de 0 a 180 grados con una cierta resistencia de peso en el.
  Por lo general se ocupan distintos tamaños de servos, el servo SG90 funciona con el voltaje y la corriente que nos da Arduino.
  Además, en este programa no se manipulará mediante el Monitor Serial si no por un potenciómetro.
  25 de Mayo del 2017.
  Filiberto Cruz Flores.
*/


#include <Servo.h> //librería Servo.
Servo servo; //extraemos en la variable servo todo lo que la libreria Servo nos ofrece.
int variador = 0; //colocamos una variable en forma de int y se inicializa con valor 0.

void setup() {

  servo.attach(4); //colocamos en el pin 4 la señal de control para el servo.

}

void loop() {

  variador = analogRead(A5); //tomamos la lectura del puerto analógico A5 en la variable "variador".
  int grados = map (variador , 0, 1023, 0, 180); //hacemos un map de la lectura analógica para convertirla en los grados del servo y lo colocamos en una variable "grados" en forma de int.
  servo.write(grados); //colocamos la variable "grados" dentro de la escritura servo para que al mover el potenciómetro el rotor del servo se mueva conforme al mapeo que se realizó.
  delay(15); //esperamos 15 milisegundos y verificamos si hubo alguna variación.

}
