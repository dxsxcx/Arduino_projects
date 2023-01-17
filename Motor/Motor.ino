int pinMotor = 9;


void setup() {
  // put your setup code here, to run once:
  pinMode(pinMotor, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  PrenderApagarMotor();
  //PrenderApagarMotorconVelocidad();
  //AcelerarMotor();
}

void PrenderApagarMotor()
{
  int tiempoPrendido = 2500; //Tiempo Prendido
  int tiempoApagado = 1000; //Tiempo Apagado

  digitalWrite(pinMotor, HIGH);
  delay (tiempoPrendido);
  digitalWrite(pinMotor, LOW);
  delay (tiempoApagado);
  
}
