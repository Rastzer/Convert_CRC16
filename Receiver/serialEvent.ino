void serialEvent() {
  while (Serial.available()){
    char inChar = (char)Serial.read();
    inString += inChar;
    if(inChar == '\n'){
      comComp = true;
    }
  }
}
