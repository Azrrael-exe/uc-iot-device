#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

#include "sensor.h"

class AnalogSensor : public AsyncSensor {
  public:
    AnalogSensor(int pin, const String& name = "AnalogSensor", int bufferSize = 10, long interval = 1000);
    float read() override;
  
  private:
    int pin;
};

#endif // ANALOG_SENSOR_H 