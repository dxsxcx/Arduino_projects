#include <Ultrasonic.h>

Ultrasonic sensorU(2, 3); //trigger(10), echo(11)
double distancia = 0; //se toma la variable en una double con valor 0 inicial

int IN1 = 6; //entrada de los motores
int IN2 = 7; //entrada de los motores
int IN3 = 4; //entrada de la direccion
int IN4 = 5; //entrada de ldireccion
int pwm = 9;

void setup() {
  pinMode(IN1, OUTPUT);//INT1
  pinMode(IN2, OUTPUT);//INT2
  pinMode(IN3, OUTPUT);//INT3
  pinMode(IN4, OUTPUT);//INT$
  pinMode(pwm, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  distancia = sensorU.Ranging(CM);  //se obtiene la distancia en centimetros

  //el auto corre
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (IN1, 255);

  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);

  Serial.println("4500");

  if (distancia >= 10) {
    //reportamos a la consola en labview que el vehiculo bajo de velocidad
    analogWrite (pwm, 100);
    Serial.println("2000");


    //el vehiculo hace la maniobra
    digitalWrite (IN3, HIGH);
    digitalWrite (IN4, LOW);
    delay (100);
    digitalWrite (IN3, LOW);
    digitalWrite (IN4, LOW);
    delay(1000);

    //el vehiculo regresa al carril (enviamos informacion a la consola)
    Serial.println(2);

    //el vehiculo hace la maniobra y sube la velocidad otra vez
    digitalWrite (IN3, LOW);
    digitalWrite (IN4, HIGH);

    analogWrite (pwm, 255);
    Serial.println("4500");
  }

  if (distancia <= 10) {
    //reportamos a la consola en labview que el vehiculo se va a detener
    Serial.println("100");

    analogWrite(pwm, 0);

    digitalWrite (IN1, LOW);
    digitalWrite (IN2, LOW);
    digitalWrite (IN3, LOW);
    digitalWrite (IN4, LOW);
  }
}
