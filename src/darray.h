#ifndef GM_C_DYNAMIC_ARR
#define GM_C_DYNAMIC_ARR

/*
 *	Dynamic Array Handling for AlsGM
 * */

typedef int type_yin;
typedef struct{
	type_yin *als_li;
	size_t arr_len;
	size_t alloc;
} dals_t;

inline dals_t* darr_init(size_t array_init_sz);

inline dals_t* darr_init(size_t array_init_sz){
	dals_t *t_n2= (dals_t*) malloc(sizeof(dals_t));
	t_n2->als_li=(type_yin *) malloc(sizeof(type_yin)*array_init_sz);
	t_n2->alloc=array_init_sz;
	t_n2->arr_len=0;

	return t_n2;
}

int darr_grow(dals_t* t){
	assert(t!=NULL);		// Asserts these conditions (just in case something goes wrong and I need to debug, I don't want to lose my last brain cell debugging this)

	assert(t->als_li!=NULL);		// and helps the reader to know what the preconditions are

	type_yin* new_li=(type_yin*) malloc(2*t->alloc);		// doubles the amount of memory allocated to the new_li from als_li
	// that makes sure the memory is allocated
	if(new_li==NULL)
		return 1; // failiure to allocate
	// security vunerability that I will **totally** fix later
	memcpy(new_li,t->als_li,sizeof(type_yin)*t->arr_len);		// memcpys the contents of the old list into the new list
	free(t->als_li);
	t->als_li=new_li;
	t->alloc *=2;

	return 0;	// Operation Sucsessful
}

type_yin darr_append(dals_t *t, type_yin val){
	if(t->arr_len > t->alloc-1){assert(darr_grow(t)!=0);}
	// refernces the link, and does the side effect of iincrementing the value. It returns the old value, which is the first slot in the array
	t->als_li[t->arr_len++]=val;
	return val;}

void destroy(dals_t* T){free(T->als_li);free(T);}

int darr_grow(dals_t* t);

void darr_print(dals_t* t);

#endif
