String cadena;
String cadena1;
String cadena2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) // Hay algo pendiente de leer
  {
    char c = Serial.read(); // Leemos los caracteres de uno en uno
    cadena += c; // Los añadimos al String
    if (c == '\n')
    {

      cadena.toUpperCase();

      Serial.print("comparar: ");
      Serial.println(cadena);

      int indice;
      int lenght1;
      int lenght2;

      indice = cadena.indexOf(",");
      cadena1 = cadena.substring(0 , indice);
      cadena2 = cadena.substring(indice + 2 );

      Serial.println("cadenas a comparar");
      Serial.print("cadena 1: ");
      Serial.println(cadena1);
      Serial.print("cadena 2: ");
      Serial.println(cadena2);

      lenght1 = cadena1.length();
      lenght2 = cadena2.length() - 1;

      Serial.println("Tamaña de las cadenas:");
      Serial.print("cadena 1: ");
      Serial.println(lenght1);
      Serial.print("cadena 2: ");
      Serial.println(lenght2);


      if (lenght1 < lenght2) {
        Serial.println("cadena 2 es mas grande que cadena 1");
        Serial.println("letras diferentes:");
        for (int i = 0; i < lenght1; i++) {
          if (cadena1.indexOf(cadena1.charAt(2)) > -1) {
            Serial.println("true");
          }
          else {
            Serial.println(cadena2.substring(i));
          }
        }
      }

      else {
        Serial.println("cadena 1 es mas grande que cadena 2");
        Serial.println("letras diferentes:");
        for (int i = 0; i < lenght2; i++) {
          if (cadena1.indexOf(cadena2.charAt(i)) > -1) {
            Serial.println("true");
          }
          else {
            Serial.println(cadena2.substring(i));
          }
        }
      }
    }
  }

}
