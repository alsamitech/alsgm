#ifndef GMENGN_XWINDOW_HDR
#define GMENGN_XWINDOW_HDR

uint xinit(){
	Display *dpy;
	int scr;
	Window win;
	XEvent evx;

	// Makes a connection between the client application and the X server
	// The application is the client, and the display where you see all the graphics is the X server. So the way to make the connection is:
	dpy=XOpenDisplay(NULL);
	
	// Next things next, we will check for a connection. If there is no connection, dpy will reutrn NULL, we will check for NULL in this if statement. If we find null, we will return 1.
	if(dpy==NULL){
		loge("ERROR: ALSGM CANNOT CONNECT TO THE X SERVER (CANNOT OPEN DISPLAY!)\n");
		return 1;
	}
	// However, if we have a connection, then we will get the screen
	screen=DefaultScreen(dpy);
	win = XCreateWindow()
}

#include "ihdr.h"
#endif
