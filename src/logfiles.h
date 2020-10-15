#ifndef ALSAMI_GAMENGINE_FILEPRGM_HDR
#define ALSAMI_GAMENGINE_FILEPRGM_HDR
#include <stdio.h>
#include <stdlib.h>

int FileInit(const char INIT_MSG[]) {
  FILE *yin;

  // use appropriate location
  yin = fopen("log.ascii", "w+");

  if(yin == NULL) {
    return 1;
  }
  char GM_NAME[] = "undefined";

  fprintf(yin, "Alsami Game Engine v01, %s\nLog and Status:\nInit Message:%s", GM_NAME, INIT_MSG);
  fclose(yin);

  return 0;
}

int WRT_TO_FL(const char msg[]) {
  FILE *YIN;

  YIN = fopen("log.ascii", "a");
  if(YIN==NULL){
    return 1;
  }

  fprintf(YIN,"%s\n", msg);

  fclose(YIN);
  return 0;

}

#endif