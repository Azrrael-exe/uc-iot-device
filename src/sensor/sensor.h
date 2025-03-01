#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class AsyncSensor {
  public:
    AsyncSensor(const String& name, int bufferSize, long interval); // Constructor with name parameter
    void loop(); // Method to handle the sensor's internal operation
    float getValue(); // Method to get the average value of the sensor's readings
    void setInterval(unsigned long _interval); // Method to set the reading interval
    virtual float read(){return 0.0;}; // Method to read the sensor's value
    String getName(); // Method to get the sensor name

  protected:
    String name; // Name of the sensor
    unsigned long interval;
    unsigned long lastReadTime;
    float* buffer;
    int bufferSize;
    int bufferIndex;
    bool bufferFilled;
};

#endif // SENSOR_H 