#ifndef _IRDISTANCE_SENSOR_LIB_
#define _IRDISTANCE_SENSOR_LIB_


#include <Arduino.h>


#define DEFAULT_SENSOR_PIN A0


class IRDistanceSensor {

	public:

		IRDistanceSensor();
		IRDistanceSensor(uint8_t);

		boolean isInRange();

	private:

		//	VARIABLES
		uint8_t _sensorPin;

		//	CONSTANTS
};


#endif
