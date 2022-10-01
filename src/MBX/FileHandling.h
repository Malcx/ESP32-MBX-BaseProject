#ifndef FILEHANDLING_H
	#define FILEHANDLING_H


	#include "Base.h"

	#if ESP_TYPE == 32
		#include "SPIFFS.h"
	#else
		#include <FS.h>
	#endif

	void mountSpiffs();
	bool writeFile(String fname, String str);
	String readFile(String fname);
	bool deleteFile(String fname);

#endif