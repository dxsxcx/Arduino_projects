//Pines de los leds
int const L1 = 2;
int const L2 = 3;
int const L3 = 4;
int const L4 = 5;
int const L5 = 6;
int const L6 = 7;

//sensor
int const analog = 2;

//declarar una variable entera
int valor = 0 ;
int X = 0;

//funcion que prende los leds
void prenderLeds (int a, int b, int c, int d, int e, int f)
{
  digitalWrite (L1, a);
  digitalWrite (L2, b);
  digitalWrite (L3, c);
  digitalWrite (L4, d);
  digitalWrite (L5, e);
  digitalWrite (L6, f);
}

void setup() {
  //consola
  Serial.begin(9600);
  //pines de entrada/salida
  pinMode (L1, OUTPUT);
  pinMode (L2, OUTPUT);
  pinMode (L3, OUTPUT);
  pinMode (L4, OUTPUT);
  pinMode (L5, OUTPUT);
  pinMode (L6, OUTPUT);

}

void loop() {
  //toma valores desd 0 a 1023
  valor = analogRead(analog);
  Serial.println(valor);

  //sensor
  X = (255*valor)/1023;
  if (X>=255){
  X=0;
  }
  
  analogWrite(10, X);
  delay (200);
 
  //valores menores a 170
  if ( valor <= 170)
  {
    //enciende led
    prenderLeds (1, 0, 0, 0, 0, 0);
  }

  // valores entre 170 a 340
  if ( valor > 170 && valor < 340)
  {
    //enciende led
    prenderLeds (1, 1, 0, 0, 0, 0);
  }
  // valores de 340 a 510
  if ( valor > 340 && valor < 510)
  {
    //enciende led
    prenderLeds (1, 1, 1, 0, 0, 0);
  }
  //valores de 510 a 680
  if ( valor > 510 && valor < 680)
  {
    //enciende led
    prenderLeds (1, 1, 1, 1, 0, 0);
  }
  //valores entre 680 a 850
  if ( valor > 680 && valor < 850)
  {
    //enciende led
    prenderLeds (1, 1, 1, 1, 1, 0);
  }
  //valores entre 850 a 1023
  if ( valor > 850 && valor < 1023)
  {
    //enciende led
    prenderLeds (1, 1, 1, 1, 1, 1);
  }
  

}
