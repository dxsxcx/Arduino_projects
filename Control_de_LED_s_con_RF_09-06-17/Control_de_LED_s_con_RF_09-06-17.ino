/*Control de LED con RF.
  La comunicación de Radio Frecuencia (RF) permite enviar señales desde el control (trasmisor) a un receptor inalámbricamente,
  el control maneja 4 canales que son a,b,c,d y cada uno recibe una señal independiente si el VT detecta que la señal es correcta
  VT pone en alto la señal y los canales D0, D1, D2, D3 son los que prenden en un HIGH.
  cada botón irá a una salida digital para encender un led por lo cual se controlarán 4 leds.
  07 de Junio del 2017.
  Filiberto Cruz Flores.
*/



void setup() {

  Serial.begin (9600); //se inicializa el Monitor Serial.
  pinMode (6, OUTPUT) ; //se define el pin 6 como salida.
  pinMode (5, OUTPUT) ; //se define el pin 5 como salida.
  pinMode (4, OUTPUT) ; //se define el pin 4 como salida.
  pinMode (3, OUTPUT) ; //se define el pin 3 como salida.
  for (int i = 7 ; i < 12 ; i++) //a un for se le asigna la variable "i" como int y se iguala a 7, si la variable es menor a 12, la variable ira aumentando de uno en uno.
    pinMode(i, INPUT) ; //se define la variable como pin de entrada.
}

void loop() {

  if (digitalRead(7) )     // Si hay dato valido.
  {
    Serial.println("se pulso el"); //en el Monitor Serial aparece la leyenda "se pulso el", si el VT recibe un dato valido por parte del mando.

    if (digitalRead(8))//si el pin 8 tiene una lectura.
    {
      Serial.println( "Botón A");//en el Monitor Serial aparece la leyenda "Botón A". 
      digitalWrite(3, HIGH); //se activa el pin 3.
      delay(1000); // esperamos 1000 milisegundos.
      digitalWrite(3, LOW); //se desactiva el pin 3.
    }

    if (digitalRead(9)) //si el pin 9 tiene una lectura.
    {
      Serial.println( "Botón B"); //en el Monitor Serial aparece la leyenda "Botón B". 
      digitalWrite(4, HIGH); //se activa el pin 4.
      delay(1000); // esperamos 1000 milisegundos.
      digitalWrite(4, LOW); //se desactiva el pin 4.
    }

    if (digitalRead(10)) //si el pin 10 tiene una lectura.
    {
      Serial.println( "Botón C"); //en el Monitor Serial aparece la leyenda "Botón C".
      digitalWrite(5, HIGH); //se activa el pin 5.
      delay(1000); // esperamos 1000 milisegundos.
      digitalWrite(5, LOW); //se desactiva el pin 5.
    }
    if (digitalRead(11)) //si el pin 10 tiene una lectura.
    {
      Serial.println( "Botón D"); //en el Monitor Serial aparece la leyenda "Botón D".
      digitalWrite(6, HIGH); //se activa el pin 6.
      delay(1000); // esperamos 1000 milisegundos.
      digitalWrite(6, LOW); //se desactiva el pin 6.
    }
    Serial.println("\t"); //en el Monitor Serial se pone un tabulador para la frase completa.
  }

}
