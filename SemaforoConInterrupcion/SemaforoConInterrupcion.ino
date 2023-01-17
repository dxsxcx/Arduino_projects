/*
  En este codigo instrumentaremos un semaforo y semaforo de peaton
  cuando presionemos un boton el semaforo detendra el paso vehicular
  para darle paso a los peatones.
  el comportamiento del semaforo sera:
  -El color Verde encendera 1 segundo
  -El color Amarillo encendera 1 segundo
  -El color Amarillo parpaderara 3 veces
  -el color Rojo durara 1 segundo
  Si el sistema detecta que una interrupcion
  -el semaforo se volvera rojo
  -el semaforo de peaton pasara de rojo a verde
  por Daniel Santos
*/

/*primero instrumentamos las variables globales del semaforo
  para especificar las conexiones de los pines
*/

int amarilloSemaforo = 9;
int rojoSemaforo = 8;
int verdeSemaforo = 10;

int rojoPeaton = 12;
int verdePeaton = 11;

int push = 7;

//esta variable nos servira para comprobar el estado del push
int boton = 0;

void setup() {
  // en esta seccion declararemos los pines como I/O

  pinMode(amarilloSemaforo, OUTPUT);
  pinMode(rojoSemaforo, OUTPUT);
  pinMode(verdeSemaforo, OUTPUT);

  pinMode(verdePeaton, OUTPUT);
  pinMode(rojoPeaton, OUTPUT);

  pinMode(push, INPUT_PULLUP); //Incluir el INPUT_PULLUP

}

void loop() {

  //Esta linea encendera el color verde del semaforo
  digitalWrite(verdeSemaforo, HIGH);

  //esta linea dara lectura del push
  boton = digitalRead(push);

  //establecemos un condicion
  if (boton != 0) {
    //si el push no es precionado el semaforo prosigue con su logica.

    digitalWrite(rojoPeaton, HIGH);
    boton = digitalRead(push);
    delay(1000);
  }

  else {
    //si el push es precionado, el semaforo detiene el trafico y los peatones avanzan
    digitalWrite(rojoPeaton, LOW);
    digitalWrite(verdeSemaforo, LOW);
    digitalWrite(rojoSemaforo, HIGH);
    digitalWrite(verdePeaton, HIGH);
    delay(1000);
    digitalWrite(verdeSemaforo, HIGH);
    digitalWrite(rojoSemaforo, LOW);
    digitalWrite(verdePeaton, LOW);
    digitalWrite(rojoPeaton, HIGH);
  }

  digitalWrite(verdeSemaforo, LOW);
  digitalWrite(amarilloSemaforo, HIGH);
  boton = digitalRead(push);

  if (boton != 0) {
    digitalWrite(rojoPeaton, HIGH);
    boton = digitalRead(push);
    delay(1000);
  } else {
    digitalWrite(amarilloSemaforo, LOW);
    digitalWrite(rojoSemaforo, HIGH);
    digitalWrite(rojoPeaton, LOW);
    digitalWrite(verdePeaton, HIGH);
    delay(1000);
    digitalWrite(verdeSemaforo, HIGH);
    digitalWrite(rojoSemaforo, LOW);
    digitalWrite(verdePeaton, LOW);
    digitalWrite(rojoPeaton, HIGH);
    delay(1000);
  }

  digitalWrite(verdeSemaforo, LOW);
  digitalWrite(amarilloSemaforo, HIGH);
  delay(1000);

  digitalWrite(amarilloSemaforo, LOW);
  digitalWrite(rojoSemaforo, HIGH);
  digitalWrite(rojoPeaton, LOW);
  digitalWrite(verdePeaton, HIGH);
  delay(1000);
  digitalWrite(verdePeaton, LOW);


  digitalWrite(rojoSemaforo, LOW);
}
