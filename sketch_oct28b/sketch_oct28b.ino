//nombrar variables
  long randNumber;
  
void setup() {
  //Modos de los pines
  pinMode (12, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (9, OUTPUT);
  
  //Scope
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  randNumber = random(9,12);
  digitalWrite(randNumber,LOW);
  delay(1000);
  digitalWrite(randNumber,HIGH);
  delay(1000);

}
