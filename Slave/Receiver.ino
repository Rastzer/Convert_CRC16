String code = "";
String str = "", inString = "", lastString = "", strData = "";
String ascii = "", hex = "", CRC;
String LSB = "", MSB = "";
int string;
int conv, countData;
uint16_t arr[100];
int buf = 0;
uint16_t polynome = 0b1010000000000001;
uint16_t check, lastBit, lastArr;
bool comComp = false, parsing = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  phars();
  if (parsing == true) {
    Serial.print("Geting Data ");
    for (int i = 0; i < 10; i++) {
      Serial.print(".");
      delay(100);
    }
    Serial.print("\n");
    Serial.print("Data Received in ASCII : ");
    Serial.println(ascii);
    Serial.print("Data Received in HEX   : ");
    Serial.println(hex);
    Serial.print("Data CRC               : ");
    Serial.println(CRC);
    Serial.print("===========================================\n");
    Serial.print("Checking Data ");
    for (int i = 0; i < 10; i++) {
      Serial.print(".");
      delay(100);
    }
    Serial.print("\n");
    code += hex;
    code += CRC;
    cekData();
    Serial.print("===========================================\n");
    Serial.println("Checking Data Finish");
    if (lastArr  == 0) {
      Serial.println("Data OK");
    }
    else {
      Serial.println("Data ERROR");
    }
    inString = "";
    parsing = false;
  }
  else {
    countData = 0;
    buf = 0;
    LSB = "";
    MSB = "";
    ascii = "";
    hex = "";
    CRC = "";
    code = "";
    lastArr = 0;
  }
}
