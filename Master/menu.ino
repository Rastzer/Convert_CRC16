void menu() {
  switch (aktifMenu) {
    case 0:
      Serial.print("Masukkan data dalam ASCII :\n");
      massage = "";
      comComp = false;
      inString = "";
      aktifMenu = 1;
      break;
    case 1:
      if (comComp == true) {
        massage += inString;
        massage.toCharArray(str, massage.length());
        aktifMenu = 2;
      }
      break;
    case 2:
      Serial.print("Code             : " + massage);
      Serial.print("HEX              : ");
      for (int i = 0; i < massage.length() - 1; i++) {
        Serial.print(massage[i], HEX);
      }
      Serial.print("\n");
      Serial.print("===========================================\n");
      aktifMenu = 3;
      break;
    case 3:
      Serial.print("Calculate CRC ");
      for (int i = 0; i < 10; i++) {
        Serial.print(".");
        delay(100);
      }
      Serial.print("\n");
      arc();
      Serial.print("Getting CRC ");
      for (int i = 0; i < 10; i++) {
        Serial.print(".");
        delay(100);
      }
      Serial.print("\n");
      Serial.print("getCRC           : ");
      Serial.println(crc.getCRC(), HEX);
      Serial.print("===========================================\n");
      aktifMenu = 4;
      break;
    case 4:
      Serial.print("Getting CodeWord ");
      for (int i = 0; i < 10; i++) {
        Serial.print(".");
        delay(100);
      }
      Serial.print("\n");
      Serial.print("CodeWord         : ");
      for (int i = 0; i < massage.length() - 1; i++) {
        Serial.print(massage[i]);
      }
      Serial.println(crc.getCRC(), HEX);
      Serial.println("Or");
      Serial.print("CodeWord         : ");
      for (int i = 0; i < massage.length() - 1; i++) {
        Serial.print(massage[i], HEX);
      }
      Serial.println(crc.getCRC(), HEX);
      Serial.print("===========================================\n");
      aktifMenu = 5;
      break;
    case 5:
      Serial.println("Send data ?");
      Serial.println("1. Send Data Normal\n2. Send Data Error\n3. No");
      Serial.print("===========================================\n");
      comComp = false;
      inString = "";
      aktifMenu = 6;
      break;
    case 6:
      if (comComp == true) {
        if (inString.toInt() == 1) {
          Serial.print("Sending CodeWord ");
          for (int i = 0; i < 10; i++) {
            Serial.print(".");
            delay(100);
          }
          Serial.print("\n");
          mySerial.print("$");
          for (int i = 0; i < massage.length() - 1; i++) {
            mySerial.print(massage[i]);
          }
          mySerial.print("&");
          mySerial.print("$");
          for (int i = 0; i < massage.length() - 1; i++) {
            mySerial.print(massage[i], HEX);
          }
          mySerial.print("&");
          mySerial.print("$");
          mySerial.print(crc.getCRC(), HEX);
          mySerial.print("&");
          mySerial.print("\n");
          Serial.print("===========================================\n");
          crc.reset();
          aktifMenu = 0;
        }
        if (inString.toInt() == 2) {
          Serial.print("Create Error Data ");
          for (int i = 0; i < 10; i++) {
            Serial.print(".");
            delay(100);
          }
          Serial.print("\n");
          Serial.print("Sending CodeWord ");
          for (int i = 0; i < 10; i++) {
            Serial.print(".");
            delay(100);
          }
          Serial.print("\n");
          //          mySerial.print("$ascii&$");
          mySerial.print("$");
          for (int i = 0; i < massage.length() - 1; i++) {
            mySerial.print(massage[i]);
          }
          //          mySerial.print(crc.getCRC(), HEX);
          mySerial.print("&");
          //          mySerial.print("$hex&$");
          mySerial.print("$");
          for (int i = 0; i < massage.length() - 1; i++) {
            mySerial.print(massage[i], HEX + 1);
          }
          mySerial.print("&");
          mySerial.print("$");
          mySerial.print(crc.getCRC(), HEX);
          mySerial.print("&");
          mySerial.print("\n");
          Serial.print("===========================================\n");
          crc.reset();
          aktifMenu = 0;
        }
        if (inString.toInt() == 3) {
          crc.reset();
          aktifMenu = 0;
        }
      }
      break;
  }
}
