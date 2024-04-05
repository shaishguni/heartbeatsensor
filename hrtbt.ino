#include <Wire.h>
#include <U8g2lib.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

const int pressurePin = A0;

void setup() {
  Serial.begin(9600);

  // Initialize OLED display
  u8g2.begin();

  // No specific initialization for pressure sensor
}

void loop() {
  // Read pressure sensor data
  int pressureValue = analogRead(pressurePin);

  // Calibrate the pressure sensor reading
  int calibratedValue = map(pressureValue, 0, 1023, 60, 180); // Simulate blood pressure in mmHg

  // Display calibrated pressure sensor data on OLED
  displayBloodPressure(calibratedValue);

  // Wait a moment before the next loop iteration
  delay(500);
}

// Function to display the blood pressure on the OLED screen
void displayBloodPressure(int calibratedValue) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);

  // Display the calibrated blood pressure value
  u8g2.setCursor(0, 15);
  u8g2.print(F("Blood Pressure: "));
  u8g2.setCursor(0, 30);
  u8g2.print(calibratedValue);
  u8g2.print(F(" mmHg"));

  u8g2.sendBuffer();
}
