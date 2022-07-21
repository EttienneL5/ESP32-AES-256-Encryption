void GetStringFromUser(String message) {
  Serial.println(message);

  while (Serial.available() <= 0) {}; // wait until input is given

  if (Serial.available() > 0) {
    String input = Serial.readString(); // please remember that a string will most of the times have a termination characer at the end and should always be remembered as it is included in the encrypted data

    uint8_t charDatLen = 0;
    char* charDat = getInputAsArr(input, &charDatLen);

    // Your input value
    printValues("Your String", charDat, charDatLen);

    // Remove all the zero values from the end of the string
    uint8_t filteredLen = 0;
    char * filtered = filterZeroes(charDat, charDatLen, &filteredLen);

    // Display value
    printValuesHex("Filtered String", filtered, filteredLen);

    //  Encrypt the input string
    size_t encryptLen = 0;
    char * encrypted = encrypt(filtered, filteredLen, &encryptLen);

    // Display encrypted value
    printValuesHex("Encrypted HEX String", encrypted, encryptLen);

    Serial.print("Encrypted String: ");
    Serial.print(encryptLen, DEC);
    Serial.println(" - " + String(encrypted));

    //  Decrypt the string
    size_t decryptedLen = 0;
    char * decryptedData = decrypt(encrypted, encryptLen, &decryptedLen);

    // Display decrypted value
    printValuesHex("Encrypted", decryptedData, decryptedLen);

    Serial.print("Decrypted String: ");
    Serial.print(decryptedLen, DEC);
    Serial.println(" - " + String(decryptedData));
    Serial.println();
    Serial.println();
  }
}
