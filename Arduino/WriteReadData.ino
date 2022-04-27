#include <SoftwareSerial.h>

const int PIN_RX = 2;
const int PIN_TX = 3;

//byte sendData[] = {0x00 }; // return 0xFF, loop
//byte sendData[] = {0x01 }; // return 0xFF, loop
//byte sendData[] = {0x02 }; // return 0xFF, loop

//byte sendData[] = {0xE0 }; // return loop
//byte sendData[] = {0xE1 }; // return loop
//byte sendData[] = {0xE2 }; // no return, unless the command is sent twice.
//byte sendData[] = {0xE3 }; // no return
// E3 to FF // no return
//byte sendData[] = {0xFF }; // no return

//byte sendData[] = {0xFE, 0x32, 0xFD }; // no return
//byte sendData[] = {0xFE, 0x32, 0x3B, 0xFD }; // no return
//byte sendData[] = {0xFE, 0x32, 0x3B, 0x49, 0xFD }; // no return
//byte sendData[] = {0xFE, 0x32, 0x3B, 0x00, 0xFD }; // return 0xFF, loop
//byte sendData[] = {0xFE, 0x32, 0x3B, 0x49, 0x3A, 0xFD }; // return loop
//byte sendData[] = {0xFE, 0x32, 0x3B, 0x49, 0x3A, 0x30, 0xFD }; // return 0xFF, loop

//byte sendData[] = {0xFE, 0x32, 0x3B, 0x49, 0x3A, 0x30, 0x31, 0xFD }; // return loop
//byte sendData[] = {0xFE, 0x32, 0x3B, 0x49, 0x3A, 0x30, 0x31, 0x2E, 0xFD }; // return loop
//byte sendData[] = {0xFE, 0x32, 0x3B, 0x49, 0x3A, 0x30, 0x31, 0x2E, 0x30, 0xFD }; // return 0xFF, loop
//byte sendData[] = {0xFE, 0x32, 0x3B, 0x49, 0x3A, 0x30, 0x31, 0x2E, 0x30, 0x30, 0xFD }; // return 0xFF, loop
//byte sendData[] = {0xFE, 0x32, 0x3B, 0x49, 0x3A, 0x30, 0x31, 0x2E, 0x30, 0x30, 0x3B, 0xFD }; // return 0xFF, loop
//byte sendData[] = {0xFE, 0x32, 0x3B, 0x49, 0x3A, 0x31, 0xFD }; // return loop
//byte sendData[] = {0xFE, 0x32, 0x3B, 0x49, 0x3A, 0x31, 0x70, 0xFD }; // return loop
//byte sendData[] = {0xFD, 0x32, 0x3B, 0x49, 0x3A, 0x31, 0x70, 0xFD }; // return loop

SoftwareSerial sSerial(PIN_RX, PIN_TX);

int incomingByte = 0;
int count = 0;

void setup()
{
  Serial.begin(115200);
    while (!Serial) {
  }
 
  Serial.println("Wait for Data:");
 
  sSerial.begin(9600);
}
 
void loop()
{
  if(sSerial.available()) {
    byte RX_DATA = sSerial.read();
    char RX_DATA_CHAR = RX_DATA;
    
    if(count == 0) {
      Serial.print(RX_DATA, HEX);
      Serial.print(",");
    } else {
      char RX_DATA_CHAR = RX_DATA;
      Serial.write(RX_DATA_CHAR);
      count++;
    }
    
    if(RX_DATA == 0xFE) {
      count = 1;
    }
    if(count > 91) {
      count = 0;
    }
    
    if(RX_DATA == 0xFD || RX_DATA == 0xFF) {
      Serial.println("");
      count = 0;
    }

  }
  if(Serial.available() > 0) {
    Serial.print("Send: ");
    
    for(byte i = 0; i < sizeof(sendData); i++) {
      Serial.print(sendData[i], HEX);
      sSerial.write(byte(sendData[i]));
    }
    Serial.println("");
    
    incomingByte = Serial.read();
  }
}
