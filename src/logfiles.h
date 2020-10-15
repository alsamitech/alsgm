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
/*Formatted Logger*/
int FRMT_LOG(char YIN_ARG_1[],char YIN_ARG_2[],char YIN_ARG_3[],char YIN_ARG_4[],int YINMODE) {
  FILE *FRMT_LG;

  const int FRMT_MD = YINMODE;

  FRMT_LG=fopen("log.ascii", "a");
  if(FRMT_LG==NULL){return 1;}
  if(FRMT_MD==1){
    fprintf(FRMT_LG,"--LOG--\nSTATUS?%s\nINFO: ALSAMI LOGGER(CODENAME YIN RENDERING ENGINE EDITION)\nAPPLICATION MESSAGE?%s\nIMPORTANCE? %s\nEND-LOG (%s)",YIN_ARG_1,YIN_ARG_2,YIN_ARG_3,YIN_ARG_4);    
  } else if(FRMT_MD==2) {

  }
  return 0;
}

#endif