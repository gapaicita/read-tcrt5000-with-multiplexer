#include "Pins.h"
#include "Sensor.h"

void setup() {
  Serial.begin(115200);
  sensorInit();
}

void loop() {
  readSensor();
  dataSensor = 0b00000;
  delay(100);
}
