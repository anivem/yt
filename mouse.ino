void setup() {
  Serial.begin(9600);
}

void loop() {
  int a0Value = analogRead(A0);
  int a1Value = analogRead(A1);
  int a2Value = analogRead(A2);
  int a3Value = analogRead(A3);
  int a4Value = analogRead(A4);

  // Check the conditions and print messages accordingly
  if (a0Value == 0) {
    Serial.println("Right Click");
  }
  if (a1Value > 900) {
    Serial.println("Left Hover");
  }
  if (a1Value < 100) {
    Serial.println("Right Hover");
  }
  if (a2Value > 900) {
    Serial.println("Down Hover");
  }
  if (a2Value < 100) {
    Serial.println("Up Hover");
  }
  if (a4Value > 900) {
    Serial.println("Down Scroll");
  }
  if (a4Value < 100) {
    Serial.println("Up Scroll");
  }
  if (a3Value == 0) {
    Serial.println("Left Click");
  }

  delay(100); // Adjust the delay as needed to control the output frequency
}
