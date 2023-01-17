/*El circuito:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin al pin 5
   LCD D5 pin al pin 4
   LCD D6 pin al pin 3
   LCD D7 pin al pin 2
   Potenciomtro al pin 0 digital
   Servo al pin 9
*/

#include <Servo.h> //libreria Servo
#include <LiquidCrystal.h> //libreria LCD

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Iniciando funcion LCD
Servo servo1; //Iniciando funcion servo

//Variables del programa
int pos = 0; //posicion del servo
int pot = 0; //informacion del servo
int grados = 0; //conversion potenciometro-grados

void setup() {
  Serial.begin(9600); //borrar
  lcd.begin(16, 2); //iniciando LCD
  servo1.attach(9);
  lcd.print("Movement Degrees");
}

void loop() {
  pot = analogRead(0);
  Serial.println(pot); //borrar
  grados = map (pot, 0, 1023, 0, 180);

  lcd.setCursor(0, 1);
  lcd.print(grados);
  servo1.write(grados);
  delay(15);
}
