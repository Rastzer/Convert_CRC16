String inString = "", massage = "", lastString = "", strData = "", polynom = "";
bool comComp = false, parsing = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  phars();
  if (parsing == true) {
    Serial.print("Polynome : ");
    Serial.println(polynom);
    Serial.println("===========================================");
    Serial.print("Codeword : ");
    Serial.println(massage);
    Serial.println("===========================================");
    inString = "";
    parsing = false;
  }
  else {
    polynom = "";
    massage = "";
  }
}
