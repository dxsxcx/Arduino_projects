/*
  Conversion de datos
  Este codigo cambia las letras de tu nombre a binario, hexadecimal y decimal.
  
  Ultima modificacion 26 de mayo 2017
  Por Daniel Santos
*/

void setup() {
  //Iniciamos la consola y mandamos a imprimir un texto  
  Serial.begin(9600);
  Serial.println("Convierte las letras deserial");
}

void loop() {
  //imprime en la consola letra por letra 
  Serial.println("Imprime mi nombre en binario");
  Serial.println( 'D' , BIN ); //para convertir valor a binario
  Serial.println( 'A' , BIN );
  Serial.println( 'N' , BIN );
  Serial.println( 'I' , BIN );
  Serial.println( 'E' , BIN );
  Serial.println( 'L' , BIN );
  Serial.println( '\n' );

  Serial.println("Imprime mi nombre en hexadecimal");
  Serial.println( 'D' , HEX ); //para convertir valor a hex
  Serial.println( 'A' , HEX );
  Serial.println( 'N' , HEX );
  Serial.println( 'I' , HEX );
  Serial.println( 'E' , HEX );
  Serial.println( 'L' , HEX );
  Serial.println( '\n' );
  
  Serial.println("Imprime mi nombre en decimal");
  Serial.println( 'D' , DEC ); //para convertir valor a hex
  Serial.println( 'A' , DEC );
  Serial.println( 'N' , DEC );
  Serial.println( 'I' , DEC );
  Serial.println( 'E' , DEC );
  Serial.println( 'L' , DEC );
  Serial.println( '\n' );
  
  while (true) {
    continue;
  }
}
