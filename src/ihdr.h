#ifndef ALSAMI_GAME_ENGINE_INTEGRATED_HDR
#define ALSAMI_GAME_ENGINE_INTEGRATED_HDR

// The Config File has full authority to decide what is libraries are used
// Config File
#include "config.h"

/*Standard Library Links. All have*/
#ifdef ALS_OPENGL
// see config.h if you dont know what this is or want to use vulkan instead
#include <X11/Xlib.h>
#include <X11/Xutil.h>
//#include <Xos.h>
//#include <Xatom.h>

// -lX11 -lGL -lGLU

#include <GL/gl.h>
/*Other OpenGL Stuff*/

#include <GL/glx.h>
#include <GL/glu.h>
#endif
/*Xlib (The Window System For Linux x.org) Requires you to use -lX11 in the compiler opetions to link the library*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Pthread (The Library for Multithreading), requires you to use the compiler option -lpthread to link the library*/
#include <string.h>
#include <pthread.h>

// TO make debugging less painful
#ifdef DEBUG_RLS
#include <assert.h>
#endif


#include <stdarg.h>
#include <sys/types.h>
#include <sys/socket.h>

/*Defines*/
typedef unsigned char uchar;

// Complaint Types

// Standard Logger Complaint
#define GAME_ENGINE_COMPLAINT_STDLOG 1

// Logger Complaint From App
#define GAME_ENGINE_LGR_CMPLNT_FR_APP 6

#define GAME_ENGINE_LFT_CMPLNT_FR_APP 6

// Logger Complaint From Core std module
#define GAME_ENGINE_LGR_COMPLNT_CORE_MODULE 40
#define GAME_ENGINE_LFT_CMPLNT_CORE_MODULE 39

// Loggger Rquest from anything
#define GAME_ENGINE_RQ_ANY 13

// For the sake of santiy


#define unt unsigned int


/*Local Links*/


/* Dyanic Array Handling Headers */
#include "tarray.h"
#include "darray.h"

#include "logfiles.h"
#include "logcon.h"
#ifdef ALS_OPENGL
// see config.h if you dont know what this is or want to use vulkan instead
#include "glgraphics.h"
#endif
#include "coremod.h"
#include "appevent.h"

//#include "logcls.h"
//#include "logobj.h"


/*
 *	TODO:
 *		- Order the Header files properly
 *		- Add a good explination for every header file
 * */

#define BIT(x) (1<<x)

#endif
