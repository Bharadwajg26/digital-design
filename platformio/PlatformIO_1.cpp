#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // Pin connections for the LCD
const int cols = 16, rows = 2; // Display dimensions
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(cols, rows); // Initialize the LCD display

  // Calculate and format the answer
  const float propagationDelay = 20; // Propagation delay in nanoseconds
  const int stages = 4; // Number of stages in the ripple counter
  const float maxFrequency = 1000.0f / (propagationDelay * stages); // Calculate MHz
  //const float roundedFrequency = (int)(maxFrequency * 10) / 10.0f; // Round to one decimal place
  

  // Display the question and answer
  lcd.print("MaxClocFreq(MHz)");
  lcd.setCursor(0, 1);
  lcd.print(maxFrequency);
  lcd.print("MHz");
}

void loop() {
  // Add any additional functionality in the loop (optional)
}