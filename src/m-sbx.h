#ifndef ALASAMI_GM_SANDBOX_MODULE
#define ALASAMI_GM_SANDBOX_MODULE
#include "expansion.h"

/*
 *	This is the sandbox Module. This Module can be swapped for a C implementation.
 *
 * */

class SBX: public Module{
  public:
    SBX(){
      
    }
    ~SBX(){
      // Free all the memory taken up by the sandbox
    }
};
