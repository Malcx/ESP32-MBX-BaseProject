#include "Base.h"




RTC_DATA_ATTR int bootCounter = 0;

void MBX_init(){




	/* Set the serial type based on esp type 
	Theese seeme to be the main / usual settings */
	if(ESP_TYPE == 32)
		Serial.begin(115200);
	else
		Serial.begin(74880);




	pinMode(AP_PIN_ON_BOOT, INPUT_PULLDOWN);
	int goToAPModeButton = digitalRead(AP_PIN_ON_BOOT);

		dbg("Button value was: ");
		dbg(goToAPModeButton);

	if(goToAPModeButton == 1)
	{
		MBX_goAP("Button press on boot.");
	}


	if(bootCounter == 0)
	{
		/* Output some application settings */
		dbg("===================");
		dbg(BuildName);
		dbg("Version  : " + BuildVersion);
		dbg("Date     : " + BuildDate);
		dbg("ESP_TYPE : " + String(ESP_TYPE));
		dbg("===================");
		dbg("bootCounter: " + String(bootCounter));
	}




	if(bootCounter == 0)
	{
		// Mounting SPIFFS takes about 100ms
		mountSpiffs();

		File confFile = SPIFFS.open(CONFIG_PATH, "r");
	 	if (!confFile) {
	 		dbg("-> No config file found.");
			MBX_goAP("No config file found at: " + String(CONFIG_PATH));
		} 
	}





	bootCounter++;

	unsigned long sleepTime = 0.1 * 60e6; // 6 seconds
	MBX_sleep(sleepTime);
}

void MBX_sleep(unsigned long sleepTime){

	dbg("Awake time in milliseconds: ");
	dbg(esp_timer_get_time() / 1000);

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
