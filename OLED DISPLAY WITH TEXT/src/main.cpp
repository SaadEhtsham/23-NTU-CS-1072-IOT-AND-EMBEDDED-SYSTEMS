/*
 * Name: Saad Ehtsham
 * Registration No: 23-NTU-CS-1072
 * Title: OLED Display with Text and Graphics using ESP32
 */

#include <Wire.h>               // Include the Wire library for I2C communication
#include <Adafruit_GFX.h>       // Include Adafruit graphics library (for basic shapes, text, etc.)
#include <Adafruit_SSD1306.h>   // Include Adafruit library for SSD1306 OLED display

// ---- OLED setup ----
#define SCREEN_WIDTH 128         // OLED display width in pixels
#define SCREEN_HEIGHT 64         // OLED display height in pixels
#define OLED_ADDR 0x3C           // I2C address of the OLED display (0x3C or 0x3D depending on module)

// Create display object using I2C communication
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Wire.begin(21, 22);  // Initialize I2C on ESP32 (SDA=21, SCL=22)

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    // If initialization fails, stay in an infinite loop
    // (Common causes: wrong wiring or incorrect I2C address)
    for (;;);
  }

  display.clearDisplay();  // Clear any previous data on the screen
}

void loop() {

  // ---- Display border rectangle ----
  display.drawRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);  // Draw a rectangle border covering entire screen

  // ---- Display small text (student ID) ----
  display.setTextSize(1);                          // Set text size to small
  display.setTextColor(SSD1306_WHITE);             // Set text color to white
  display.setCursor(2, 5);                         // Set cursor position (x=2, y=5)
  display.println("23-NTU-CS-1072");               // Print student ID
  display.display();                               // Show on display

  // ---- Display larger text (name) ----
  display.setTextSize(2);                          // Set text size to medium-large
  display.setTextColor(SSD1306_WHITE);             // Set text color to white
  display.setCursor(15, 26);                       // Set cursor position for name
  display.println("Saad Ehtsham");                 // Print name
  display.display();                               // Show updated text on display
  delay(2000);                                     // Wait 2 seconds before repeating
}
