#ifndef ALSGM_QUEUE_H
#define ALSGM_QUEUE_H

#include "ihdr.h"

#define EVM_TICK 2
#define EVM_INITALIZE 3
#define EVM_MOUSECLICK 4

typedef struct EVTOKEN_STRUCT{
    enum{
		INITALIZE,CREATE,TICK,WINDOWEXPOSE,MOUSECLICK,WINDOWRESIZE
	}type;
} evtoken_T;

evtoken_T* evtoken_init(){
    evtoken_T* yintoken_i=(evtoken_T *) calloc(1, sizeof(evtoken_T));

    return yintoken_i;
}

void evtoken_destroy(evtoken_T* evtoken_i){
    free(evtoken_i);
}

typedef struct EVENT_STRUT{
	evtoken_T token;
}event_T;

event_T* gm_init_event(){
	event_T* event_i=(event_T*)calloc(1,sizeof(event_T));

	return event_i;
}

void gm_destroy_event(event_T* event_i){
    free(event_i);
}

evtoken_T* gm_parse_event(event_T* event_i, void (*msg_callback)(u_int32_t)){
    switch(event_i->token.type){
    case INITALIZE:
        WRT_TO_FL("AlsGM event INITALIZE: a event was created");
        msg_callback(EVM_INITALIZE);
        break;
    case TICK:
        msg_callback(EVM_TICK);
    }
}



#endif
