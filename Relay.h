#ifndef Relay_h
#define Relay_h

#include "Arduino.h"

class Relay
{
  public:
    Relay(int pinNum);
    void setState(boolean state);
    boolean getState();
   
  private:
    int _pinNum;
};

#endif
