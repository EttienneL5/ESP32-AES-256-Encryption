char * encrypt(char * incoming, size_t in_size, size_t *out_size) {
  esp_aes_context ctx;
  esp_aes_init( &ctx );
  esp_aes_setkey( &ctx, KEY, 256);

  uint8_t iv_cop[16];
  memcpy(iv_cop, IV, 16);
  setUsedIVString();

  uint8_t paddedlen = 0;
  char * paddedData = addPadding((char*)incoming, in_size, &paddedlen);
  if ((paddedlen == 1) && paddedData[0] == 0xff) {
    return (char*)0xff;
  }

  uint8_t * cBuffer = (uint8_t*)malloc(paddedlen);
  esp_aes_crypt_cbc(&ctx, ESP_AES_ENCRYPT, paddedlen, iv_cop, (uint8_t*)paddedData, cBuffer);

  size_t encodeSize = 0;
  char *encoded = base64_encode((const unsigned char *)cBuffer, paddedlen, &encodeSize);
  *out_size = encodeSize;

  esp_aes_free(&ctx);
  return encoded;
}

char * decrypt(char * incoming, uint8_t in_size, size_t *out_Length) {
  esp_aes_context ctx;
  esp_aes_init( &ctx );
  esp_aes_setkey( &ctx, KEY, 256);

  uint8_t iv_cop[16];
  memcpy(iv_cop, IV, 16);

  *out_Length = 0;
  char * cBuffer;
  unsigned char *base64_decoded = base64_decode((const char*) incoming,  in_size, (size_t*)out_Length);
  if (*out_Length > 0) {
    cBuffer = (char*)malloc(*out_Length);

    esp_aes_crypt_cbc( &ctx, ESP_AES_DECRYPT, *out_Length, iv_cop, (uint8_t*)base64_decoded, (uint8_t*)cBuffer);

    esp_aes_free( &ctx );
  } else {
    cBuffer = (char*)malloc(1);
    cBuffer[0] = 0xff;
  }
  return cBuffer;
}

/*
   This could remove spaces but i reused code form one of my other projects where i feed this function a data byte array coming from bluetooth,
   The data array is one long encrypted string and sometimes the string could contain zeroes at the end
*/
char * filterZeroes(char * incoming, uint8_t leng, uint8_t * out_leng) {
  char * result;
  uint8_t lastPart = leng - 3;
  uint8_t count = 0;

  for (int i = lastPart; i < leng; i++) {
    if (incoming[i] < 0x20) { // spaces will be kept
      count++;
    }
  }
  *out_leng = leng - count;
  result = (char*)malloc(*out_leng);
  memcpy(result, incoming, *out_leng);
  free(incoming);
  return result;
}

char * getIV(char * incoming, uint8_t in_leng, uint8_t * datLength) {
  *datLength = in_leng - sizeof(IV);
  char * result = (char*)malloc(*datLength);

  for (int i = 0; i < sizeof(IV); i++) {
    IV[i] = (uint8_t)incoming[*datLength + i];
  }
  memcpy(IV, incoming + *datLength, sizeof(IV));
  memcpy(result, incoming, *datLength);
  free(incoming);
  return result;
}

void setUsedIVString() {
  String result = "";
  for (int i = 0; i < sizeof(IV); i++) {
    result += (char)IV[i];
  }
  usedIV = result;
}
