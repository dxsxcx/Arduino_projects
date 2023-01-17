int a = 120;
int b = 80;

void setup() {
  Serial.begin(9600);
  Serial.print("a= ");
  Serial.println(a);
  Serial.print("b= ");
  Serial.println(b);
  Serial.print("AND= ");
  Serial.println(a&b);
  Serial.print("OR= ");
  Serial.println(a|b);
  Serial.print("XOR= ");
  Serial.println(a^b);
  Serial.print("Suma= ");
  Serial.println(a+b);
  Serial.print("Resta= ");
  Serial.println(a-b);
  Serial.print("NOT(a)= ");
  Serial.println(~a);
  Serial.print("NOT(b)= ");
  Serial.println(~b);
  

}

void loop() {
  

}
