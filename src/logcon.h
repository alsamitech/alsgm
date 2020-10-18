#ifndef GMENGN_LOGINTOCON
#define GMENGN_LOGINTOCON

#include "ihdr.h"

/*
 *	Author's Notes:
 *		a uchar is just an unsigned char datatype, as defined in the integrated header copybook (ihdr.h) 
 *		uchars only use 1 byte or less, which makes them perfect choice for number-based configuration opetions.
 *		So instead of a function call looking like this
 *
 * 		YIN_EXAMPLEFUNCTIONTOCALL("the string to do stuff with", "the mode");
 *
 * 		It will look like this
 *
 * 		YIN_EXAMPLEFUNCTIONTOCALL("the const char* to stuff with", 69);
 *
 * 		This just saves memory and it a good idea just for the sake of efficiency.
 *
 *
 * */

uchar LOG_TO_CON(uchar YIN_TYPE, const char* MSG, uchar IMP){
	switch(YIN_TYPE){
		/*1 would just mean that it is a standard thing to log to console (ie. "Processing Message" or "Got that keypress (key x)")*/
		case 1:
			frpintf(stdout,"ALSGM-LOG\nApplication Process: %s\n", MSG);
			break;
		/*2 would be an application complaint like "I can't find that saved map!!!" or "The Program is almost out or RAM"*/
		case 2:
		/*the type 20 is reserved specifically for core console complaints/logs*/
		case 20:
			fprintf("CODENAME YIN\nCORE-MODULE-LOG: %s\n", MSG);
			
	}
}

#endif
