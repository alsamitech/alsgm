#ifndef ALASAMI_GM_SANDBOX_MODULE
#define ALASAMI_GM_SANDBOX_MODULE
#include "ihdr.h"
#include "expansion.h"
#include "pthread.h"

#define GSBXD_ANDRUN 0x01

/*
 *	This is the sandbox Module. This Module can be swapped for a C implementation.
 *
 * */

class SBX: public Module{
  public:
    pthread_t thread;
    void (*module_callback)(int resp);
    uint16_t Run();
    static void* srun(void *Yin);
    SBX(){
	    module_id_assign(this);
    }
    ~SBX(){
      // Free all the memory taken up by the sandbox
    }
    void dispatch(uint8_t flags);
};

void SBX::dispatch(uint8_t flags){
    pthread_create(&thread, NULL, srun, NULL);
}

void* SBX::srun(void *Yin){
    //SBX::Run();
    //this->Run();
    return NULL;
}

#endif
