// C++ code
//
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  if (0.01723 * readUltrasonicDistance(7, 7) < 7 && 0.01723 * readUltrasonicDistance(7, 7) > 0) {
    Serial.println("vid");
  }
  if (0.01723 * readUltrasonicDistance(7, 7) < 14 && 0.01723 * readUltrasonicDistance(7, 7) > 7) {
    Serial.println("for");
  }
  if (0.01723 * readUltrasonicDistance(7, 7) < 21 && 0.01723 * readUltrasonicDistance(7, 7) > 14) {
    Serial.println("bac");
  }
  if (0.01723 * readUltrasonicDistance(7, 7) > 21) {
    Serial.println("no");
  }
  delay(1000); // Delay a little bit for performance
}