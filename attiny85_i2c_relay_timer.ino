#include <TinyWireS.h>
char state = '0';
char oldState = '0';
unsigned long endMillis = 0;

void setup()
{
  pinMode(3, OUTPUT );
  TinyWireS.begin(13);                
  TinyWireS.onReceive(receiveEvent);
}

void loop()
{
  TinyWireS_stop_check();
  
  if (oldState != state) {
    switch(state) {
      case '1':
        endMillis = millis() + 2000;
        break;
      case '2':
        endMillis = millis() + 3000;
        break;
      case '3':
        endMillis = millis() + 5000;
        break;
      case '4':
        endMillis = millis() + 10000;
        break;
      default:
        endMillis = 0;
    }
    oldState = state;
  }

  if(endMillis <= millis()) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }
}

void receiveEvent(int howMany)
{
  state = TinyWireS.receive();
}
