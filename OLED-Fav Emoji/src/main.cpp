// =========================
// Name: Saad Ehtsham
// Reg No: 23-NTU-CS-1072
// Title: OLED Display Fav Emoji
// =========================

#include <Wire.h>                 // Library for I2C communication
#include <Adafruit_GFX.h>         // Core graphics library for display handling
#include <Adafruit_SSD1306.h>     // Library for SSD1306 OLED display

// Define OLED display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create display object using I2C communication
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Declare the function before using it in setup()
void drawCoolFace();

void setup() {
  // Initialize the OLED display with address 0x3C
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    // If the display is not detected, stay here forever
    for (;;);
  }

  display.clearDisplay();   // Clear any previous data on the screen
  drawCoolFace();           // Call the function to draw the cool emoji
  display.display();        // Render the drawn graphics to the OLED
}

void loop() {
  // The display is static, no continuous updates required
}

// Function to draw a "cool face" emoji
void drawCoolFace() {
  int centerX = SCREEN_WIDTH / 2;   // Center of the OLED horizontally
  int centerY = SCREEN_HEIGHT / 2;  // Center of the OLED vertically
  int faceRadius = 20;              // Radius of the circular face

  // Draw the circular outline of the face
  display.drawCircle(centerX, centerY, faceRadius, SSD1306_WHITE);

  // Draw sunglasses
  display.fillRect(centerX - 10, centerY - 6, 8, 4, SSD1306_WHITE); // Left lens
  display.fillRect(centerX + 2, centerY - 6, 8, 4, SSD1306_WHITE);  // Right lens
  display.drawLine(centerX - 2, centerY - 4, centerX + 2, centerY - 4, SSD1306_WHITE); // Bridge of glasses

  // Draw a curved smile using pixel plotting
  for (int x = -8; x <= 8; x++) {
    int y = (x * x) / 10;  // Parabolic curve equation for smile shape
    display.drawPixel(centerX + x, centerY + 6 - y, SSD1306_WHITE);
  }
}
