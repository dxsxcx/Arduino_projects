#include <Stepper.h> //Librería Stepper

/*se establece los pines de operación 
*Pines 9,11,10,12 son las conexiones con el controlador
*200 son los pasos por revolución.
*/
Stepper motor(200, 9, 11, 10, 12); 


void setup() {
  
  motor.setSpeed(60); //establecemos la velocidad como 60 revoluciones por minuto
  Serial.begin(9600); 
  
}
void loop() {

  Serial.println("sentido del reloj"); 
  motor.step(1000); //El motor gira 1000 pasos en sentido horario.
  delay(500); 

  Serial.println("sentido contrario del reloj"); 
  motor.step(-1000); //El motor girara en el sentido contrario
  delay(500);
}
