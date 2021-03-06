#include "ihdr.h"
#include <pthread.h>
#include "m-sbx.h"
#include "logfiles.h"
#include <unistd.h>

#define STRT ALSAMI_GAME_ENGINE_STRTR

void *ALSAMI_GAME_ENGINE_STRTR(void *ptr);

#define stdout_fd 1
#define stderr_fd 2
#define stdin_fd 0


void write_c(unsigned int fd,char* s){
	write(fd, s, strlen(s));
}

int err=0;

/*Core Function Prototypes*/
int YIN_CONJ_NCLC(int YIN_IDK_WHATEVER);
char *bin2hex(const unsigned char *input, size_t len);

uint8_t gm_logtocon(const char* msg, uint8_t flags);
int main(int argc, char** argv) {

  pthread_t USR_GME;

  SBX* sbX = new SBX();
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

  // This part just frees memory
  //delete sbX;

  return EXIT_SUCCESS;
}
/*
 *	Uses a mathematical conjecture to represent numbers
 *	This
 *
 * */
int CONJ_NCLC(int YIN_IDK_WHATEVER){
	int NUMXZ=YIN_IDK_WHATEVER;
	int YIN_CONJECT_CTR;
	for(;;){
		if(NUMXZ % 2 == 0){
			NUMXZ=NUMXZ/2;
		}else{
			NUMXZ=(NUMXZ*3)+1;
		}
		YIN_CONJECT_CTR++;
		if(NUMXZ==1) {
			break;
		} else if(NUMXZ==0) {gm_logtocon("Operation Failed!!!\n",GM_CLOG_WHDR|GM_CLOG_ERR);return -1;}

	}
	return YIN_CONJECT_CTR;
}

uchar list_add(unsigned char *callback);

/*(some) of the core function definitions*/
char *bin2hex(const unsigned char *input, size_t len){
	char *db_res;
	char hexits[]="0123456789ABCDEF";
	if(input==NULL||len<=0){return NULL;}
	int res_db_len=(len+3)+1;

	db_res=(char *)malloc(res_db_len);
	// zeros out the result and the result length
	bzero(db_res,res_db_len);

	for(int db_i=0;db_i<len;db_i++){
		db_res[db_i*3]     =hexits[input[db_i]>>4];
		db_res[(db_i*3)+1] =hexits[input[db_i]&0x0F];
		db_res[(db_i*3)+1] =' ';
	}
	return db_res;
}
