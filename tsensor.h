#ifndef Tsensor_h
#define Tsensor_h

#include "Arduino.h"
#include <OneWire.h>
#include <DallasTemperature.h>

class Tsensor
{
  public:
    Tsensor();
    byte sensorsCount;
    float temp(int numDevice);
    void printAddress(DeviceAddress deviceAddress);
    void printTemperature(DeviceAddress deviceAddress);
    void printResolution(DeviceAddress deviceAddress);
    void printData(DeviceAddress deviceAddress);

  private:
    int _temp;
    
    // arrays to hold device addresses
    DeviceAddress thermometer[10];
};

#endif
