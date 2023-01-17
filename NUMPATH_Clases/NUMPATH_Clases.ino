//salida del potenciometro
int salida = 0;

//display de 7 seg
int A = 7;
int B = 6;
int C = 3;
int D = 4;
int E = 5;
int G = 9;
int F = 8;

void segmentoSiete (int a, int b, int c, int d, int e, int g, int f)
{
  digitalWrite (A, a);
  digitalWrite (B, b);
  digitalWrite (C, c);
  digitalWrite (D, d);
  digitalWrite (E, e);
  digitalWrite (G, g);
  digitalWrite (F, f);
}
//NOTA: NO USAR NUMEROS COMO NOMBRES DE LOS PARAMETROS EN LAS FUNCIONES

//Serie de leds
int O = 2;
int Y = 13;
int R = 12;
int V = 11;
int AZ = 10;

//Inicia digitalWrite para serie de leds
void serieLeds (int h, int i, int j, int k, int l)
{
  digitalWrite (O, h);
  digitalWrite (Y, i);
  digitalWrite (R, j);
  digitalWrite (V, k);
  digitalWrite (AZ, l);
}

void setup() {
  //Declaramos consola
  Serial.begin(9600);

  //Declarar pines para Leds
  pinMode(O, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(V, OUTPUT);
  pinMode(AZ, OUTPUT);

  //Declarar pines para el display de 7 segmentoSietes
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

}

void loop() {

  //lectura del puerto analogico donde esta el potenciometro
  salida = analogRead(5);
  Serial.println(salida);

  //condicion para encencer leds y display

  if (salida >= 0 && salida < 50)
  {
    serieLeds(0, 0, 0, 0, 0);
    segmentoSiete(0, 0, 0, 0, 0, 1, 0);
  }
  if (salida >= 51 && salida < 204)
  {
    serieLeds(1, 0, 0, 0, 0);
    segmentoSiete(1, 0, 0, 1, 1, 1, 1);
  }
  if (salida >= 205 && salida < 409)
  {
    serieLeds(1, 1, 0, 0, 0);
    segmentoSiete(0, 0, 1, 0, 0, 0, 1);
  }
  if (salida >= 410 && salida < 613)
  {
    serieLeds(1, 1, 1, 0, 0);
    segmentoSiete(0, 0, 0, 0, 1, 0, 1);
  }
  if (salida >= 614 && salida < 817)
  {
    serieLeds(1, 1, 1, 1, 0);
    segmentoSiete(1, 0, 0, 1, 1, 0, 0);
  }
  if (salida >= 818 && salida < 1021)
  {
    serieLeds(1, 1, 1, 1, 1);
    segmentoSiete(0, 1, 0, 0, 1, 0, 0);
  }

}


