#ifndef ALSAMI_GAMENGINE_FILEPRGM_HDR
#define ALSAMI_GAMENGINE_FILEPRGM_HDR

#include "ihdr.h"

typedef struct LOGGER_STRUCT{
	char* msg;
} logger_T;

logger_T* init_logger(char* msg_src){
	logger_T* logger=(logger_T*)calloc(1, (sizeof(LOGGER_STRUCT)+strlen(msg_src)));
	logger->msg=msg_src;

	return logger;
}

void logger_destroy(logger_T* logger){
	free(logger);
}

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

char* gm_read_file(char* filename){
	char* buffer=0;
	long f_len;
	FILE* gmf=fopen(filename, "rb");

	if(gmf){
		fseek(gmf, 0, SEEK_END);
		f_len=ftell(gmf);

		buffer=(char*)calloc(f_len, f_len);
		
		if(buffer)
			fread(buffer, 1, f_len, gmf);

		fclose(gmf);
	}
}

int WRT_TO_FL(const char* msg) {
  FILE *YIN;

  YIN = fopen("log.gm", "a");
  if(YIN==NULL){return 1;}

  fprintf(YIN,"%s\n", msg);
  fclose(YIN);
  return 0;

}
/*Formatted Logger (deprecated)*/
int FRMT_LOG(char YIN_ARG_1[],char YIN_ARG_2[],char YIN_ARG_3[],char YIN_ARG_4[],int YINMODE) {
  FILE *FRMT_LG;

  const int FRMT_MD = YINMODE;

  FRMT_LG=fopen("log.ascii", "a");
  if(FRMT_LG==NULL){return 1;}
  switch(FRMT_MD) {
    case /* {NOTE: ill see what I did wrong later but the c++ compiler hates me}GAME_ENGINE_COMPLAINT_STDLOG*/1:
      fprintf(FRMT_LG,"--LOG--\nSTATUS?%s\nINFO: AlsGM LOGGER\nAPPLICATION MESSAGE?%s\nIMPORTANCE? %s\nEND-LOG (%s)",YIN_ARG_1,YIN_ARG_2,YIN_ARG_3,YIN_ARG_4);
      break;
    case GAME_ENGINE_LFT_CMPLNT_FR_APP:
        // TODO: We Should finish this before the year (insert 64 bit integer limit here).
        break;
    case GAME_ENGINE_LFT_CMPLNT_CORE_MODULE:
        fprintf(FRMT_LG, "ERROR FROM CORE MODULE, REPORT TO https://github.com/alsamitech/alsgm and the game developer ASAP IF NO SOLOUTION IS FOUND\nError Message: %s\n--errno--", YIN_ARG_1);
        break;
    case 23:
      fprintf(FRMT_LG,"%s", YIN_ARG_1);
  }
  return 0;
  fclose(FRMT_LG);
}

// i will finish this later i promise
/*unsigned char loge(const char* fmt, ...) {
	FILE *fnx;
	va_list ap;
	char out[512];
	if(FRMT_LOG==NULL){return 1;}
	struct tm tm ={0};
	char *after_date=&out[22];
	tm=*localtime(&tm);
	strftime(out, 22, "%Y-%m-%d:%H:%M:%S",&tm);
	*out[21]= ' ';
	strcpy(after_date,"[ERROR]");
	fnx=fopen("session.log", "w+");
	va_start(ap,fmt);
	vsprintf(after_date+0, fmt, ap);
	va_end(ap);
	out[28]=' ';
	fprintf(stdout, "%s\n", out);
	fprintf(fnx, "%s\n", out);
	// vfprintf(stdout, fmt, ap);

	fclose(fnx);
	return 1;
}
unsigned char logi(const char *fmt, ...){
	FILE *fnx;
	va_list ap;
	char *out[512];
	if(FRMT_LOG==NULL){return 1;}
	struct tm tm ={0};
	char *after_date=out[22];
	tm=*localtime(&tm);
	strftime(out, 22, "%Y-%m-%d:%H:%M:%S",&tm);
	*out[21] = ' ';
	strcpy(after_date,"[ERROR]");
	fnx=fopen("session.log", "w+");
	va_start(ap,fmt);
	vsprintf(after_date+0, fmt, ap);
	va_end(ap);
	*out[28]=' ';
	fprintf(stdout, "%s\n", out);
	fprintf(fnx, "%s\n", out);
	// vfprintf(stdout, fmt, ap);

	fclose(fnx);
	return 1;
}*/
#endif
