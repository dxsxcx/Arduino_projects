int pot = 0;
int b = 2;
int g = 3;
int y = 4;
int o = 5;
int r = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(b, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(o, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot = analogRead(A0);
  Serial.println(pot);
  if (pot <= 20)
  {
    pot=20;
    }

  digitalWrite(b, HIGH);
  delay (pot);
  digitalWrite(b, LOW);
  delay (pot);

  pot = analogRead(A0);
  Serial.println(pot);
  if (pot <= 20)
  {
    pot=20;
    }

  digitalWrite(g, HIGH);
  delay (pot);
  digitalWrite(g, LOW);
  delay (pot);

  pot = analogRead(A0);
  Serial.println(pot);
  if (pot <= 20)
  {
    pot=20;
    }

  digitalWrite(y, HIGH);
  delay (pot);
  digitalWrite(y, LOW);
  delay (pot);

  pot = analogRead(A0);
  Serial.println(pot);
  if (pot <= 20)
  {
    pot=20;
    }

  digitalWrite(o, HIGH);
  delay (pot);
  digitalWrite(o, LOW);
  delay (pot);

  pot = analogRead(A0);
  Serial.println(pot);
  if (pot <= 20)
  {
    pot=20;    
    }
  

  digitalWrite(r, HIGH);
  delay (pot);
  digitalWrite(r, LOW);
  delay (pot);
  
}
