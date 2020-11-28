#ifndef ALSGM_LOGCON_H
#define ALSGM_LOGCON_H

#include "ihdr.h"
#include <time.h>

// Bit Feild Defines
#define GM_CLOG_TIME 0x01	// 0b00000001
#define GM_CLOG_WHDR 0x02	// 0b00000010
#define GM_CLOG_TIME 0x04	// 0b00000100
#define GM_CLOG_ERR 0x08	// 0b00001000

uint8_t gm_logtocon(const char* msg, uint8_t flags){

	if(flags&GM_CLOG_WHDR){
#ifdef APP_NAME
		printf("%s LOG (AlsGM)\n", APP_NAME);
#else
		printf("Game Log (AlsGM Engine)\n");
#endif
	}
	if(flags&GM_CLOG_ERR){
		printf("\033[1;31m%s\033[0m\n", msg);
	}else{}

}

#endif
