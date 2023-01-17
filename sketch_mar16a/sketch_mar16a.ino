int a=2;
int b=3;
int c=4;
int d=5;
int e=6;
int f=7;
int g=8;

int sensor=9;
int numero=0;

void setup() {
  for(int i=2; i<9;i++)
  {
pinMode(i,OUTPUT);
digitalWrite(1,HIGH);
    
  }
pinMode(12,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(sensor))
{
numero=random(0,9);
}

switch(numero)




}
