#ifndef FILEHANDLING_H
	#define FILEHANDLING_H


	#include "Base.h"
	#include "SPIFFS.h"

	void mountSpiffs();
	bool writeFile(String fname, String str);
	String readFile(String fname);
	bool deleteFile(String fname);

#endif