#include <JeeLib.h>
#include <SD.h>
#include <Wire.h>
#include <RTClib.h>

int ID;
int CS = 4;
File dataFile;
RTC_DS3231 RTC;

void setup() {
  Serial.begin(57600);
  Wire.begin();
  RTC.begin();
  //RTC.adjust(DateTime(__DATE__,__TIME__ ));
  Serial.println("Formato de fecha: DD/MM/AAAA");
  Serial.println("Iniciando Lectura de Micro SD");
  pinMode(CS, OUTPUT);
  if (!SD.begin(CS)) {
    Serial.println("No se Detecta la tarjeta");
    return;
  }
  Serial.println("Listo para grabar");
  rf12_initialize(18, RF12_868MHZ, 212); // parameters are byte nodeId, byte freqBand, byte netGroup
  // freqBands  should be RF12_915MHZ, or RF12_433MHZ
  // nodeId parameter should be in range of to 1-26
  // netGroup parameter should be in range of to 1-212
  // red dots on radios are 915Mhz, green dots are 434 Mhz

  Serial.println("[SimpleReceive]");
}

void loop() {
  if (rf12_recvDone() && rf12_crc == 0) {  // received good data if true
    // rf12_recvDone() is true if new information has been received.
    // re12_crc == 0 indicates good transmission, checks validity of data

    int* buf = (int*) rf12_data;
    // buf is a pointer to our data, the same as an array name

    long uvolts = buf[4];
    uvolts = (uvolts << 8) | buf[3];
    uvolts = (uvolts << 8) | buf[2];
    uvolts = (uvolts << 8) | buf[1];
    ID = buf[0];

    DateTime now = RTC.now();
    float volts = (float) uvolts / 1000000.0;
    Serial.print (ID);
    Serial.print (", ");
    Serial.print (volts, 6);
    Serial.print (", ");
    Serial.print (now.hour(),DEC);
    Serial.print (":");
    Serial.print (now.minute(),DEC);
    Serial.print (":");
    Serial.print (now.second(),DEC);
    Serial.print (", ");
    Serial.print (now.day(),DEC);
    Serial.print ("/");
    Serial.print (now.month(),DEC);
    Serial.print ("/");
    Serial.println (now.year(),DEC);


    dataFile = SD.open("Voltaje.txt", FILE_WRITE);
    if (dataFile) {
      dataFile.print (ID);
      dataFile.print (", ");
      dataFile.print (volts,6);
      dataFile.print (", ");
      dataFile.print (now.hour(),DEC);
      dataFile.print (":");
      dataFile.print (now.minute(),DEC);
      dataFile.print (":");
      dataFile.print (now.second(),DEC);
      dataFile.print (", ");
      dataFile.print (now.day(),DEC);
      dataFile.print ("/");
      dataFile.print (now.month(),DEC);
      dataFile.print ("/");
      dataFile.println (now.year(),DEC);
      dataFile.close();
    }
  }
}
