#ifndef ALSAMI_OPNEGL_GAME_ENGINE_MAIN_HEADER_FILE
#define ALSAMI_OPNEGL_GAME_ENGINE_MAIN_HEADER_FILE

#include "ihdr.h"

/*
 *	OpenGL implemntation of X11.
 *	Sami Alameddine
 *
 *	compier options for this
 *	-lX11 -lGL
 * */

static Display *alsami_dpy;		// X Display
static int screen;			// X Screen
static Window app_win;			// App Main(root) Window
static XEvent app_xev			// X event thingy
static XSetWindowAttributes x_attrs;

uchar X_WIN_INIT(char arg1, uchar arg2) {
	alsami_dpy=XOpenDisplay(NULL);
	if(alsami_dpy==NULL){
		return 69;
	}
	screen=DefaultScreen(alsami_dpy);
	depth=DefaultDepth(alsami_dpy,screen);
	root_win=RootWindow(alsami_dpy,screen);
	
	x_attrs.border_pixel=BlackPixel(alsami_dpy,screen);
	x_attrs.background_pixel=WhitePixel(alsami_dpy,screen);
	x_attrs.override_redirect=True;
	x_attrs.colormap=CopyFromParent;
	x_attrs.EventMask=ExposureMask|KeyPressMask;
	// root window
	app_win=XCreateWindow(dpy,root_win,200,200,500,300,0,depth,InputOutput,CopyFromParent,CWBackPixel|CWColormap|CWBorderPixel|CWEventMask|CWBorderPixel|CWEventMask,&x_attrs);
}

// For testing purposes
//int main(){}

#endif
