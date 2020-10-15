#ifndef ALSAMI_GAMENGINE_FILEPRGM_HDR
#define ALSAMI_GAMENGINE_FILEPRGM_HDR

int FilesInit(const char INIT_MSG) {
  FILE *yin;

  // use appropriate location
  yin = fopen("log.ascii");

  if(fptr == NULL) {
    return 1;
  }

  printf(yin, "Alsami Game Engine v01, %s\nLog and Status:\nInit Message:%s", GM_NAME, INIT_MSG);
  fclose(yin);

  return 0;
}

#endif