void menu() {
  switch (aktifMenu) {
    case 0:
      Serial.print("Masukkan Code ASCII :\n");
      massage = "";
      comComp = false;
      inString = "";
      aktifMenu = 1;
      break;
    case 2:
      Serial.println("Pilih polynomial :\n1.ARC\n2.CCITT - FALSE\n3.XMODEM");
      Serial.println("===========================================");
      comComp = false;
      inString = "";
      aktifMenu = 3;
      break;
    case 4:
      Serial.println("Kirim CRC-16?\n1.Yes\n2.No");
      Serial.println("===========================================");
      comComp = false;
      inString = "";
      aktifMenu = 5;
      break;
  }
}
