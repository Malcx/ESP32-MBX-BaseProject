#ifndef MBXBASE_H
	#define MBXBASE_H

	#include <ArduinoJson.h>


	#define ESP_TYPE 0
	#if defined ARDUINO_ARCH_ESP8266
		#define ESP_TYPE 8266
	#elif defined ESP32
		#define ESP_TYPE 32
	#endif



	#include "../../_config.h"
	#include "Debug.h"
	#include "FileHandling.h"
	#include "AccessPoint.h"




	void MBX_init();

#endif