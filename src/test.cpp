#include "core.h"


void *STRT(void *ptr) {
  WRT_TO_FL("TEST: TEST");
  FRMT_LOG("BOOTED TO ENTRY POINT","This is a test","CRITICAL","DONE",1);
  FRMT_LOG("MODIFY TEST","OFFICIAL ALSGM TEST PROGRAM","DEBUGGING", "SUCSESS",1);
  //LOG_TO_CON(21, "test", -1);

  return NULL;
}
