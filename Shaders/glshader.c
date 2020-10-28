#include <stdio.h>
#include <stdlib.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>


#include <GL/glx.h>
#include <GL/glu.h>

int main(){
	Display *dpy;
  int screen;
  Window win, root_win;
  XEvent event;

  GLint att[]={GLX_RGBA, GLX_DEPTH_SIZE,GLX_DOUBLEBUFFER,None};
  XVisualInfo *visual;
  GLXContext glc;

  dpy=XOpenDisplay(NULL);
  if(dpy=NULL){
    fprintf(stderr,"Cannot Open Display\n");
    return 1;
  }
  screen=DefaultScreen(dpy);
  depth=DefaultDepth(dpy,screen);
  root_win=RootWindow(dpy,screen);

  visual=glXChooseVisual(dpy,screen,att);

  attrs.border_pixel=BlackPixel(dpy,screen);
  attrs.background_pixel=WhitePixel(dpy, screen);
  attrs.override_redirect=True;
  attrs.colormap=XCreateColorMap(dpy,root_win,visual->visual, AllocNone);

  win=XCreateWindow(dpy, root_win,200,200,500,300,0,visual->depth,InputOutput,visual->visual, CWBackPixel |CWColorMap| CWBorderPixel|CWEventKMask, &attrs);

  XMapWindow(dpy,win);

  glc=glXCreateContext(dpy,visual,NULL,GL_TRUE);
  glXMakeCurrent(dpy,win,glc);

  glEnable(GL_DEPTH_TEST);

  for(;;) {
    XNextEvent(dpy,&event);

    if(event.type==Expose) {



    }
    if(event.type=KeyPress){
      XDestroyWindow(dpy,win);
      XCloseDisplay(dpy);
      break;
    }
  }

	return 0;
}
