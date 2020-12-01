#ifndef ALSGM_INTEGRATED_HDR
#define ALSGM_INTEGRATED_HDR

// The Config File has full authority to decide what is libraries are used
// Config File
#include "config.h"

// links to external object files if an IA_64 architecture is defined in config.h
#ifdef i386_64

#endif

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
#include <math.h>
/*Pthread (The Library for multithreading), requires you to use the compiler option -lpthread to link the library*/
#include <string.h>
#include <pthread.h>

// TO make debugging less painful
#ifdef DEBUG_RLS
#include <assert.h>
#endif

// For better portability and for sanity
#include <stdint.h>

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

// Logger Request from anything
#define GAME_ENGINE_RQ_ANY 13

// For the sake of sanity


#define unt unsigned int

uint8_t gm_logtocon(const char* msg, uint8_t flags);

/*Local Links*/


/* Dynamic Array Handling Headers */
// i ain't that good at c++, so I'll keep tarray out for now
//#include "tarray.h"
#include "darray.h"

#include "window.h"

#include "logfiles.h"
#include "queue.h"
#include "logcon.h"
#include "sprites.hpp"

#ifdef ALS_OPENGL
// see config.h if you dont know what this is or want to use vulkan instead
#include "glgraphics.h"
#endif
#include "coremod.h"
#include "aar.h"
// Excluded for now
//#include "appevent.h"

#ifdef ALS_VULK

#include "vulk/vulk.h"

#endif

#ifdef i386
#define isa_mint uint32_t
#endif
#ifdef i386_64
#define isa_mint uint64_t
#else
// I know
#define isa_mint uint64_t
#endif


/*
 *	TODO:
 *		- Order the Header files properly
 *		- Add a good explanation for every header file
 * */

#define BIT(x) (1<<x)

#endif
