#ifndef ALSGM_CORE_API_GAMINGDIV_CORE_MODULE
#define ALSGM_CORE_API_GAMINGDIV_CORE_MODULE

typedef struct COREAPI_STRUCT{
	/*descriptor*/int d;
	void (*PROC_CALLBACK)();
} coreapi_T;

coreapi_T* corealloc(void (*nPROC_CALLBACK)()){
	coreapi_T* coreapi_i=(coreapi_T*)calloc(1, sizeof(struct COREAPI_STRUCT));

	return coreapi_i;
}

#endif
