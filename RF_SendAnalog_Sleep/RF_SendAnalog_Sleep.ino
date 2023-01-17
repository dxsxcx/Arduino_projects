#include <JeeLib.h>

int ID = 1;
int buf[5];
PortI2C myI2C(1);
AnalogPlug adc (myI2C, 0x69);


void setup() {

  /*for (int i = 0; i < 20; i++) {
    if(i != 2)//just because the button is hooked up to digital pin 2
    pinMode(i, OUTPUT);
    }
  
  attachInterrupt(0, digitalInterrupt, CHANGE); //interrupt for waking up*/

  rf12_initialize(20, RF12_868MHZ, 212); // init the radio

  Serial.begin(57600);
  if (adc.isPresent())
  Serial.println("Analog Plug found");
  adc.send();
  adc.write(0x8C);
  adc.stop();
}

void loop() {
  adc.select(2);
  delay(500);
  long uvolts = ((adc.reading() >> 8) * 1000) / 64;
  //uvolts = uvolts * 2.1979245839;

  buf[0] = ID;
  buf[1] = (uvolts >> 0) & 0xFF;
  buf[2] = (uvolts >> 8) & 0xFF;
  buf[3] = (uvolts >> 16) & 0xFF;
  buf[4] = (uvolts >> 24) & 0xFF;


  float sentvolts = (float) uvolts / 1000000.0;
  Serial.print (ID);
  Serial.print (", ");
  Serial.println (sentvolts, 6);

  while (!rf12_canSend())     // wait until sending is allowed
  rf12_recvDone();            // processes any incoming data
                              // it all happens "in the background"
  rf12_sendStart(0, buf, sizeof buf);  // sends the data out

/* //Enable Sleep
  SMCR |= (1 << 2); //power down mode
  SMCR |= 1;//enable sleep

   //Disable ADC
  ADCSRA &= ~(1 << 7);

   //BOD Disable
  MCUCR |= (3 << 5); //set both BODS and BODSE at the same time
  MCUCR = (MCUCR & ~(1 << 5)) | (1 << 6); //then set the BODS bit and clear the BODSE bit at the same time
  __asm__  __volatile__("sleep");//in line assembler to go to sleep
}

void digitalInterrupt(){
  //needed for the digital input interrupt
}
*/
