void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Tabla AND ");

  Serial.print("true AND true = ");
  Serial.println(true&&true);
  Serial.print("true AND false = ");
  Serial.println(true&&false);
  Serial.print("false AND true = ");
  Serial.println(false&&true);
  Serial.print("false AND false = ");
  Serial.println(false&&false); 

  Serial.println("Tabla OR ");

  Serial.print("true OR true = ");
  Serial.println(true||true);
  Serial.print("true OR false = ");
  Serial.println(true||false);
  Serial.print("false OR true = ");
  Serial.println(false||true);
  Serial.print("false OR false = ");
  Serial.println(false||false); 
  
  while(true){}//paro
}
