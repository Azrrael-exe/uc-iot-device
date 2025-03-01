#include <Arduino.h>
#include "sensor/analog_sensor.h"
#include <ArduinoJson.h>

const int ledPin = 13;

AnalogSensor analogSensor(A0, "AnalogSensor", 10, 100);
unsigned long lastPrintTime = 0;
const unsigned long printInterval = 5000; // 5 segundos
JsonDocument doc;

void setup() {
  // Inicializar el pin del LED como salida
  pinMode(ledPin, OUTPUT);
  pinMode(A0, INPUT);
  
  Serial.begin(115200);
  Serial.println("Iniciando sensor analógico en A0...");
}

void loop() {

  
  // Actualizar el sensor
  analogSensor.loop();
  
  // Imprimir el valor cada 5 segundos
  unsigned long currentMillis = millis();
  if (currentMillis - lastPrintTime >= printInterval) {
    lastPrintTime = currentMillis;
    doc[analogSensor.getName()] = analogSensor.getValue();
    Serial.println(doc.as<String>());
  }
}