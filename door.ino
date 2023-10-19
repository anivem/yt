#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Servo myservo;  // Create a servo object
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD address and dimensions

void setup() {
  myservo.attach(7);  // Attach the servo to pin 7
  lcd.init();  // Initialize the LCD
  lcd.backlight();  // Turn on the backlight
  Serial.begin(9600);  // Start the serial communication
  Serial.println("Ready to receive commands...");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readString();  // Read the command from Bluetooth

    if (command == "open") {
      myservo.write(90);  // Turn the servo to 90 degrees (open)
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Door is open");
    } else if (command == "close") {
      myservo.write(0);  // Turn the servo to 0 degrees (close)
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Door is closed");
    } else {
      // Display the received message on the LCD
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("");
      lcd.setCursor(0, 1);
      lcd.print(command);
    }
    
    Serial.println("Received: " + command);  // Print the received command to serial monitor
  }
}
