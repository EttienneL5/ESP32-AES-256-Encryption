char *getInputAsArr(String in, uint8_t *returnLen) {
  *returnLen = in.length();
  char * result = (char*)malloc(*returnLen);
  memset(result, 0, *returnLen); // making sure all indexes contain zero as the value

  for ( int i = 0; i < *returnLen; i++) {
    result[i] = in[i];
  }

  return result;
}
