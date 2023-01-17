/* 
 Ejemplo de control de motor DC usando modulo L298
 http://electronilab.co/tienda/driver-dual-para-motores-full-bridge-l298n/
 
 El programa activa el motor en un sentido por 4 segundos, 
 para el motor por 500 ms, activa el motor en sentido inverso por 4 segundos 
 y se detiene por 5 segundos. Luego repite la acción indefinidamente.
 
 Creado 16/05/14
 por Andres Cruz
 ELECTRONILAB.CO
 */
 
//derecha
int IN3 = 5; 
int IN4 = 4;
//izquierda
int IN1 = 7; 
int IN2 = 6;

void setup()
{
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin 4 
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin 5
  pinMode (IN1, OUTPUT);    // Input1 conectada al pin 7 
  pinMode (IN2, OUTPUT);    // Input2 conectada al pin 6
}
void loop()
{
  // Motor der gira en un sentido
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW); 
  delay(4000);
  // Motor der no gira
  digitalWrite (IN4, LOW); 
  delay(500);
  // Motor der gira en sentido inverso
  digitalWrite (IN3, HIGH);
  delay(4000);
  // Motor der no gira
  digitalWrite (IN3, LOW); 
  delay(5000);

  // Motor izq gira en un sentido
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); 
  delay(4000);
  // Motor izq no gira
  digitalWrite (IN1, LOW); 
  delay(500);
  // Motor izq gira en sentido inverso
  digitalWrite (IN2, HIGH);
  delay(4000);
  // Motor izq no gira
  digitalWrite (IN2, LOW); 
  delay(5000);
}
