#ifndef MBXCONFIG_H
	#define MBXCONFIG_H


	#define CONFIG_PATH "_config.json"


	// MNake these  #defined ?

	const int AP_PIN_ON_BOOT = 14; // If this pin has HIGH on boot then go into setup

	const String AP_SSID = "ESPSetUp";
	const String AP_PASS = "helloworld";
	const String AP_MDNS_Name = "mbx";



	const String BuildName = "MBX Base Project";
	const String BuildVersion = "v0.01";
	const String BuildDate = "20220904";

#endif