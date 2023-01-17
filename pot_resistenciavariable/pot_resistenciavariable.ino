//iniciamos con una variable tipo flotante
int pot = 0;
float voltaje = 0.0;

void setup() {
  //iniciamos
  Serial.begin(9600);
  pinMode(6, OUTPUT); //cambiar el "6" por el puerto donde este el LED
}

void loop() {
  pot = analogRead(A1); //modificar el puerto de entrada
  voltaje = pot * 0.00488; 
  Serial.print(voltaje); //tambien se puede dividir entre 1000
  Serial.println("v"); //esta linea agrega una etiqueta V despues de la cantidad

  pot = pot / 4;
  analogWrite(6, pot); 

  delay(100); //aplicamos un delay para limitar la lectura del valor
}
