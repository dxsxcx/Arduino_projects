void setup() {
  //declarar el tipo de puerto con el que vamos a trabajar
  pinMode(13, OUTPUT); //numero de pin (2 al 13) / salida(OUTPUT)
}
//el loop hace repetir el proceso dentro del mismo
void loop() {
  //hacer la logica de encender el led
  digitalWrite(13, HIGH); //numero de pin / Valor = 1, 5v de salida
  //mantener el estado HIGH 1 segundo
  delay(1000);
  //apagar el led 
  digitalWrite(13, LOW);
  //mantener el estado LOW 1 segundo
  delay(1000);
}
