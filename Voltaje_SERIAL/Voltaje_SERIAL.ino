int valor = 0;
float voltage = 0;

void setup() {
  //iniciar el monitor serial
  Serial.begin(9600);
}
void loop() {
  //asociar a "valor" lo que retorna la funcion "analogRead"
  valor = analogRead(A1);
  voltage = valor * 0.00488;

  //usar la funcion Serial para mandar a imprimir valor
  Serial.println(valor);
  Serial.println(voltage);

}
