#include <LiquidCrystal.h>
LiquidCrystal pantalLCD(12, 11, 5, 4, 3, 2);
//(rs, enable, d4, d5, d6 y d7)

void setup{
  Serial.begin(9600);
  pantallaLCD.begin(16, 2);
}

void loop{
  if (Serial.available() > 0)
  {
    delay(100);
    pantallaLCD.clear();
    while (Serial.available() > 0)
    {
      pantallaLCD.write(Serial.read());
    }
  }
}

