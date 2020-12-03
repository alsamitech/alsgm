#ifndef ALSAMI_OPNEGL_GAME_ENGINE_MAIN_HEADER_FILE
#define ALSAMI_OPNEGL_GAME_ENGINE_MAIN_HEADER_FILE
// to get rid of the ihdr being annoying
#include <X11/Xlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glu.h>

//#include "ihdr.h"

/*
 *	OpenGL implementation of X11.
 *	Sami Alameddine
 *
 *	Linker Args
 *	-lX11 -lGL
 * */

// these are only needed in this specific translation layer, so no need to let them be used anywhere else
/*static*/ Display *alsami_dpy;		// X Display
/*static*/ int screen;			// X Screen
/*static*/ Window app_win, root_win;			// App Main(root) Window
/*static*/ XEvent app_xev;			// X event thingy
/*static*/ XSetWindowAttributes x_attrs;
/*static*/ unsigned int depth;
XWindowAttributes winattr;

/* GLX vars */
GLint att[]={GLX_RGBA,GLX_DEPTH_SIZE,24,GLX_DOUBLEBUFFER,None};
XVisualInfo *alsami_xvis;
GLXContext glc;

// Draw triangle function
void drawTriangle(GLfloat CordX,GLfloat CordY,GLfloat CordZ){
	glColor3f(0.0f,0.0f,0.0f);

	glBegin(GL_TRIANGLES);
		glVertex3f(0.0f,0.0f,0.0f);

	      	//glVertex3f(negativeX,positiveX,Z)
		//glVertex3f(CordX,CordY,CordZ);
		glVertex3f(-0.5f,0.0f,0.0f);
		// yes I'm using libc and im not gonna stop
		//glVertex3f(fabs(CordX),CordY,CordZ);
		glVertex3f(0.5f, 0.5f, 0.0f);
}

uint8_t X_WIN_INIT(char arg1, uchar arg2) {
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
	/*x_attrs.colormap=CopyFromParent;*/
	
	alsami_xvis=glXChooseVisual(alsami_dpy,screen,att);
	
	x_attrs.colormap=XCreateColormap(alsami_dpy, root_win, alsami_xvis->visual, AllocNone);
	x_attrs.event_mask=ExposureMask|KeyPressMask;
	// root window
	
	glc = glXCreateContext(alsami_dpy, /*visual*/alsami_xvis, NULL, GL_TRUE);
	
	app_win=XCreateWindow(alsami_dpy,root_win,200,200,500,300,0,alsami_xvis->depth,InputOutput,alsami_xvis->visual,CWBackPixel|CWColormap|CWBorderPixel|CWEventMask|CWBorderPixel|CWEventMask,&x_attrs);
	XMapWindow(alsami_dpy,app_win);

	glXMakeCurrent(alsami_dpy,app_win,glc);

	// makes OpenGL do the integration with X11
	glEnable(GL_DEPTH_TEST);

	// main loop
	for(;;){
		XNextEvent(alsami_dpy,&app_xev);
		if(app_xev.type==Expose){
			XGetWindowAttributes(alsami_dpy,app_win,&winattr);
			glViewport(0,0,winattr.width,winattr.height);

			// glClearColor(red,green,blue,alpha)
			glClearColor(0.7f,0.7f,0.7f,0.7f);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			drawTriangle(0.5f,0.5f,0.0f);
			glEnd();
    			glXSwapBuffers(alsami_dpy,app_win);
		}
	}
}

#endif
