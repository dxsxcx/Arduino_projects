String mihtml = "<!DOCTYPE html> <html> <head> <title>Control Arduino</title> </head> <body> <h1>Hola Mundo</h1> </body> </html>";
int indice1 = 0;
int indice2 = 0;
String fragmento;

void setup() {
  Serial.begin(9600);
  mihtml.replace("Control Arduino", "Cadenas String");
  Serial.println(mihtml);


  indice1 = mihtml.indexOf("<body>");
  indice2 = mihtml.indexOf("</body>");
  fragmento = mihtml.substring(indice1 + 6, indice2);
  Serial.println(fragmento);
  


}

void loop() {


}
