#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

MPU6050 IMU;

int16_t ax, ay, az;
int16_t gx, gy, gz;

//Compensaciones
#define desplazGiro 0  //Desplazamiento inicial del giro
#define desplazAngulo -2.12  // Desplazamiento inicial del ángulo
#define compenMotorD 0  // Compensación para el motor derecho
#define compenMotorI 0  // Compensación para el motor izquierdo
#define gananciaGiro 131
#define pi 3.14159

float anguloY, anguloPrevY;
float dt;
unsigned long tiempoPrev, ultimoTiempo;
int tiempoTranscurrido;

float kp, ki, kd; //parámetros del PID

float velGiro = 0;
float salidaI, salidaD, Salida;



float sumaErrores, dErr, error, ultimoError;

// Definición d epines del controlador de motores (Cambiar pines)
int TN1 = 2; //Pin 2
int TN2 = 3; //Pin 3
int ENA = 4; //Pin 4
int TN3 = 6; //Pin 6
int TN4 = 7; //Pin 7
int ENB = 5; //Pin 5


void setup()
{
  Wire.begin();
  //Serial.begin(115200);
  //Configura PWM rápido mediante las etiquetas del micro definidas en AVR

  TCCR3A = _BV(COM3A1) | _BV(WGM31) | _BV(WGM30); // TIMER_3 @1KHz, pwm rápido
  TCCR3B = _BV(CS31);
  TCCR0A = _BV(COM0B1) | _BV(WGM01) | _BV(WGM00); // TIMER_0 @1KHz, pwm rápido
  TCCR0B = _BV(CS01) | _BV(CS00);

  /* Si el robot es encendido con un ángulo mayor a 30 o -30 grados,las ruedas no se moverán
    hasta que el robot esté en un aposición correcta.*/

  IMU.initialize();
  for (int i = 0; i < 200; i++) // Cicla 200 veces para obtener la postura inicial
  {
    filtradoComplementario();
  }
/*
  Serial.println("Ya termine!");
  Serial.println(anguloY);*/

  if (abs(anguloY) < 30)  // Inicia a trabajar despues de limpiar datos
  {
    Salida = error = sumaErrores = dErr = 0;
    filtradoComplementario();
    controlPID();
  }
  pinMode(TN1, OUTPUT); // configuración de pines para controlador de motores
  pinMode(TN2, OUTPUT);
  pinMode(TN3, OUTPUT);
  pinMode(TN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

}

void loop()
{
  filtradoComplementario(); // promedia el ángulo medido para obtener un valor más estable
  if ((micros() - ultimoTiempo) > 10000)
  {
    // Si el angulo es > 30 or < -30 entonces el robot se detiene
    if (abs(anguloY) < 30)
    {
      controlPID(); // Calcula salida en base a errores PID
      controlPWM(); // Controla motores con el dato de salida

      /*Serial.print("\t angulo:");
      Serial.print(anguloY);
      Serial.print("\t valor kp:");
      Serial.print(kp);
      Serial.print("\t valor ki:");
      Serial.print(ki);
      Serial.print("\t valor kd:");
      Serial.println(kd);*/
    }
    else
    {
      digitalWrite(TN1, HIGH); //amarra los motores
      digitalWrite(TN2, HIGH);
      digitalWrite(TN3, HIGH);
      digitalWrite(TN4, HIGH);
    }
    ultimoTiempo = micros();
  }
}

void filtradoComplementario()
{
  // Obtiene datos medidos del IMU
  IMU.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Calcula angulo Y con aceleraciones del IMU
  float anguloY_IMU = atan(-ax / sqrt(pow(ay, 2) + pow(az, 2))) * (180.0 / pi);

  // Calcula el tiempo transcurrido entre mediciones
  unsigned long ahora = micros();
  tiempoTranscurrido = ahora - tiempoPrev;
  dt = tiempoTranscurrido * 0.000001; // Convierte a segundos
  tiempoPrev = ahora;

  // Calcula angulo Y integrando mediciones del giroscopio y filtrado complementario

  anguloY = 0.98 * (anguloPrevY + ((gy - desplazGiro) / gananciaGiro) * dt) + 0.02 * anguloY_IMU;

  anguloPrevY = anguloY;
}

void controlPID()
{
  kp = analogRead(A0) / 10.0; //26.000
  ki = analogRead(A1) / 10.0; //0
  kd = analogRead(A2) / 10.0; //2.6

  // Calcula los valores de cada componente PID usando los valores de gestura.
  error = anguloY - desplazAngulo;
  sumaErrores += error;
  dErr = error - ultimoError;

  // Calcula salida en base a control PID
  Salida = kp * error + ki * sumaErrores + kd * dErr; // dErr puede sustituirse por gy/131
  ultimoError = error;


  // Calcula salidas para cada rueda
  salidaD = Salida + velGiro;
  salidaI = Salida - velGiro;

}

void controlPWM()
{
  if (salidaI > 0)
  {
    digitalWrite(TN1, HIGH);
    digitalWrite(TN2, LOW);
  }
  else if (salidaI < 0)
  {
    digitalWrite(TN1, LOW);
    digitalWrite(TN2, HIGH);
  }
  else
  {
    OCR3A = 0;
  }
  if (salidaD > 0)
  {
    digitalWrite(TN3, HIGH);
    digitalWrite(TN4, LOW);
  }
  else if (salidaD < 0)
  {
    digitalWrite(TN3, LOW);
    digitalWrite(TN4, HIGH);
  }
  else
  {
    OCR0B = 0;
  }
  OCR3A = min(1023, (abs(salidaI * 4) + compenMotorI * 4)); // Timer/Counter3 es un temporizador/contador de propósito general de 16 bits
  OCR0B = min(255, (abs(salidaD) + compenMotorD)); // Timer/Counter0 es un módulo temporizador/contador de 8 bits

  /*Serial.print("OCR3A:");
  Serial.print(OCR3A);
  Serial.print("\t OCR0B:");
  Serial.print(OCR0B);*/

}



