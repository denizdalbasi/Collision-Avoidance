# Real-Time Distance Monitoring Algorithm

This document explains how the Arduino ultrasonic monitoring system works, including the logic it follows and the calculations it performs.

---

### 1. Hardware Integration
* **Trigger/Echo:** Measures sound wave travel time via the Ultrasonic sensor.
* **Alert System:** Visual (Pin 12 LED) and Auditory (Pin 10 Buzzer) feedback.
* **Layout:** Refer to `circuit.png` in the root directory.

### 2. Distance Calculation
The system calculates distance based on the time-of-flight principle:

$$distance = (duration \times 0.034) / 2$$

* **0.034:** The speed of sound (cm/μs).
* **Divided by 2:** Accounts for the round-trip travel of the sound wave.

### 3. Decision Logic
The system evaluates the distance every **100ms** against a **30 cm** threshold:

| Distance | State | LED (Pin 12) | Buzzer (Pin 10) |
| :--- | :--- | :--- | :--- |
| **0 - 30 cm** | Alert | ON | Active |
| **> 30 cm** | Clear | OFF | Silent |

### 4. Summary
The algorithm runs in a continuous loop, providing high-speed responsiveness with minimal power consumption, making it ideal for embedded safety applications.
![Circuit Layout](https://github.com/denizdalbasi/Collision-Avoidance/blob/main/circuit.png?raw=true)
