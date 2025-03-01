#include <Arduino.h>
#include "sensor.h"

AsyncSensor::AsyncSensor(const String& name, int bufferSize, long interval) {
    this->name = name;
    this->bufferSize = bufferSize;
    this->buffer = new float[bufferSize];
    this->bufferIndex = 0;
    this->bufferFilled = false;
    this->interval = interval;
    this->lastReadTime = 0;
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0.0;
    }
}

String AsyncSensor::getName() {
    return this->name;
}


void AsyncSensor::loop() {
    unsigned long currentTime = millis();
    if (currentTime - lastReadTime >= interval) {
        float newValue = read();
        lastReadTime = currentTime;
        buffer[bufferIndex] = newValue;
        bufferIndex = (bufferIndex + 1) % bufferSize;

        if (bufferIndex == 0) {
            bufferFilled = true;
        }
    }
}

float AsyncSensor::getValue() {
    if (!bufferFilled && bufferIndex == 0) {
        return 0; // No hay lecturas todavía
    }
    
    float sum = 0.0;
    int count = bufferFilled ? bufferSize : bufferIndex;
    for (int i = 0; i < count; i++) {
        sum += buffer[i];
    }
    return sum / count; // Round to nearest integer
}

void AsyncSensor::setInterval(unsigned long interval) {
    this->interval = interval;
}