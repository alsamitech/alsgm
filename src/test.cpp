#include "core.h"


void *STRT(void *ptr) {
  WRT_TO_FL("TEST: TEST");
  FRMT_LOG("BOOTED TO ENTRY POINT","THis is a test","CRITICAL","DONE",1);  
  LOG_TO_CON(21, "Yin is very fucking hot i cant anymore", 21);

  return NULL;
}
