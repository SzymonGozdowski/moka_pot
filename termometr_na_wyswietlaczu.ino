#include <LiquidCrystal.h>

// Initialize the library by associating any needed LCD interface pin
// with the Arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int lm35_pin = A1; // LM35 O/P pin

void setup() {
  // Uncomment the next line to see temperature in the Serial Monitor
  Serial.begin(9600);
  
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Print an initial message to the LCD
  lcd.print("Temp: ");
}

void loop() {
  float temp_adc_val = analogRead(lm35_pin); // Read Temperature
  float temp_val = temp_adc_val * (5.0 / 1023.0) * 100.0; // Convert to °C

  // Clear the previous temperature reading
  lcd.setCursor(0, 1); // Move cursor to second row
  lcd.print("                "); // Clear row with spaces
  
  // Format and display the temperature value
  lcd.setCursor(0, 1); // Reset cursor to start of row
  lcd.print(temp_val, 1); // Print temperature with 1 decimal place
  lcd.print((char)223); // Print the degree symbol
  lcd.print("C");

  // Optional: send temperature to Serial Monitor
  Serial.println(temp_val);
  
  delay(500); // Wait for 0.5 second before updating
}
