#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD address to 0x27 for a 16x2 display

const int redLEDPin = 2;     // Red LED connected to Pin 2
const int greenLEDPin = 3;   // Green LED connected to Pin 3
const int voltagePin = A0;   // Analog input pin for reading battery voltage

void setup() {
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight
  lcd.setCursor(0, 0);
  lcd.print("Battery Voltage:");
  Serial.begin(9600);
}

void loop() {
  // Read battery voltage
  int batteryVoltage = analogRead(voltagePin);

  // Convert analog reading to voltage (assuming a 5V reference)
  float voltage = batteryVoltage * (5.0 / 1023.0);

  // Display battery voltage on the LCD
  lcd.setCursor(0, 1);
  lcd.print("                ");  // Clear the previous reading
  lcd.setCursor(0, 1);
  lcd.print(voltage, 2);  // Display voltage with 2 decimal places

  // Check battery health
  if (voltage >= 1.5) {
    digitalWrite(greenLEDPin, HIGH);  // Green LED on for a healthy battery
    digitalWrite(redLEDPin, LOW);
  } else {
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(redLEDPin, HIGH);     // Red LED on for a low battery
  }

  delay(1000); // Delay for a second before the next reading
}
