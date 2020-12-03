#ifndef ALSAMI_GAME_ENGINE_EXPANDER_API_HDR
#define ALSAMI_GAME_ENGINE_EXPANDER_API_HDR

#include "ihdr.h"


/*WARNING TO ALSGM MODULE DEVELOPERS!
 *DO NOT PLAY WITH THE ASSGN_MODULEID_COUNT VARIABLE! However, it is kept public for the sake of ID handling extensions*/



static int count=0;


class Module{
  public:
    Module(){}
    virtual ~Module(){}
    unsigned int MODULE_ID;
    //uint16_t assgn_moduleid_count;
};

void module_id_assign(Module* mod_i){
	mod_i->MODULE_ID=count++;
}

#endif
