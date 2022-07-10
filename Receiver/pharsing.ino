void phars() {
  if (comComp == true) {
    for (int i = 0; i < inString.length(); i++) {
      if (inString[i] == '$') {
        lastString = "";
        polynom = "";
      }
      else if (inString[i] == '&') {
        lastString = polynom = strData;
        strData = "";
      }
      else {
        if (lastString == "") {
          strData += inString[i];
        }
        else {
          massage += inString[i];
        }
      }
    }
    parsing = true;
    comComp = false;
  }
}
