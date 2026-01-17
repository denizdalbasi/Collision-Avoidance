# 🧠 System Algorithm – Real-Time Distance Monitoring

## Overview
- This document explains the algorithm used in the Real-Time Distance Monitoring System.
- The system is implemented using **C++ (Arduino)** on an **Arduino Uno**.
- Distance is measured using an ultrasonic sensor based on **time-of-flight** calculations.

---

## 1. Trigger Phase
- The Arduino sends a **10-microsecond HIGH pulse** to the sensor’s **Trigger pin**.
- This pulse causes the ultrasonic sensor to emit sound waves.

---

## 2. Measurement Phase
- The Arduino listens on the **Echo pin** using the `pulseIn()` function.
- It measures the time (in microseconds) taken for the sound wave to:
  - Travel to the object
  - Reflect back to the sensor
- The measured time is stored in a variable named `duration`.

---

## 3. Calculation Phase
- The distance to the object is calculated using the formula:
  

distance = duration × 0.034 / 2

- **Formula Explanation:**
- `0.034` → Speed of sound in cm per microsecond
- `/ 2` → Accounts for the sound traveling to the object and back
- The final value represents the distance in **centimeters (cm)**.

---

## 4. Decision Logic
- The calculated distance is compared against a **30 cm threshold**.

### Alert State (0–30 cm)
- LED on **Pin 12** is turned **ON**
- Buzzer on **Pin 10** is activated using `tone()`

### Clear State (> 30 cm)
- LED on **Pin 12** is turned **OFF**
- Buzzer is silenced using `noTone()`

---

## Execution Timing
- The algorithm runs continuously inside the Arduino `loop()` function.
- A **100 ms delay** is used between measurements to:
- Maintain responsiveness
- Reduce unnecessary CPU usage

---

## Summary
- The system continuously monitors distance in real time.
- Visual and auditory alerts are triggered when an object enters the defined proximity range.
- The algorithm is simple, efficient, and suitable for embedded applications.
