void cekData(){
    for (int i = 0; i < code.length(); i++) {
    str += code[i];
    if (i % 2 != 0) {
      conv = 0;
      for (int j = 0; j < 2; j ++) {
        if (j == 0) {
          conv = conv + table(str[j]) * 16;
        }
        else {
          conv = conv + table(str[j]);
        }
      }
      arr[buf] = conv;
      buf ++;
      str = "";
    }
  }
  for (int i = 0; i < code.length() / 2; i ++) {
    if(i > 0){
      arr[i] = lastArr ^ arr[i]; 
    }
    for (int j = 0; j < 8; j ++) {
      Serial.println(arr[i], BIN);
      lastBit = bitRead(arr[i],0);
      arr[i] = arr[i] >> 1;
      if (lastBit == 1) {
        arr[i] = arr[i] ^ polynome;
      }
      else {
        arr[i] = arr[i];
      }
      lastArr = arr[i];
    }
  }
}
