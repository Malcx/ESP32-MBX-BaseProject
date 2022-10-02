#include "FileHandling.h"



void mountSpiffs(){

    while(!SPIFFS.begin()){
      dbg("SPIFFS Error - reformatting.");
      bool formatted = SPIFFS.format();
      if ( formatted ) {
	      dbg("SPIFFS formatted successfully");
        SPIFFS.begin();
      }
    }
    dbg("SPIFFS mounted");
}



bool writeFile(String fname, String str)
{
  deleteFile(fname);

  dbg("Writing file '" + fname + "' with contents : " +str);
  File f = SPIFFS.open(fname, "w");
    if (!f)
    {
      dbg("file open failed");
      return false;
    }
    else
    {
      int bytesWritten = f.print(str);
      f.close();
    }
    return true;
}






String readFile(String fname)
{

  String str = "";
  File f = SPIFFS.open(fname, "r");
  if (!f) {
    dbg("Failed to open file for reading");
    return "MBX_UNDEFINED";
  }
  while (f.available()) {
    str += char(f.read());
  }

  return str;
}

bool deleteFile(String fname)
{
    return SPIFFS.remove(fname); // delete the file
}

