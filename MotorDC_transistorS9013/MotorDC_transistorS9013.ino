/*Motor DC.
  Este programa controla el giro de un motor de corriente directa (DC) o motor de corriente continua (CC).
  Con el pin 7 controlamos la señal de encendido mediante un transistor.
  29 de Junio del 2017.
  Filiberto Cruz Flores.
*/


void setup()
{
  pinMode(7, OUTPUT); //se establece el pin 7 como salida.
}

void loop()
{
digitalWrite(7, LOW); //el pin 7 permanece desactivado.
delay(1000); //esperamos 1000 milisegundos.
digitalWrite(7, HIGH); //el pin 7 se activa.
delay(1000); //esperamos 1000 milisegundos.
digitalWrite(7, LOW); //el pin 7 se desactiva.
delay(1000); //esperamos 1000 milisegundos.
digitalWrite(7, HIGH); //el pin 7 se activa.
delay(1000); //esperamos 1000 milisegundos.
}
