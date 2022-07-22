void cdma2000() {
  crc.setPolynome(0xC867);
  crc.setStartXOR(0xFFFF);
  crc.setEndXOR(0);
  crc.setReverseIn(false);
  crc.setReverseOut(false);
  crc.add((uint8_t *) str, massage.length() - 1);
  Serial.print("CRC-16/CDMA2000 : ");
  Serial.println(crc.getCRC(), HEX);
}

void ccittFalse() {
  crc.setPolynome(0x1021);
  crc.setStartXOR(0xFFFF);
  crc.setEndXOR(0);
  crc.setReverseIn(false);
  crc.setReverseOut(false);
  crc.add((uint8_t *) str, massage.length() - 1);
  Serial.print("CRC-16/CCITT - FALSE : ");
  Serial.println(crc.getCRC(), HEX);
}

void xmodem() {
  crc.setPolynome(0x1021);
  crc.setStartXOR(0);
  crc.setEndXOR(0);
  crc.setReverseIn(false);
  crc.setReverseOut(false);
  crc.add((uint8_t *) str, massage.length() - 1);
  Serial.print("CRC-16/XMODEM : ");
  Serial.println(crc.getCRC(), HEX);
}

void arc() {
  crc.setPolynome(0x8005);
  crc.setStartXOR(0);
  crc.setEndXOR(0);
  crc.setReverseIn(true);
  crc.setReverseOut(true);
  crc.add((uint8_t *) str, massage.length() - 1);
  CRC = crc.getCRC();
  Serial.println("Using Polynomial : 0x8005");
  Serial.println("StartXOR         : 0x0000");
  Serial.println("EndXOR           : 0x0000");
  Serial.println("ReverseIn        : true");
  Serial.println("ReverseOut       : true");
  Serial.print("===========================================\n");
}
