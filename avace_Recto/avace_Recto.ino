#include <Servo.h>

Servo MotorIzq;
Servo MotorDer;
int pos = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  MotorIzq.attach(9);
  MotorDer.attach(11);
  MotorIzq.writeMicroseconds(1500);
  MotorDer.writeMicroseconds(1500);
}

void loop() {

  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

  for (pos = 0; pos < 200; pos += 10)
  {
    MotorIzq.writeMicroseconds(1400 + pos);
    MotorDer.writeMicroseconds(1500 - pos);
    delay(20);
  }

  delay (2000);

  for (pos = 0; pos < 200; pos += 10)
  {
    MotorIzq.writeMicroseconds(1700 - pos);
    MotorDer.writeMicroseconds(1300 + pos);
    delay(20);
  }

  MotorIzq.writeMicroseconds(1500);
  MotorDer.writeMicroseconds(1500);

  while (true) {};

}
