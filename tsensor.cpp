#include "tsensor.h"

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2
#define TEMPERATURE_PRECISION 9

// Setup a oneWire instance to communicate with any OneWire
// devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

Tsensor::Tsensor() {
  Serial.begin(9600);
  sensors.begin();

  // locate devices on the bus
  Serial.print("Locating devices...");
  Serial.print("Found ");
  sensorsCount = sensors.getDeviceCount();
  Serial.print(sensorsCount, DEC);
  Serial.println(" devices.");

  // report parasite power requirements
  Serial.print("Parasite power is: ");
  if (sensors.isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");

  for (byte i = 0; i < sensorsCount; i++) {
    if (!sensors.getAddress(thermometer[i], i)) { //заполнение массива адресами сенсоров 
      Serial.print("Unable to find address for Device ");
      Serial.println(i);
    }

    // show the addresses we found on the bus
    Serial.print("Device ");
    Serial.print(i);
    Serial.print(" Address: ");
    printAddress(thermometer[i]);
    //Serial.println();

    // set the resolution to 9 bit per device
    sensors.setResolution(thermometer[i], TEMPERATURE_PRECISION);

    //Serial.print("Device ");
    //Serial.print(i);
    Serial.print(" Resolution: ");
    Serial.print(sensors.getResolution(thermometer[i]), DEC);
    Serial.println();
  }
  Serial.end();
}

//public metods
float Tsensor::temp(int numDevice)
{
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(numDevice);
}

// function to print a device address
void Tsensor::printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    // zero pad the address if necessary
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}

// function to print the temperature for a device
void Tsensor::printTemperature(DeviceAddress deviceAddress)
{
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();
  Serial.println("DONE");
  float tempC = sensors.getTempC(deviceAddress);
  Serial.print("Temp C: ");
  Serial.print(tempC);
  Serial.print(" Temp F: ");
  Serial.print(DallasTemperature::toFahrenheit(tempC));
}

// function to print a device's resolution
void Tsensor::printResolution(DeviceAddress deviceAddress)
{
  Serial.print("Resolution: ");
  Serial.print(sensors.getResolution(deviceAddress));
  Serial.println();
}

// main function to print information about a device
void Tsensor::printData(DeviceAddress deviceAddress)
{
  Serial.print("Device Address: ");
  printAddress(deviceAddress);
  Serial.print(" ");
  printTemperature(deviceAddress);
  Serial.println();
}

//private metods
