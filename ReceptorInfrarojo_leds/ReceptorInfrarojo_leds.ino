/*Sensor inflarojo con led RGB y Buzzer.
  La idea es encender un LED RGB en distintos colores segun el boton seleccionado del control
  Filiberto Cruz Flores.
*/
#include <IRremote.h>
IRrecv receptorIR(6);
decode_results resultados;
String c;

int R = 11;
int G = 10;
int B = 9;
int buzzer = 5;

void setup() {
  Serial.begin(9600);
  receptorIR.enableIRIn();
  pinMode(R, OUTPUT); //rojo
  pinMode(G, OUTPUT); //verde
  pinMode(B, OUTPUT); //azul
  pinMode(buzzer, OUTPUT); //buzzer
  
}

void loop() {

  if (receptorIR.decode(&resultados)) {
    Serial.println(resultados.value); //imprime los datos recibidos
    receptorIR.resume(); //regresa a recibir el dato
  }

  c = resultados.value;

  if (c == "16756815") //ON
  {
    analogWrite(R, 255);
    analogWrite(G, 255);
    analogWrite(B, 255);
  }
  if (c == "16754775") //White
  {
    analogWrite(R, 0);
    analogWrite(G, 0);
    analogWrite(B, 0);
  }
  if (c == "16750695") //Red
  {
    analogWrite(R, 0);
    analogWrite(G, 255);
    analogWrite(B, 255);
  }
  if (c == "16767015") //Green
  {
    analogWrite(R, 255);
    analogWrite(G, 0);
    analogWrite(B, 255);
  }
  if (c == "16746615") //Blue
  {
    analogWrite(R, 255);
    analogWrite(G, 255);
    analogWrite(B, 0);
  }
  if (c == "16757325") //Flash
  {
    analogWrite(buzzer, 255);
    delay(100);
    analogWrite(buzzer, 0);
    delay(100);
    
  }
  if (c == "16775175") //Off
  {
    analogWrite(R, 255);
    analogWrite(G, 255);
    analogWrite(B, 255);
    analogWrite(buzzer, 0);
  }
  else {
    analogWrite(R, 255);
    analogWrite(G, 255);
    analogWrite(B, 255);
    analogWrite(buzzer, 0);
  }


}




