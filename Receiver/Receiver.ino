String inString = "", massage;
bool comComp = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (comComp == true) {
    massage = inString;
    Serial.print("Code : " + massage + "\n");
    inString = "";
    comComp = false;
  }
}
