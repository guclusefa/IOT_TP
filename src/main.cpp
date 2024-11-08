#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor

// Joystick pins
#define JOY_X_PIN 34  // X-axis pin
#define JOY_Y_PIN 35  // Y-axis pin

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHTxx and Joystick test!"));

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Read joystick values
  int joyX = analogRead(JOY_X_PIN);  // Read X-axis
  int joyY = analogRead(JOY_Y_PIN);  // Read Y-axis

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  // Print the sensor readings to the Serial Monitor
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.print(F("°F\n"));

  // Print joystick values
  Serial.print(F("Joystick X: "));
  Serial.print(joyX);  // Raw value of the X-axis
  Serial.print(F("  Joystick Y: "));
  Serial.println(joyY);  // Raw value of the Y-axis
}
