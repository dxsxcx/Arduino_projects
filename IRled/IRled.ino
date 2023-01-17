#include <IRremote.h>

int RECV_pin = 11;
IRrecv irrecv(RECV_pin);
decode_results results;
String peticion;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); //inicia la entrada de IR

  pinMode(7, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    peticion = results.value;
    irrecv.resume();
  }

  if (peticion == "16761405") {
    digitalWrite(7, HIGH);
  }
  else {
    digitalWrite(7, LOW);
  }
}


