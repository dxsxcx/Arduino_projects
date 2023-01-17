#include <Wire.h>
#include <DHT11.h>
#include <SoftwareSerial.h>
#include "EB_Bluetooth.h"

dht11 sensorTH;
#define PINSENSOR 5

EB_Bluetooth miBT(3, 2); //RX, 3; TX, 2 ; INT,9 para el  HC-05 el pin 9 se remueve
char mensaje[250];
int i = 0;

int foto;

int LEDS = 8; //Leds
int IN1 = 10; //entrada de los motores
int IN2 = 11; //entrada de los motores
int IN3 = 12; //entrada de los motores
int IN4 = 13; //entrada de los motores

void setup() {

  pinMode(LEDS, OUTPUT);// Leds
  pinMode(IN1, OUTPUT);//INT1
  pinMode(IN2, OUTPUT);//INT2
  pinMode(IN3, OUTPUT);//INT3
  pinMode(IN4, OUTPUT);//INT$

  Serial.begin(9600);
  miBT.begin();
  if (miBT.setName("BTDANY"))
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

  foto = analogRead(A0);
  if (foto >= 1000){
    digitalWrite(LEDS, HIGH);
    }
    else{digitalWrite(LEDS, LOW);}

  int lectura = sensorTH.read(PINSENSOR);
  switch (lectura)
  {
    case DHTLIB_OK:
      Serial.println("OK");
      break;

    case DHTLIB_ERROR_CHECKSUM:
      Serial.println("Error de suma de confirmacion");
      break;

    case DHTLIB_ERROR_TIMEOUT:
      Serial.println("Tiempo Excedido");
      break;

    default:
      Serial.println("Error desconocido");
      break;
  }

  char dato;
  if (miBT.connected()) {
    if (miBT.available())
    {
      dato = miBT.read();
      mensaje[i] = dato;
      i++;
      if (dato == '\n')
      {
        if (strstr(mensaje, "GO") != 0) //Adelante
        {
          Serial.println("lectura");
          digitalWrite (IN1, HIGH);
          digitalWrite (IN2, LOW);
          digitalWrite (IN3, LOW);
          digitalWrite (IN4, LOW);
        }

        if (strstr(mensaje, "L") != 0) //Derecha
        {
          Serial.println("lectura");
          digitalWrite (IN3, HIGH);
          digitalWrite (IN4, LOW);
          delay(1000);
          digitalWrite (IN3, LOW);
          digitalWrite (IN4, LOW);
        }

        if (strstr(mensaje, "R") != 0) //Right
        {
          Serial.println("lectura");
          digitalWrite (IN3, LOW);
          digitalWrite (IN4, HIGH);
          delay(1000);
          digitalWrite (IN3, LOW);
          digitalWrite (IN4, LOW);
        }

        if (strstr(mensaje, "B") != 0) //Atras
        {
          Serial.println("lectura");
          digitalWrite (IN1, LOW);
          digitalWrite (IN2, HIGH);
          digitalWrite (IN3, LOW);
          digitalWrite (IN4, LOW);
        }

        if (strstr(mensaje, "S") != 0) //Stop
        {
          Serial.println("lectura");
          digitalWrite (IN1, LOW);
          digitalWrite (IN2, LOW);
          digitalWrite (IN3, LOW);
          digitalWrite (IN4, LOW);
        }

        if (strstr(mensaje, "DATA") != 0) //DATA
        {
          miBT.print("humedad (%): ");
          miBT.print(sensorTH.humidity);
          miBT.print("Temperatura (Cº): ");
          miBT.print(sensorTH.temperature);
        }
        i = 0;
        for (int j = 0; j > 255; j++)
        {
          mensaje[j] = "";
        }

      }
    }
  }
}
