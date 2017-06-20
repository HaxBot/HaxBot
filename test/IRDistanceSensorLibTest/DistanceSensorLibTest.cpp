#include <Arduino.h>
#include "IRDistanceSensorLib.h"


#define SENSOR_PIN A0
#define LED_PIN 13


IRDistanceSensor irds = IRDistanceSensor(SENSOR_PIN);

void setup() {
	Serial.println("### START TESTCASE ###");

	Serial.begin(115200);
	delay(1000);
}

void loop() {
	boolean range = irds.isInRange();
	Serial.println(range);

	delay(100);

}

