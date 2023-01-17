//declaramos variables
int ldr = 0;
int valor = 0;

void setup() {
  Serial.begin(9600);
  pinMode(10 , OUTPUT);
}

void loop() {
  ldr = analogRead(A0);
  Serial.println(ldr);
  /*acaba la primer fase del codigo,
     se debe tomar lectura del sensor y determinar un rango
     despues remplazar el valor medio en la variable valor
  */
  valor = 500;
  if (ldr <= valor) {
    digitalWrite (10, HIGH);
  } else {
    digitalWrite (10, LOW);
  }

}
