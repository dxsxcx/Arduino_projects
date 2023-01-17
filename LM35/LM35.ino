int val;
void setup()
{
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}
void loop()
{
  val = analogRead(0);
  float mv = ( val / 1024.0) * 5000;
  float cel = mv / 10;
  //float farh = (cel*9)/5 + 32;

  Serial.print("Tempertura = ");
  Serial.print(cel);
  Serial.println("*C");
  delay(1000);

  /* uncomment this to get temperature in farenhite
    Serial.print("TEMPRATURE = ");
    Serial.print(farh);
    Serial.print("*F");
    Serial.println();
  */

  digitalWrite(9, LOW);

  if (cel > 30) 
  {
    digitalWrite(9, HIGH);
  }


}
