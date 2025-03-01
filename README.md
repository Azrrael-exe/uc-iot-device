# uc-iot-device
Base Repository for micro controller iot device

## Main Features

- Asynchronous analog sensor readings
- Moving average readings to reduce noise
- Configurable circular buffer
- Adjustable reading intervals
- Automatic conversion from analog values to voltage (0-5V)

## System Components

### Hardware
- Arduino UNO R4 WiFi
- Analog sensor connected to pin A0

### Software Structure

The project is organized into several components:

1. **AsyncSensor** (Base Class)
   - Handles basic asynchronous reading logic
   - Implements circular buffer for storing readings
   - Calculates reading averages

2. **AnalogSensor** (Derived Class)
   - Specialization for analog sensors
   - Converts analog readings (0-1023) to voltage (0-5V)
   - Inherits AsyncSensor functionality

3. **Main Program**
   - Configures sensor on pin A0
   - Displays readings every 5 seconds via serial port
   - Serial communication speed: 115200 baud

## Configuration

### Sensor Parameters
- Analog pin: A0
- Buffer size: 10 samples
- Sampling interval: 100ms
- Print interval: 5000ms (5 seconds)

