char * addPadding(char * in_buffer, uint8_t in_size, uint8_t * out_buf_leng) {
  int padd_amnt = getNextMultiple(in_size, 16);
  *out_buf_leng = in_size + padd_amnt;
  char * result = (char *)malloc(*out_buf_leng); // allocate memory for the return array items
  memset(result, 0, *out_buf_leng);

  for (int i = 0; i < in_size; i++) {
    result[i] = 0;
  }

  if (in_size > 5) {
    if (padd_amnt > 0) { // padding is required (byte values needs to be added or changed
      for (int i = 0; i < *out_buf_leng; i++) {
        if (i < in_size) {
          result[i] = in_buffer[i];
        } else {
          result[i] = padd_amnt;
        }
      } // end for loop
    } else {
      for (int i = 0; i < in_size; i++) {
        result[i] = in_buffer[i];
      }
    }
  } else {
    result[0] = 0xFF; // incoming data less than 1 (empty)
  }
  return result;
}


int getNextMultiple(int size, int multiple) {
  return multiple - (size % multiple);
}

char * removeTrailingZeroes(char * in_buffer, int in_size, int * out_buf_leng) {
  byte TrailingZeros = 0;
  byte lastQwarter = (in_size / 4) * 3;
  for (int i = in_size; i > 0; i--) {
    if (i > lastQwarter) {
      if (in_buffer[i] == 0) {
        TrailingZeros++;
      }
    }
  }

  *out_buf_leng = in_size - TrailingZeros;
  char * result = (char *)malloc(*out_buf_leng); // allocate memory for the return array items
  memset(result, 0, *out_buf_leng);

  for (int i = 0; i < in_size; i++) {
    result[i] = in_buffer[i];
  }
  printValuesHex("Trailing zeroes", result, *out_buf_leng);
  return result;
}
