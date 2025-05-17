#include <LiquidCrystal.h>

// Initialize LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(14, 27, 26, 25, 33, 32);

// Custom characters for spinner animation (4 frames)
byte spinnerFrames[4][8] = {
  {0b00000,0b00100,0b01010,0b00100,0b00000,0b00000,0b00000,0b00000}, // frame 1
  {0b00000,0b00000,0b00100,0b01010,0b00100,0b00000,0b00000,0b00000}, // frame 2
  {0b00000,0b00000,0b00000,0b00100,0b01010,0b00100,0b00000,0b00000}, // frame 3
  {0b00000,0b00000,0b00000,0b00000,0b00100,0b01010,0b00100,0b00000}  // frame 4
};

void setup() {
  lcd.begin(16, 2);       // Initialize the LCD with 16 columns and 2 rows
  lcd.print("Loading..."); // Display initial message

  // Load custom characters into LCD memory
  for (int i = 0; i < 4; i++) {
    lcd.createChar(i, spinnerFrames[i]);
  }
}

void loop() {
  // Cycle through spinner frames at bottom-right corner
  for (int i = 0; i < 4; i++) {
    lcd.setCursor(15, 1);  // Position at last column, second row
    lcd.write(i);          // Display custom char frame i
    delay(300);            // Wait 300 milliseconds
  }
}
