int a = 120;

void setup() {
  Serial.begin(9600);
  Serial.println(a<<3);
  Serial.println(a<<2);
  Serial.println(a<<1);
  Serial.println(a);
  Serial.println(a>>1);
  Serial.println(a>>2);
  Serial.println(a>>3);
  Serial.println(a>>4);
  Serial.println(a>>5);

}

void loop() {
  

}
