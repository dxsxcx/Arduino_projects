/*
  Objeto String
  Este codigo permite usar y manipular cadenas de texto de formas más complejas que las matrices de caracteres.
  Puedes concatenar cadenas, añadirlas, buscar y reemplazar subcadenas y más. Se necesita más memoria que una
  matriz de caracteres simple.
  Ultima modificacion 26 de mayo 2017
  Por Daniel Santos
*/

//Asignamos a 3 objetos String textos
String texto1 = "Este codigo permite usar y manipular cadenas de texto de formas más complejas";
String texto2 = ", puedes concatenar cadenas, añadirlas, buscar y reemplazar subcadenas y más";
String texto3 = "Este codigo permite usar y manipular cadenas de texto de formas más complejas";

//Asignamos variables que utilizaremos en el codigo.
int indice = 0;
String otra;
int valor;

void setup() {
  //Iniciamos el serial e imprimimos el primer texto de prueba.
  Serial.begin(9600);
  Serial.println("Frase inicial");
  Serial.print("\t");
  Serial.println(texto1);

  //Imprimimos el tamaño del texto.
  Serial.print("Tamaño de texto: ");
  Serial.println(texto1.length());

  //Remplazamos una palabra por otra
  texto1.replace("complejas", "elaboradas");
  Serial.println("Texto remplazado:");
  Serial.print("\t");
  Serial.println(texto1);

  //concatenamos la cadena de texto 1 con la cadena de texto 2.
  Serial.println("Textos concatenados:");
  texto1.concat(texto2);
  Serial.print("\t");
  Serial.println(texto1);

  //buscamos la posicion de la palabra que remplazamos
  indice = texto1.indexOf("elaboradas");
  Serial.print("indice de la palabra que remplazamos: ");
  Serial.println(indice);

  //Substraemos la paralabra que remplazamos
  Serial.print("Texto remplazado:");
  otra = texto1.substring(indice , indice + 10);
  Serial.println(otra);

  //Verificamos que el texto1 sea igual al texto 3
  valor = texto1.equals(texto3);
  Serial.print("El texto es igual: ");
  Serial.println(valor);

  //Remueve la palabra que remplazamos en un inicio
  Serial.println("Remueve la palabra que remplazamos:");
  texto1.remove(indice, 10);
  Serial.print("\t");
  Serial.println(texto1);
}

void loop() {
  // no utilizaremos el loop en esta ocacion
}
