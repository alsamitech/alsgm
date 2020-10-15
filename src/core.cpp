#include <GL/gl.h>
#include <stdlib.h>
#include "expansion.h"
#include "m-sbx.h"
#include "logfiles.h"

#define START ALSAMI_GAME_ENGINE_STRTR

int ALSAMI_GAME_ENGINE_STRTR ();

int main() {

  SBX* sbX;// = new SBX();
  //sbX->Run();

  FileInit("Initializing Process...");

  int err= ALSAMI_GAME_ENGINE_STRTR ();

  switch(err) {
    case 0:
      break;
    case 1:
      char GEN_ERR[] = "ERROR: Program had an undefined issue and needs to stop.";
      WRT_TO_FL(GEN_ERR);
  }

  // This part just frees memor
  //delete sbX;

  return EXIT_SUCCESS;
}