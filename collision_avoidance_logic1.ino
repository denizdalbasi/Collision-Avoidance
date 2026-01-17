// UAV Collision Avoidance Prototype
const int trigPin = 9;   // Pin that sends the sound burst
const int echoPin = 8;   // Pin that listens for the echo
const int alertLED = 12; // Visual warning
const int buzzer = 10;   // Audio alarm

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(alertLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600); // Opens the monitor so you can see data
}

void loop() {
  // 1. Send out a 10-microsecond pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 2. Measure the time it takes for the echo to return
  long duration = pulseIn(echoPin, HIGH);

  // 3. Calculate distance in cm (Speed of sound is 0.034 cm/us)
  int distance = duration * 0.034 / 2;

  // 4. Decision Logic
  if (distance > 0 && distance < 30) { // Object closer than 30cm
    digitalWrite(alertLED, HIGH);
    tone(buzzer, 1000); // Sound alarm
    Serial.print("CRITICAL: Obstacle at ");
    Serial.print(distance);
    Serial.println(" cm");
  } else {
    digitalWrite(alertLED, LOW);
    noTone(buzzer);
    Serial.print("Clear Path. Distance: ");
    Serial.println(distance);
  }
  delay(100); // Wait 0.1 seconds before next check
}