#include "CRC16.h"
#include "CRC.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

CRC16 crc;

char str[50];
int aktifMenu = 0, pilihCRC = 0;
String code = "";
String CRC;

String inString = "", massage = "", hex = "";
bool comComp = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  menu();
}
