#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

MPU6050 IMU;
// MPU6050 initialize; Esta linea convoca a la función inicializar
int16_t ax, ay, az;
int16_t gx, gy, gz;

//Compensaciones
#define desplazGiro 0  //Desplazamiento inicial del giro
#define desplazAngulo 2.5  // Desplazamiento inicial del ángulo
#define compenMotorD 0  // Compensación para el motor derecho
#define compenMotorI 0  // Compensación para el motor izquierdo
#define gananciaGiro 131
#define pi 3.14159

float dA, anguloRecursivo, anguloEsperado;

float kp, ki, kd; //parámetros del PID
float anguloSensor, anguloFiltrado, omega, dt;
float velGiro = 0, velDesplazamiento = 0;
float salidaI, salidaD, Entrada, Salida;

unsigned long tiempoPrev, ultimoTiempo;
float sumaErrores, dErr, error, ultimoError;
int tiempoTranscurrido;

float sumaD, sumaDTemp, sumaI, sumaITemp, distancia, distanciaD, distanciaI, velocidad;

int TN1 = 3; //Pin 2
int TN2 = 2; //Pin 3
int ENA = 4; //Pin 4
int TN3 = 7; //Pin 6
int TN4 = 6; //Pin 7
int ENB = 5; //Pin 5


void setup()
{
  Serial.begin(115200);
  Wire.begin();

  TCCR3A = _BV(COM3A1) | _BV(WGM31) | _BV(WGM30); // TIMER_3 @1K Hz, pwm rápido
  TCCR3B = _BV(CS31);
  TCCR0A = _BV(COM0B1) | _BV(WGM01) | _BV(WGM00); // TIMER_0 @1K Hz, pwm rápido
  TCCR0B = _BV(CS01) | _BV(CS00);

  /* Si el robot es encendido con un ángulo mayor a 30 o -30 grados,las ruedas no se moverán
    hasta que el robot esté en un aposición correcta.*/

  IMU.initialize();
  for (int i = 0; i < 200; i++) // Cicla 200 veces para obtener la postura inicial
  {
    Firtrar();
  }
  if (abs(anguloFiltrado) < 30)  // Inicia a trabajar despues de limpiar datos
  {
    omega = anguloSensor = anguloFiltrado = 0;
    Salida = error = sumaErrores = dErr = 0;
    Firtrar();
    myPID();
  }
  pinMode(TN1, OUTPUT); // configuración de pines para controlador de motores
  pinMode(TN2, OUTPUT);
  pinMode(TN3, OUTPUT);
  pinMode(TN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  // pinMode(18,INPUT);
  // pinMode(2, INPUT);

  // attachInterrupt(4, encoderA, FALLING);
  // attachInterrupt(1, encoderB, FALLING);
}

void loop()
{
  while (1)
  {
    Firtrar(); // promedia el ángulo medido para obtener un valor más estable
    if ((micros() - ultimoTiempo) > 10000)
    {
      // Si el angulo es > 30 or < -30 entonces el robot se detiene
      if (abs(anguloFiltrado) < 30)
      {
        myPID();
        PWMControl();
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

  Serial.print("\t valor kp:");
  Serial.print(kp);
  Serial.print("\t valor ki:");
  Serial.print(ki);
  Serial.print("\t valor kd:");
  Serial.println(kd);

}

void Firtrar()
{
  // Datos medidos
  IMU.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  anguloSensor = (atan2(ax, az) * 180 / pi + desplazAngulo);
  omega = gy / gananciaGiro + desplazGiro;
  // Firtrar datos para obtener la posición real
  unsigned long ahora = micros();
  tiempoTranscurrido = ahora - tiempoPrev;
  tiempoPrev = ahora;
  dt = tiempoTranscurrido * 0.000001;
  dA = (anguloSensor - anguloFiltrado) * 0.64;
  anguloRecursivo = dA * dt + anguloRecursivo;
  anguloEsperado = anguloRecursivo + (anguloSensor - anguloFiltrado) * 1.6 + omega;
  anguloFiltrado = anguloEsperado * dt + anguloFiltrado;
  Serial.println(anguloFiltrado);
}

void myPID()
{
  kp = analogRead(A0) / 10.0; //26.000
  ki = analogRead(A1) / 10.0; //0
  kd = analogRead(A2) / 10.0; //2.6

  // Calculando los valores de salida usando los valores de gestura y los valores del PID.
  error = anguloFiltrado;
  sumaErrores += error;
  dErr = error - ultimoError;
  Salida = kp * error + ki * sumaErrores + kd * omega;
  ultimoError = error;
  // noInterrupts();
  sumaD = (sumaD + sumaDTemp) / 2;
  sumaI = (sumaI + sumaITemp) / 2;
  velocidad = (sumaD + sumaI) / 2;
  distancia += velocidad + velDesplazamiento;
  distancia = constrain(distancia, -300, 300);
  Salida += velocidad * 70 + distancia * 0.6;
  sumaDTemp = sumaD;
  sumaITemp = sumaI;
  sumaD = 0;
  sumaI = 0;
  salidaD = Salida + velGiro;
  salidaI = Salida - velGiro;
  // interrupts();
}

void PWMControl()
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


}


