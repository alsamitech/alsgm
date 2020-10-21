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
 * 		A complaint happens when a process wants to ask the user to fix a case of user-error if the program wants to log a potentical unknown bug, it should log to the file instead of the console. A complaint is differnt than a log. A log is meant to to inform the user that something is happening, a complaint is meant to complain to the suer that something is not working and may be a pottential case of end-suer error.
 * */


// unsigned char Log To COnsole args: unsigned char yin type(just the type of varibale) const char* msg and the imporntace variable)
uchar LOG_TO_CON(uchar YIN_TYPE, const char* MSG, uchar IMP){
	switch(YIN_TYPE){
		/*1 would just mean that it is a standard thing to log to console (ie. "Processing Message" or "Got that keypress (key x)")*/
		case 1:
			fprintf(stdout,"ALSGM-LOG\nApplication Process: %s\n", MSG);
			break;
		/*2 would be an application complaint like "I can't find that saved map!!!" or "The Program is almost out or RAM"*/
		case 2:
			fprintf(stdout,"ALSGM-LOG\nAPPLICATION SENT A COMPLAINT\nREAD THE MESSAGE AND FIX THE ISSUE TO PREVENT THIS WARNING\n%s\n\n--Alsami Technologies - alsgm (Codename Yin)--");
			break;

		/*the type 20 is reserved specifically for core console complaints/logs*/
		case 20:
			fprintf(stderr,"CODENAME YIN\nCORE-MODULE-LOG: %s\nIMPORTANCE: %u\n", MSG,IMP);
			break;
		/*The type 21 means that a core module is complaining to the user*/
		case 21:
			fprintf(stderr,"ERROR OF URGENCY %u\nA CORE MODULE IS COMPLANING\n%s)");
			break;
	}
}

#endif
