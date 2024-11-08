#include <Arduino.h>

int VRxPin = 34; // Analog input pin for X-axis
int VRyPin = 35; // Analog input pin for Y-axis

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Read X and Y axis values
  int xValue = analogRead(VRxPin) - 3100;
  int yValue = analogRead(VRyPin) - 3100;

  // Print the joystick's X and Y values
  Serial.print("X-axis: " + String(xValue));
  Serial.print(" Y-axis: " + String(yValue));

  // Determine direction based on joystick position
  String direction = "";

  // X-axis check (left to right)
  if (xValue < -100) {
    direction += " Left";
  } else if (xValue > 100) {
    direction += " Right";
  } else {
    direction += " Center X";
  }

  // Y-axis check (up to down)
  if (yValue < -100) {
    direction += " Up";
  } else if (yValue > 100) {
    direction += " Down";
  } else {
    direction += " Center Y";
  }

  // Print direction
  Serial.println(" Direction: " + direction);

  // Delay for readability
  delay(100);
}
