## Ultrasonic Distance Sensor Logic
#Project Overview
This project demonstrates the implementation of a real-time distance monitoring system using C++ and an Arduino Uno. The software calculates the distance to an object by measuring the time-of-flight of ultrasonic waves and provides visual and auditory feedback based on programmed thresholds.

#Logic Flow (The Algorithm)
The program follows a continuous execution loop consisting of four main stages:

1. The Trigger Phase
To start a measurement, the software sends a precise 10-microsecond high pulse to the sensor's Trigger pin. This tells the sensor to emit a burst of sound.

2. The Measurement Phase
The code then uses the pulseIn() function to listen to the Echo pin.

It measures the time (in microseconds) that it takes for the sound to bounce off an object and return to the sensor.

This value is stored as a variable called duration.

3. The Calculation Phase
To convert time into a readable distance (cm), the code applies the following mathematical formula:

distance= duration×0.034/2

Why these numbers?

0.034: The speed of sound is approximately 343 meters per second, which translates to 0.034 centimeters per microsecond.

Divide by 2: The sound wave travels to the object and back. We only need the distance to the object, so we divide the total travel time in half.

4. The Decision Logic (Conditionals)
The software evaluates the distance variable against a set threshold (30 cm) to determine the output state:

IF the distance is between 0 and 30 cm:

The system enters an "Alert State."

Digital Pin 12 is set to HIGH (turns on LED).

The tone() function is called on Pin 10 (activates buzzer).

ELSE:

The system enters a "Clear State."

Digital Pin 12 is set to LOW.

The noTone() function is called to silence the buzzer.

Software Specifications
Language: C++ (Arduino)

Communication: Serial communication at 9600 baud for real-time data logging.

Timing: 100ms polling rate to balance responsiveness with CPU efficiency.​
