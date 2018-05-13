#include "Arduino.h"
#include "Relay.h"

Relay::Relay(int pinNum)
{
  _pinNum = pinNum;
  digitalWrite(_pinNum, HIGH); //избавляемся включения реле при старте 
  pinMode(_pinNum, OUTPUT);
}

//public metods
void Relay::setState(boolean state)
{
  digitalWrite(_pinNum, !state);
}

boolean Relay::getState()
{
  return !digitalRead(_pinNum);
}

//private metods
