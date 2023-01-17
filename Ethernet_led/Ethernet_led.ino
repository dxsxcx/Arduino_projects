#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0xEF, 0xFE, 0xED }; //colocar la direccion MAC
IPAddress ip(192, 168, 1, 20); // Colocar la direccion IP
EthernetServer server(80);

String peticion; // Para guardar la peticion del cliente
boolean LED7_status = 0;
boolean LED6_status = 0;
boolean LED5_status = 0;

void setup()
{ Ethernet.begin(mac, ip);
  server.begin();
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}
void loop()
{
  EthernetClient cliente = server.available(); // Comprobamos si hay peticiones

  if (cliente) // En caso afirmativo
  {
    boolean termino = true;
    while (cliente.connected())
    {
      if (cliente.available()) // Hay algo pendiente de leer
      {
        char c = cliente.read(); // Leemos los caracteres de uno en uno
        peticion += c; // Los añadimos al String
        if (c == '\n' && termino)
        {
          cliente.println("HTTP/1.1 200 OK");
          cliente.println("Content-Type: text/html");
          cliente.println("Connection: close");
          cliente.println();
          cliente.println("<!DOCTYPE html>"); // Envia la pagina Web
          cliente.println("<html>");
          cliente.println("<head>");
          cliente.println("<title>Control de LEDs en Arduino</title>");
          cliente.println("</head>");
          cliente.println("<body>");
          cliente.println("<h1>LED</h1>");
          cliente.println("<p>Haz click para conmutar el LED.</p>");
          cliente.println("<form method=\"get\">");
          Procesa_Estado_Chechbox(cliente);
          cliente.println("<br>");
          cliente.println("<input type=\"submit\" value=\"enviar\">");
          cliente.println("</form>");
          cliente.println("</body>");
          cliente.println("</html>");
          Serial.print(peticion);
          peticion = ""; // Una vez procesador, limpiar el string
          break;
        }

        if (c == '\n')
          termino = true;
        else if (c != '\r')
          termino = false;

      } 					// termina if (cliente.available...
    }   						// termina while...
    delay(10);// Da tiempo
    cliente.stop(); 				// Cerra conexion
  }  							// If cliente
} 							// loop

void Procesa_Estado_Chechbox(EthernetClient cl)
{
  //Led 7
  if (peticion.indexOf("LED7=7") > -1) // LED7 seleccionado
  {
   LED7_status = !LED7_status ;
  }  // Si esta seleccionado invertimos el valor
  digitalWrite(7, LED7_status);

  if (LED7_status){
    cl.println("<input type=\"checkbox\" name=\"LED7\" value=\"7\"checked>LED7");
    cl.println("<br>");}
  else{
    cl.println("<input type=\"checkbox\" name=\"LED7\" value=\"7\">LED7");
    cl.println("<br>");}
    
  //Led 6
  if (peticion.indexOf("LED6=6") > -1) // LED6 seleccionado
  {
   LED6_status = !LED6_status ;
  }  // Si esta seleccionado invertimos el valor
  digitalWrite(6, LED6_status);

  if (LED6_status){
    cl.println("<input type=\"checkbox\" name=\"LED6\" value=\"6\"checked>LED6");
    cl.println("<br>");}
  else{
    cl.println("<input type=\"checkbox\" name=\"LED6\" value=\"6\">LED6");
    cl.println("<br>");}

  //Led 5
  if (peticion.indexOf("LED5=5") > -1) // LED5 seleccionado
  {
   LED5_status = !LED5_status ;
  }  // Si esta seleccionado invertimos el valor
  digitalWrite(5, LED5_status);

  if (LED5_status){
    cl.println("<input type=\"checkbox\" name=\"LED5\" value=\"5\"checked>LED5");
    cl.println("<br>");
  }
  else{
    cl.println("<input type=\"checkbox\" name=\"LED5\" value=\"5\">LED5");
    cl.println("<br>");
    }
}


