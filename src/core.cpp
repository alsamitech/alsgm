#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "expansion.h"
#include "m-sbx.h"
#include "logfiles.h"

#define START ALSAMI_GAME_ENGINE_STRTR

int ALSAMI_GAME_ENGINE_STRTR ();

int main(int argc, char** argv) {

  pthread_t USR_GME;

  SBX* sbX;// = new SBX();
  //sbX->Run();

  FileInit("Initializing Process...");
  
  // Entry point
  int err= ALSAMI_GAME_ENGINE_STRTR ();

  switch(err) {
    case 0:
      break;
    case 1:
      char GEN_ERR[] = "ERROR: Program had an undefined issue and needs to stop.";
      WRT_TO_FL(GEN_ERR);
  }

  pthread_join(USR_GME, NULL);

  // This part just frees memor
  //delete sbX;

  return EXIT_SUCCESS;
}