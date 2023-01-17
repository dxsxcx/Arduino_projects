#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0xEF, 0xFE, 0xED }; //colocar la direccion MAC
IPAddress ip(192, 168, 1, 20); // Colocar la direccion IP
EthernetServer servidor(8000);

void setup()
{
  Ethernet.begin(mac, ip); //
  servidor.begin(); //
  pinMode(3, OUTPUT); //
  digitalWrite(3, LOW); //
}
void loop()
{
  //
  EthernetClient cliente = servidor.available();

  if (cliente) { // Un client existe
    while (cliente.connected()) {
      if (cliente.available()) {
        char c = cliente.read();
        if (c == 'A')
        {
          digitalWrite(3, HIGH);
        }
        if (c == 'a')
        {
          digitalWrite(3, LOW);
        }
      }
      servidor.println(analogRead(0));
      delay(100);
    }
    cliente.stop();
  }
}
