#include<LiquidCrystal.h>
LiquidCrystal pantalla(2, 3, 4, 5, 6, 7);
int valor = 0;
float voltage = 0.0;

void setup() {
  Serial.begin(9600);
  pantalla.begin(16, 2);
  pantalla.setCursor(0,0);
  pantalla.print("MADE BY DSC");
  delay(3000);
}

void loop() {
  
  pantalla.clear();
  pantalla.print("Voltimetro");
  pantalla.setCursor(0,1);
  valor = analogRead(0);
  voltage =(float) ((4950/1023)*valor);
  Serial.println(valor);
  Serial.println(voltage);
  pantalla.print(voltage);
  pantalla.print("mV");
  pantalla.print("    DSC");
  delay(1000); 
}
