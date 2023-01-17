//nombramos los puertos segun la luz
//Semaforo B
int RB = 5;
int AB = 6;
int VB = 7;

//semaforo A
int RA = 8;
int AA = 9;
int VA = 10;

void setup() {
//Luces como salidas

//Semaforo B
pinMode(RB, OUTPUT);
pinMode(AB, OUTPUT);
pinMode(VB, OUTPUT);

//Semaforo A
pinMode(RA, OUTPUT);
pinMode(AA, OUTPUT);
pinMode(VA, OUTPUT);
}

void loop() {
//SEMAFORO A DEJA PASAR AUTOS - enciendes verde A, enciendes rojo B
digitalWrite(AB, LOW);
digitalWrite(RA, LOW);
digitalWrite(VA, HIGH);
digitalWrite(RB, HIGH);
delay (1000);


//TIEMPO DE CAMBIO - apagas verde A, enciendes amarillo A
digitalWrite(VA, LOW);
digitalWrite(AA, HIGH);
delay (1000);
digitalWrite(AA, LOW);
delay (100);
digitalWrite(AA, HIGH);
delay (100);
digitalWrite(AA, LOW);
delay (100);
digitalWrite(AA, HIGH);
delay (100);
digitalWrite(AA, LOW);
delay (100);
digitalWrite(AA, HIGH);
delay (100);

//SEMAFORO B DEJA PASAR AUTOS - apagas amarillo A, apagas rojo B, enciendes rojo A, Enciendes verde B
digitalWrite(AA, LOW);
digitalWrite(RB, LOW);
digitalWrite(RA, HIGH);
digitalWrite(VB, HIGH);
delay (1000);

//TIEMPO DE CAMBIO - apaga verde B, enciende amarillo B
digitalWrite(VB, LOW);
digitalWrite(AB, HIGH);
delay (1000);
digitalWrite(AB, HIGH);
delay (100);
digitalWrite(AB, LOW);
delay (100);
digitalWrite(AB, HIGH);
delay (100);
digitalWrite(AB, LOW);
delay (100);
digitalWrite(AB, HIGH);
delay (100);
digitalWrite(AB, LOW);
delay (100);
digitalWrite(AB, HIGH);
delay (1000);

}
