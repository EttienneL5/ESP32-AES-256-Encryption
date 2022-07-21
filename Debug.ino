void printValuesHex(String tag, unsigned char *val, int size) {
  Serial.print(tag + ": " + String(size) + " - ");
  for (int i = 0; i < size; i++) {
    if (val[i] > (byte)16) {
      Serial.print(val[i], HEX);
    } else {
      Serial.print("0");
      Serial.print(val[i], HEX);
    }
    Serial.print(" ");
  }
  Serial.println("");
}


void printValuesHex(String tag, char *val, int size) {
  Serial.print(tag + ": " + String(size) + " - ");
  for (int i = 0; i < size; i++) {
    if (val[i] > (byte)16) {
      Serial.print(val[i], HEX);
    } else {
      Serial.print("0");
      Serial.print(val[i], HEX);
    }
    Serial.print(" ");
  }
  Serial.println("");
}

void printValues(String tag, char *val, int size) {
  Serial.print(tag + ": " + String(size) + " - ");
  for (int i = 0; i < size; i++) {
    Serial.print(String(val[i]));
  }
  Serial.println("");
}
