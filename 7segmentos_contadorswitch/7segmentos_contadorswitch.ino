//declarar las variables con nombres de los pines
int a = 4;
int b = 5;
int c = 6;
int d = 7;
int e = 8;
int f = 9;
int g = 10;
int pt = 11;

//esta variable almacenara el contador
int contador = 0;

void setup() {
  //declarar todos los pines como salida
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(pt, OUTPUT); //punto

  /*declarar los pines como HIGH
     para no encender el display

  */
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(pt, HIGH);

}

void loop() {
  /* Esta linea es para utilizar un boton
    Boton = digitalRead(push);
    if (Boton == 1)
    {
    contador = contador + 1;
    }*/

  //creamos estructura switch
  switch (contador) {//inicia switch
    case 0:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      digitalWrite(pt, HIGH);
      break;

    case 1:
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(pt, HIGH);
      break;

    case 2:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(pt, HIGH);
      break;

    case 3:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(pt, HIGH);
      break;

    case 4:
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      digitalWrite(pt, HIGH);
      break;

    case 5:
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      digitalWrite(pt, HIGH);
      break;

    case 6:
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      digitalWrite(pt, HIGH);
      break;

    case 7:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(pt, HIGH);
      break;

    case 8:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      digitalWrite(pt, HIGH);
      break;

    case 9:
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      digitalWrite(pt, HIGH);
      break;
  }
  /*
    //linea final
    contador = contador + 1;
    delay(1000);

    //esta linea resetea el codigo
    if (contador == 10) {
    contador = 0;
    digitalWrite(pt, LOW);//enciende el punto:)
    }*/
  int retroceso = 1;

  //Conteo de 0 a 9
  if (retroceso == 1) //primer vuelta
  { contador = contador + 1; //aumenta de 1 en 1
    delay(1000);
    if (contador == 10) //cambiamos el 10 dependiendo el numero de casos
    { //cambiamos el orden
      contador = 9; //cambiamos el 9 dependiendo el numero de casos
      retroceso = 2; //conteo de regreso
    }
  }   if (retroceso == 2) //como la condicion no se cumplio se inicia retroceso
  { contador = contador - 1;
    delay(1000);
    if (contador == 0)
    { retroceso = 1;
      contador = 0 ;
    }
  }




}
