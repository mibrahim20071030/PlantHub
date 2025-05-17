#include <LiquidCrystal.h>
#include <Stepper.h>

// LCD setup: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Stepper setup: steps per revolution, and IN1–IN4 pins
const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); // IN1, IN3, IN2, IN4

// Spinner frames for LCD animation
byte spinnerFrames[4][8] = {
  {0b00000,0b00100,0b01010,0b00100,0b00000,0b00000,0b00000,0b00000}, // frame 1
  {0b00000,0b00000,0b00100,0b01010,0b00100,0b00000,0b00000,0b00000}, // frame 2
  {0b00000,0b00000,0b00000,0b00100,0b01010,0b00100,0b00000,0b00000}, // frame 3
  {0b00000,0b00000,0b00000,0b00000,0b00100,0b01010,0b00100,0b00000}  // frame 4
};

void setup() {
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.print("Stepper Init");

  // Create custom characters
  for (int i = 0; i < 4; i++) {
    lcd.createChar(i, spinnerFrames[i]);
  }

  // Initialize Stepper Motor
  myStepper.setSpeed(10);  // 10 RPM

  delay(2000);
}

void loop() {
  // Forward
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Fwd + Spin");

  // Animate and rotate forward
  for (int step = 0; step < stepsPerRevolution; step += 64) {
    lcd.setCursor(15, 1);
    lcd.write((step / 64) % 4);
    myStepper.step(64);   // move 64 microsteps
    delay(10);
  }

  delay(500);

  // Backward
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bwd + Spin");

  for (int step = 0; step < stepsPerRevolution; step += 64) {
    lcd.setCursor(15, 1);
    lcd.write((step / 64) % 4);
    myStepper.step(-64);
    delay(10);
  }

  delay(500);
}
