#ifndef MBXBASE_H
	#define MBXBASE_H

	#include <ArduinoJson.h>


	#define ESP_TYPE 32


	#include "../../_config.h"
	#include "Debug.h"
	#include "FileHandling.h"
	#include "AccessPoint.h"




	void MBX_init();
	void MBX_sleep(unsigned long sleepTime);

#endif