#include <LiquidCrystal.h>

// LCD pins: (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

const int gasSensorPin = A0;  // MQ2 sensor connected to A0
const int threshold = 500;    // Gas detection threshold

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // Initialize LED
  Serial.begin(9600);            // Start serial monitor

  lcd.begin(16, 2);  // Initialize LCD (16x2)
  lcd.print("Gas Sensor Ready"); // Display startup message
  delay(2000);
  lcd.clear();
}

void loop() {
  int gasValue = analogRead(gasSensorPin); // Read MQ2 sensor
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  lcd.setCursor(0, 0);
  lcd.print("Gas Level: ");
  lcd.print(gasValue);  // Display gas value

  if (gasValue > threshold) {
    Serial.println("Gas detected! Blinking fast.");
    lcd.setCursor(0, 1);
    lcd.print("ALCOHOL DETECTED");
    
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);  // Fast blink
  } else {
    //Serial.println("No gas detected. Normal blinking.");
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);

    lcd.setCursor(0, 1);
    lcd.print("Status: Normal   "); // Ensure old text is cleared

    //digitalWrite(LED_BUILTIN, LOW);
    //delay(1000);
  }

  delay(500);  // Small delay for stable readings
}
