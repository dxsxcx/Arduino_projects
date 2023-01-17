#include <Servo.h>

Servo MotorIzq;
//Servo MotorDer;
int pos = 0;
int Pot = 0;

void setup() {
  MotorIzq.attach(9);
  //MotorDer.attach(0);
}

void loop() {

  Pot = analogRead (5);

  while (Pot >= 512) {
    Pot = analogRead (5);

    for (pos = 1000; pos < 2000; pos += 10)
    {
      MotorIzq.writeMicroseconds(pos);
      delay(200);
    }

    Pot = analogRead (5);

    for (pos = 2000; pos >= 1000; pos -= 50)
    {
      MotorIzq.writeMicroseconds(pos);
      delay(200);
    }

    Pot = analogRead (5);
  }
}
