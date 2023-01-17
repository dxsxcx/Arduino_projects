char valor;
String Name ;
String ref = "CARLOS";

void setup() {
  Serial.begin(9600);
}

void loop() {

  if (Serial.available()) {
    valor = Serial.read();
    Name += valor;

    if (valor == '\n') {
      Name.toUpperCase();
      Serial.print(Name);
      if (Name.indexOf(ref.charAt(0))>-1|| Name.indexOf(ref.charAt(1))>-1 || Name.indexOf(ref.charAt(2))>-1|| Name.indexOf(ref.charAt(3))>-1|| Name.indexOf(ref.charAt(4))>-1|| Name.indexOf(ref.charAt(5))>-1){
        Serial.println("El nombre contiene una letra de carlos");
      }
      else {
        Serial.println("El nombre NO contiene una letra de carlos");
      }
      Name ="";
    }
  }
}
