#ifndef ALSAMI_OPNEGL_GAME_ENGINE_MAIN_HEADER_FILE
#define ALSAMI_OPNEGL_GAME_ENGINE_MAIN_HEADER_FILE
// to get rid of the ihdr being annoying
#include <X11/Xlib.h>

#include "ihdr.h"

/*
 *	OpenGL implemntation of X11.
 *	Sami Alameddine
 *
 *	compier options for this
 *	-lX11 -lGL
 * */

/*static*/ Display *alsami_dpy;		// X Display
/*static*/ int screen;			// X Screen
/*static*/ Window app_win, root_win;			// App Main(root) Window
/*static*/ XEvent app_xev			// X event thingy
/*static*/ XSetWindowAttributes x_attrs;

/* GLX vars */
GLint att[]={GLX_RGBA,GLX_DEPTH_SIZE,24,GLX_DOUBLEBUFFER,None};
XVisualInfo *alsami_xvis;
GLXContext glc;


uchar X_WIN_INIT(char arg1, uchar arg2) {
	alsami_dpy=XOpenDisplay(NULL);
	if(alsami_dpy==NULL){
		return 69;
	}
	screen=DefaultScreen(alsami_dpy);
	depth=DefaultDepth(alsami_dpy,screen);
	root_win=RootWindow(alsami_dpy,screen);

	alsami_xvis=glXVChooseVisual(dpy,screen,att);

	x_attrs.border_pixel=BlackPixel(alsami_dpy,screen);
	x_attrs.background_pixel=WhitePixel(alsami_dpy,screen);
	x_attrs.override_redirect=True;
	/*x_attrs.colormap=CopyFromParent;*/
	x_attrs.colormap=XCreateColorMap;
	x_attrs.EventMask=ExposureMask|KeyPressMask;
	// root window
	app_win=XCreateWindow(dpy,root_win,200,200,500,300,0,depth,InputOutput,CopyFromParent,CWBackPixel|CWColormap|CWBorderPixel|CWEventMask|CWBorderPixel|CWEventMask,&x_attrs);
	XMapWindow(alsami_dpy,app_win);

	// main loop
	for(;;){
		XNextEvent(alsami_dpy,&app_xev);
		if(app_xev==Expose){}
	}
}

// For testing purposes
//int main(){}

#endif
