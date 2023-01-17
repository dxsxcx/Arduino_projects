/*
  Arreglos
  Este codigo manda a imprimir una suma de arreglos tipo char

  Ultima modificacion 26 de mayo 2017
  Por Daniel Santos
*/

char texto1[4] = {'H', 'o', 'l', 'a'};
char texto2[5] = {'m', 'u', 'n', 'd', 'o'};
char texto4[1] = {' '};
char texto3[11];

void setup() {
  //iniciamos la consola
  Serial.begin(9600);

  /*Mandamos a imprimir caracter por caracter del arreglo 3
   *dentro del Serial.print agregamos lo caracteres de los
   *arreglos del textos 1, 2 y 3 al arreglo texto 4
   */
   
  Serial.print (texto3[0] = texto1[0]); 
  Serial.print (texto3[1] = texto1[1]);
  Serial.print (texto3[2] = texto1[2]);
  Serial.print (texto3[3] = texto1[3]);
  Serial.print (texto3[4] = texto4[0]);
  Serial.print (texto3[5] = texto2[0]);
  Serial.print (texto3[6] = texto2[1]);
  Serial.print (texto3[7] = texto2[2]);
  Serial.print (texto3[8] = texto2[3]);
  Serial.print (texto3[9] = texto2[4]);
  Serial.print (texto3[10] = texto2[5]);


}

void loop() {
  // No utilizamos el Loop en esta ocasion
}
