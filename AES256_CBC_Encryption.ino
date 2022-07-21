#include <hwcrypto/aes.h>

uint8_t KEY[32] = {0x52, 0x53, 0x68, 0x6D, 0x39, 0x36, 0x66, 0x58, 0x4A, 0x44, 0x53, 0x68, 0x56, 0x32, 0x64, 0x56, 0x79, 0x50, 0x79, 0x6B, 0x52, 0x45, 0x6B, 0x78, 0x32, 0x38, 0x62, 0x75, 0x76, 0x35, 0x4A, 0x33};
uint8_t IV[16] = {0x48, 0x66, 0x72, 0x54, 0x4C, 0x48, 0x73, 0x53, 0x72, 0x67, 0x36, 0x49, 0x6E, 0x65, 0x59, 0x42};
String usedIV = "";

void setup() {
 Serial.begin(115200);
 Serial.println("This is the AES 256 CBC Encryption demo");
 Serial.println("created by Ettienne Lewis. Enjoy your stay");
 Serial.println("As this is an example you can manually change the key and IV in code,");
 Serial.println("you can also make it dynamic for more security (like you should) ;)");
}

void loop() {
  Tasking();
}
