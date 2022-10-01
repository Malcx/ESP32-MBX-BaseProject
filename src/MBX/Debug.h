#include <Arduino.h>

void dbg(String message);

void dbg(long message);


void dbg_append(String message);

void dbg_append(long message);
String dbg_get();
bool dbg_hasData();
void dbg_toBrowser();