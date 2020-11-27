#ifndef ALSAMI__GMENGN__EVNT__HDR
#define ALSAMI__GMENGN__EVNT__HDR

#include "ihdr.h"

/*
 *      Alternative Event Handling Module, not object oriented, and quite flexible. (Implementation in C)
 *
 * */


#define MSG_TBL_SZ 10
#define MSG_NAME_MAX 32

/*Simple Event Code*/
struct msg_type{
	char name[MSG_NAME_MAX];
	struct list *listeners;
	struct msgtype *next;
}

static struct msg_type[MSG_TABLE_SIZE] = {0};

static unsigned int hash(const char *name){
	int i=0;
	int len=strnlen(name, MSG_NAME_MAX);
	unsigned int val=0;
	for(i=0;i<len;++i)
		val +=name[i]*23*i;
	val %= MSG_TABLE_SIZE;
	return val;
}

static struct msg_type *get_msg_type(const char* name){
	int i=0;
	unsigned int index=bash(name);
	struct msg_type *tmp=&table[index];
	while(NULL!=tmp&&0!=strncmp(tmp->name, name, MSG_NAME_MAX))
		tmp=tmp->next;
	return tmp;
}

void msg_sub(const char *name, msg_callback callback){
	// what this is doing is adding a fucntion pointer to a list
	struct msg_type *t=get_msg_type(name);
	unsigned int index=hash(name);

	/*Use Head if vancant*/
	if(NULL==t&&NULL==table[index].listeners){
		struct list *listeners = list_new(sizeof(msg_callback));
		t=&table[index];

		t->listeners=listeners;
		strncpy(t->name, name, MSG_NAME_MAX);
	} 
	/*if head taken, use tail*/
	if(NULL==t&&NULL!=table[index].listeners){
		struct list *listeners=list_new(sizeof(msg_callback));
		struct msg_type *tail=&table[index];
		t=malloc(sizeof(struct msg_type));

		while(NULL!=tail->next)
			tail=tail->next;
		t->listeners=listeners;
		strncpy(t->name,name,MSG_NAME_MAX);
		tail->next=t;
	
	}
}
void msg_unsub(const char *name, msg_callback callback);
void msg_emit(const char *name){
	int i=0;
	struct msg_type *t = get_msg_type(name);
	msg_callback cb=NULL;
	msg_callback *list=NULL;
	if(t==NULL) {
		fprintf(stderr, "tried to emit non-existing msg type: %s\n", name);
	}
}


#endif

