void phars() {
  if (comComp == true) {
    if (aktifMenu == 1) {
      massage += inString;
      massage.toCharArray(str, massage.length());
      Serial.println("Code : " + massage);
      Serial.print("===========================================\n");
      aktifMenu = 2;
    }
    if (aktifMenu == 3) {
      if (inString.toInt() == 1) {
        arc();
        pilihCRC = 1;
        aktifMenu = 4;
      }
      else if (inString.toInt() == 2) {
        ccittFalse();
        pilihCRC = 2;
        aktifMenu = 4;
      }
      else if (inString.toInt() == 3) {
        xmodem();
        pilihCRC = 3;
        aktifMenu = 4;
      }
      else {
        Serial.println("Mohon masukkan pilihan polynomial yang benar!");
        inString = "";
        comComp = false;
      }
    }
    if (aktifMenu == 5) {
      if (inString.toInt() == 1) {
        crc.reset();
        Serial.print("Mengirim CRC-16 : ");
        if (pilihCRC == 1) {
          arc();
          massage.remove(massage.length() - 1, 2);
          mySerial.print("$ARC&");
          mySerial.print(massage);
          mySerial.print(crc.getCRC(), HEX);
          mySerial.print("\n");
          //mySerial.println("$");
        }
        if (pilihCRC == 2) {
          ccittFalse();
          massage.remove(massage.length() - 1, 2);
          mySerial.print("$CCITT-FALSE&");
          mySerial.print(massage);
          mySerial.print(crc.getCRC(), HEX);
          mySerial.print("\n");
          //mySerial.println("$");
        }
        if (pilihCRC == 3) {
          xmodem();
          massage.remove(massage.length() - 1, 2);
          mySerial.print("$XMODEM&");
          mySerial.print(massage);
          mySerial.print(crc.getCRC(), HEX);
          mySerial.print("\n");
          //mySerial.println("$");
        }
        Serial.println("===========================================");
        crc.reset();
        aktifMenu = 0;
      }
      if (inString.toInt() == 2) {
        crc.reset();
        aktifMenu = 2;
      }
    }
  }
}
