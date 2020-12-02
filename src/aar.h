#ifndef ALSGM_ARR
#define ALSGM_ARR

/*
 *	AlsGM Dyanmic Array of any type
 *
 *	uses a void** pointer
 * */

#define darray_del(x) free(x)

#ifdef __cplusplus
extern "C" {
#endif

typedef struct DYANMIC_ARR_STRUCT{

	size_t size;
	size_t item_size;
	void** items;
}darray_T;

darray_T* darr_alloc(size_t init_size){
	darray_T* darray_i=(darray_T*)calloc(1, sizeof(darray_T));
	darray_i->item_size=init_size;
	darray_i->size=0;

	return darray_i;
}

void* darr_append(darray_T* darray_i, void* item){
	darray_i->size++;
	darray_i->items=(void**)realloc(darray_i->items, darray_i->size*darray_i->item_size);
	
	darray_i->items[darray_i->size-1]=item;

	return item;	
}

void darr_shift_left(darray_T* darray_i, int index){}

// Ill make a remove function later

void darr_free(darray_T* darray_i, void (*free_method)(void* item)){

}

#ifdef __cplusplus
}
#endif

#endif	// ALSGM_ARR
