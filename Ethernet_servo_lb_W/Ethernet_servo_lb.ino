#include <Servo.h>
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0xEF, 0xFE, 0xED }; //colocar la direccion MAC
IPAddress ip(192, 168, 1, 20); // Colocar la direccion IP
EthernetServer servidor(8000);
Servo servi;
int dato = 0;

void setup()
{
  Ethernet.begin(mac, ip); //
  servidor.begin();
  servi.attach(5);//Servo begin
  Serial.begin(9600);
}
void loop()
{
  //
  EthernetClient cliente = servidor.available();

  if (cliente) { // Un cliente existe
    while (cliente.connected()) {
      if (cliente.available()) {
        char c = cliente.read();
        Serial.println(c);
        dato = (int)c;
        Serial.print("final: ");
        Serial.println(dato);
        dato = constrain(dato, 0, 180);
        servi.write(dato);
      }
      delay(100);
    }
    cliente.stop();
  }
}
