//NOMBRANDO VARIABLES
int Led = 2;
int valor = 0;
double y = 0.0;
int intervalo = 512;

void setup() {
pinMode(Led, OUTPUT);
digitalWrite(Led, LOW);
Serial.begin(9600);
}

void loop() {
valor = analogRead(1);
Serial.println(valor);
y = (900/490)*(valor-533)+100;

intervalo = (int)y;

digitalWrite(Led, HIGH);
delay (y);

digitalWrite(Led, LOW);
delay (y);

}

