char num [] = {B00111000, 66, '8', 57, 58,};
char hola[4] = {'H', 'O', 'L', 'A'};
char mundo[5] = {'M', 'U', 'N', 'D' , 'O'};
char hm[10];
char dato[5];

void setup() {
  Serial.begin(9600);
  /*hm[0] = hola[0];
  hm[1] = hola[1];
  hm[2] = hola[2];
  hm[3] = hola[3];
  hm[4] = 32;
  hm[5] = mundo[0];
  hm[6] = mundo[1];
  hm[7] = mundo[2];
  hm[8] = mundo[3];
  hm[9] = mundo[4];*/

  Serial.println( num [0]);
  Serial.println( num [3]);

  hm[4] = 32;
  for (int i = 0; i < 5; i++ ) {   
    hm[i+5] = mundo[i];
  }
  for (int i = 0; i < 4; i++ ) {
    hm[i] = hola[i];
  }
   Serial.println( hm );
}

void loop() {
  /*Serial.println("inserte dato");
    char datos = Serial.read();
    for*/
}
