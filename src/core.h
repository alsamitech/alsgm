#include "ihdr.h"
#include "expansion.h"
#include "m-sbx.h"
#include "logfiles.h"

#define STRT ALSAMI_GAME_ENGINE_STRTR

void *ALSAMI_GAME_ENGINE_STRTR(void *ptr);

int err=0;

int main(int argc, char** argv) {

  pthread_t USR_GME;

  SBX* sbX;// = new SBX();
  //sbX->Run();

  FileInit("Initializing Process...");
  
  // Entry point
  pthread_create(&USR_GME, NULL, &ALSAMI_GAME_ENGINE_STRTR, NULL);

  switch(err) {
    case 0:
      break;
    case 1:
      char GEN_ERR[] = "ERROR: Program had an undefined issue and needs to stop.";
      WRT_TO_FL(GEN_ERR);
      break;
  }

  pthread_join(USR_GME, NULL);

  // This part just frees memor
  //delete sbX;

  return EXIT_SUCCESS;
}