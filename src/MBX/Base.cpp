#include "Base.h"




RTC_DATA_ATTR int recordCounter = 0;

void MBX_init(){



	/* Set the serial type based on esp type 
	Theese seeme to be the main / usual settings */
	if(ESP_TYPE == 32)
		Serial.begin(115200);
	else
		Serial.begin(74880);

	/* Output some application settings */
	dbg("===================");
	dbg(BuildName);
	dbg("Version  : " + BuildVersion);
	dbg("Date     : " + BuildDate);
	dbg("ESP_TYPE : " + String(ESP_TYPE));
	dbg("===================");

	dbg("recordCounter: " + String(recordCounter));



	if(recordCounter == 0)
	{
		// Mounting SPIFFS takes 100ms
		mountSpiffs();

		File confFile = SPIFFS.open(CONFIG_PATH, "r");
	 	if (!confFile) {
	 		dbg("-> No config file found.");
	 		dbg("-> Entering AP Setup ");
	 		dbg("   - SSID : " + AP_SSID);
	 		dbg("   - PASS : " + AP_PASS);
		} 

	}
	dbg("Uptime: ");
	dbg(esp_timer_get_time());


	recordCounter++;
	unsigned long sleepTime = 0.1 * 60e6; // 6 seconds
  	ESP.deepSleep(sleepTime);

	/*
	
	LittleFS.begin();
	File file = LittleFS.open("/_config.txt", "r");
	if(!file){
		Serial.println("Entering AP - no config file found.");
	}
	File file = LittleFS.open("/_config.txt", "r");
	if(!file){
		Serial.println("Entering AP - no config file found.");
	}
	*/
}
