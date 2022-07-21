# ESP32-AES-256-Encryption
This is a working example of the AES256 encryption method

When i was looking into creating a device that required aes256 cbc i did not think that it would be so difficult to find a working example. 
This is my working example to make sure someone out there can use it and not struggle as I did.

I also wrote a new Base64 "Library" (just not sure how to convert it into an actual library but maybe one day) as the ones i found did not encode the data correctly.

The code includes:
1. Input from serial
2. PKCS5/7 padding
3. AES256 CBC Encryption
4. Base64 Encoding

5. Base64 Decode
6. AES256 CBC Decryption
7. Display original input

Please not that this example takes a string but converts it into a byte array (refferenced byte array)

For the people that likes challenges, the floor is yours to optimize and create your own rainbow of new issues
