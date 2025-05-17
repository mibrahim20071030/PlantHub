#include <LiquidCrystal.h>

// Initialize LCD with Arduino Uno pins: RS=12, E=11, D4=5, D5=4, D6=3, D7=2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte spinnerFrames[4][8] = {
  {0b00000,0b00100,0b01010,0b00100,0b00000,0b00000,0b00000,0b00000}, // frame 1
  {0b00000,0b00000,0b00100,0b01010,0b00100,0b00000,0b00000,0b00000}, // frame 2
  {0b00000,0b00000,0b00000,0b00100,0b01010,0b00100,0b00000,0b00000}, // frame 3
  {0b00000,0b00000,0b00000,0b00000,0b00100,0b01010,0b00100,0b00000}  // frame 4
};

void setup() {
  lcd.begin(16, 2);
  lcd.print("Loading...");
  for (int i = 0; i < 4; i++) {
    lcd.createChar(i, spinnerFrames[i]);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    lcd.setCursor(15, 1);
    lcd.write(i);
    delay(300);
  }
}
