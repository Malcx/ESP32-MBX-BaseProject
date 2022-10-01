#include "Debug.h"


const int mbx_debugStackSize = 32;
String mbx_debugStack[mbx_debugStackSize];
int mbx_debugIndex = 0;
char dbgbuf[128];
String dbg_res = "";


void dbg(String message){
	Serial.println(message);
	
	mbx_debugStack[mbx_debugIndex] = message;
	mbx_debugIndex++;
	if(mbx_debugIndex == mbx_debugStackSize)
	{
		for(int i=2; i<mbx_debugStackSize; i++)
			mbx_debugStack[i - 1] = mbx_debugStack[i];
		mbx_debugIndex--;
		mbx_debugStack[0] = "--Debug Log Truncated";
	}
}


void dbg(long message){
	sprintf(dbgbuf, "%i", message);
	dbg(dbgbuf);
}



void dbg_append(String message){
	mbx_debugIndex--;
	if(mbx_debugIndex < 0)
		mbx_debugIndex = 0;

	mbx_debugStack[mbx_debugIndex] = mbx_debugStack[mbx_debugIndex] + message;

	mbx_debugIndex++;
}


void dbg_append(long message){
	sprintf(dbgbuf, "%i", message);
	dbg_append(dbgbuf);
}


String dbg_get(){
	if(mbx_debugIndex == 0)
		return "";

	dbg_res = "";
	for(int i = 0; i < mbx_debugIndex; i++)
	{
		dbg_res += mbx_debugStack[i] + "\n";
		mbx_debugStack[i] = "";
	}
	mbx_debugIndex = 0;
	return dbg_res;
}

bool dbg_hasData(){
	if(mbx_debugIndex == 0)
		return false;
	return true;	
}

void dbg_toBrowser(){
/*
 	if(dbg_hasData())
    	sendResponse(dbg_get());
	else
	    sendResponse("");
	    */
}