/* Alfred_Caracterizacion de motores
   El programa realiza una rampa de voltaje
   el objetivo es obtener el valor de voltaje
   en el que los motores tienen la capacidad de
   mover la estructura completa.
   Daniel Santos Calderon
   16 de agosto del 2017
*/
//Puertos de Motor 1
int s1M1 = 5;
int s2M1 = 6;
int pwm1 = 7;

//Puertos de Motor 2
int s1M2 = 4;
int s2M2 = 3;
int pwm2 = 2;
//Valores de control
int rampaInicio, rampaFinal, retraso;

void setup() {
  pinMode(s1M1, OUTPUT);
  pinMode(s2M1, OUTPUT);
  pinMode(s1M2, OUTPUT);
  pinMode(s2M2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);

  Serial.begin(9600);
}

void detenerse() {

  if (Serial.available() == 1) {
    Serial.println("Stop de seguridad");
    analogWrite(pwm1, 0);
    analogWrite(pwm2, 0);
    digitalWrite(s1M1, LOW);
    digitalWrite(s2M1, LOW);
    digitalWrite(s1M2, LOW);
    digitalWrite(s2M2, LOW);
    delay(100);
    while (true);
  }
}

void loop() {


    rampaInicio = 10;
    rampaFinal = 255;
    retraso = 100;

    //rectificar datos
    rampaInicio = constrain(rampaInicio, 0, 255);
    rampaFinal = constrain(rampaFinal, 0, 255);

    /*Incia la rampa en el valor de inicio */
    for (int i = rampaInicio; i <= rampaFinal; i++) {
      detenerse();
      digitalWrite(s2M1, HIGH);
      digitalWrite(s2M2, HIGH);
      analogWrite(pwm1, i);
      analogWrite(pwm2, i);
      Serial.println(i);
      delay (retraso);
    }

    //Fin de la rampa
    for (int i = rampaFinal; i >= rampaInicio; i--) {
      detenerse();
      digitalWrite(s2M1, HIGH);
      digitalWrite(s2M2, HIGH);
      analogWrite(pwm1, i);
      analogWrite(pwm2, i);
      Serial.println(i);
      delay (retraso);
    }

    //detener motores
    digitalWrite(s1M1, LOW);
    digitalWrite(s2M1, LOW);
    digitalWrite(s1M2, LOW);
    digitalWrite(s2M2, LOW);
    delay(1000);
}
