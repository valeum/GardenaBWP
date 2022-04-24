#include <SoftwareSerial.h>

// Arduino UNO (RX to TX of Gardena device)
const int PIN_RX = 2;
const int PIN_TX = 3;

SoftwareSerial sSerial(PIN_RX, PIN_TX);

int i = 1;

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
  if (sSerial.available()) {
    int RX_DATA = sSerial.read();

    // Options
    // A - Print Only Start, Checksum and End as HEX
    if(RX_DATA == 0xFE || i == 93 || RX_DATA == 0xFD) {
      Serial.print("|");
      Serial.print(RX_DATA, HEX);
      Serial.print("|");
    } else {
      char RX_DATA_CHAR = RX_DATA;
      Serial.write(RX_DATA_CHAR);
    }
    
    // Print all as HEX
    /*
    Serial.print(RX_DATA, HEX);
    Serial.print("|");
    */
    
    if(RX_DATA == 0xFD) {
      Serial.println("");
      i = 1;
    } else {
      i++;
    }
  }
}
