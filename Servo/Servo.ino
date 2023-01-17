#include <Servo.h>

Servo servo1;
int pos = 0;

void setup()
{
  servo1.attach(4);
  servo1.write(0);
  
}

void loop() {

  for (pos = 10; pos < 90; pos += 1)
  {
    servo1.write(pos);
    delay(50);
  }

  for (pos = 90; pos >= 10; pos -= 1)
  {
    servo1.write(pos);
    delay(50);
  }

}
