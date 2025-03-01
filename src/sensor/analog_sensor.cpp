#include "analog_sensor.h"

AnalogSensor::AnalogSensor(int pin, const String& name, int bufferSize, long interval) 
  : AsyncSensor(name, bufferSize, interval), pin(pin) {
  pinMode(pin, INPUT);
}

float AnalogSensor::read() {
  int rawValue = analogRead(pin);
  float voltage = rawValue * 5.0 / 1023.0;
  return voltage;
} 