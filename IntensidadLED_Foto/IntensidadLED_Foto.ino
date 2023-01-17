//NOMBRANDO VARIABLES
int Led = 2;
int valor = 0;
double y = 0.0;
int intervalo = 512;

void setup() {
pinMode(Led, OUTPUT);
digitalWrite(Led, LOW);
}

void loop() {
valor = analogRead(1);
y = (900/512)*(valor-512)+100;

intervalo = (int)y;

digitalWrite(Led, HIGH);
delay (y);

digitalWrite(Led, LOW);
delay (y);
}
