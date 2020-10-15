#include <GL/gl.h>
#include <stdlib.h>

#define START ALSAMI_GAME_ENGINE_STRTR



int main() {

  FilesInit();

  int err = ALSAMI_GAME_ENGINE_STRTR();

  switch(err) {
    case 0:
      break;
  }

  return 
}