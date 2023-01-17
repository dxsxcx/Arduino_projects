#include <IRremote.h>

int RECV_pin = 11;

IRrecv irrecv(RECV_pin);

decode_results results;


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); //inicia la entrada de IR

}

void loop() {
  if (irrecv.decode(&results)) {
  Serial.println(results.value);
  irrecv.resume(); 
  }

}
