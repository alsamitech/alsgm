#ifndef YIN_C_DYNAMIC_ARR
#define YIN_C_DYNAMIC_ARR

/*
 *	Sami Alameddine
 *	Alsami Technologies
 *
 *	Dynamic Array Struct in C
 * */

inline dals_t darr_init(size_t array_init_sz){
	dals_t *t_n2=malloc(sizeof(dals_t));
	t_n2->als_li=malloc(sizeof(int)*array_init_sz);
	t_n2->alloc=array_init_sz;
	t_n2->arr_len=0;

	return t_n2;
}

int grow(dals_t* t){
	assert(t!=NULL);		// Asserts these conditions (just in case something goes wrong and I need to debug, I don't want to lose my last brain cell debugging this)
	assert(t-als_li!=NULL);		// and helps the reader to know what the precoditions are

	type_yin* new_li=malloc(2*t->alloc);		// doubles the amount of memory allocated to the new_li from als_li
	// that makes sure the memory is allocated
	if(newli==NULL)
		return 1; // failiure to allocate
	// security vunerability that I will **totally** fix later
	memcpy(new_li,t->als_li,sizeof(type_yin)*t->arr_len);		// memcpys the contents of the old list into the new list
	free(t->als_li);
	t->als_li=new_li;
	t->alloc *=2;

	return 0;	// sucsess
}

typedef int type_yin;
typedef struct{
	type_yin *als_li;
	size_t arr_len;
	size_t alloc;
} dals_t;

inline darr_init(size_t array_init_sz);

void destroy(dals_t* T);

int grow(dals_t* t);

void print(dals_t* t);

#endif
