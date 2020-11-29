#include "core.h"
#include "logcon.h"

uint8_t gm_logtocon(const char* msg, uint8_t flags);
// NOTE: This is just for testing out specific headers, not the entire thing (useful when in a long debug session)
void* STRT(void* Yin){
	gm_logtocon("test", GM_CLOG_WHDR|GM_CLOG_ERR);
}
