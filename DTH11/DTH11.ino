#include <Wire.h>
#include <DHT11.h>

dht11 sensorTH;
#define PINSENSOR 7

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("\n");

  int lectura = sensorTH.read(PINSENSOR);
  Serial.println("Lee sensor");

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

  Serial.println("humedad (%): ");
  Serial.println((float)sensorTH.humidity, 2);
  Serial.println("Temperatura (Cº): ");
  Serial.println((float)sensorTH.temperature, 2);
  delay(1000);

}
