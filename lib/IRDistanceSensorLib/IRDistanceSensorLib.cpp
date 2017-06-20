#include <Arduino.h>
#include "IRDistanceSensorLib.h"

/**
 * @file IRDistanceSensorLib.cpp
 * @author Benjamin Boortz <benjamin.boortz@secure.mailbox.org>
 * @version 1.0
 */



IRDistanceSensor::IRDistanceSensor() {
	// initialize variables
	_sensorPin= DEFAULT_SENSOR_PIN;
}

IRDistanceSensor::IRDistanceSensor(uint8_t sensorPin) {
	// initialize variables
	_sensorPin= sensorPin;
}


boolean IRDistanceSensor::isInRange() {
	int sensorValue = analogRead (_sensorPin);

	if (sensorValue < 100) {
		return true;
	}

	return false;
}
