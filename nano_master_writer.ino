
#include <Wire.h>

#define USE_SERIAL  Serial

String x = "";

void setup() {
  Wire.begin();
  USE_SERIAL.begin(9600); 
  USE_SERIAL.println("Main program is starting...");
  USE_SERIAL.println("Set value");
}

void loop() {
  String preVal = x;
  if (USE_SERIAL.available())
  {
    x = USE_SERIAL.readString();
    delay(200);
  }
  
  if (preVal != x)
  {
    char buffer[4];
    x.toCharArray(buffer, 4);
    Wire.beginTransmission(13);
    Wire.write(buffer);              
    Wire.endTransmission();
    USE_SERIAL.print("Data sent to ATtiny Device: ");
    USE_SERIAL.println(buffer);
    Wire.requestFrom(0x13,1);    
    while(Wire.available())    
    { 
      int c = Wire.read(); 
    }
  }
  delay(50);
}
