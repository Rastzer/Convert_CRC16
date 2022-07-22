void phars() {
  if (comComp == true) {
    for (int i = 0; i < inString.length(); i++) {
      if (inString[i] == '$') {
        lastString = "";
      }
      else if (inString[i] == '&') {
        if (countData == 0) {
          lastString = ascii = strData;
          strData = "";
        }
        if (countData == 1) {
          lastString = hex = strData;
          strData = "";
        }
        if (countData == 2) {
          lastString = strData;
          for (int i = 0; i < 2; i ++) {
            MSB += lastString[i];
          }
          for (int j = 2; j < 4; j ++) {
            LSB += lastString[j];
          }
          CRC += LSB;
          CRC += MSB;
          strData = "";
        }
        countData ++;
      }
      else {
        if (lastString == "") {
          strData += inString[i];
        }
      }
    }
    parsing = true;
    comComp = false;
  }
}
