#include "AccessPoint.h"

void MBX_goAP(String reason){

      dbg("-> Entering AP Setup ");
      dbg("-> Due to -> " + reason);
      dbg("   - SSID : " + AP_SSID);
      dbg("   - PASS : " + AP_PASS);
}
