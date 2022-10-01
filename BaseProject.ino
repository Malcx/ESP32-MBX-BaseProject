#include "src/MBX/Base.h"



// ToDO
// SetUp AP with either button on start. No FileExists or touchpin
// OTA updates


// Form has:
// OTA URL
// OTA Cert
// OTA API KEY
// API URL
// API Cert
// API KEY
// Wifi SSID
// WiFi Password
// MDNS
// UUID
// FACTORY RESET - format SPIFFS, but not reset old firmware
// pin for restart in AP mode (i.e. if this is connected on boot)
// Static IP on the network - speeds up wake time!

// Basic parse HTML for screen output on i2c

// RTC memory for fast wake / no spiffs / no serial
// https://diyprojects.io/esp32-store-temporary-data-rtc-memory-deep-sleep/#.YyG267TMKHt

void setup() {

	MBX_init();

//   powerOn();

}

void loop() {
  // put your main code here, to run repeatedly:

}
