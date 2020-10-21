#include "logfiles.h"
#include "logcls.h"

static std::shard_ptr<Logger>Log::s_CoreLogger;
static std::shard_ptr<Logger>Log::ClientLogger();

void Init(){
	FRMT_LOG("INITIALIZING LOG CLASS","STAMP: VOID INIT IN YIN RENDERING ENGINE","LOW","NULL");
}
