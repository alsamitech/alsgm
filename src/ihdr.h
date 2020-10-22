#ifndef ALSAMI_GAME_ENGINE_INTEGRATED_HDR
#define ALSAMI_GAME_ENGINE_INTEGRATED_HDR
/*Standard Library Links. All have*/
#ifdef ALS_OPENGL
// see config.h if you dont know what this is or want to use vulkan instead
#include <GL/gl.h>
#endif
#include <X11/Xlib.h>
/*Xlib (The Window System For Linux x.org) Requires you to use -lX11 in the compiler opetions to link the library*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Pthread (The Library for Multithreading), requires you to use the compiler option -lpthread to link the library*/
#include <string.h>
#include <pthread.h>
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
// Config File
#include "config.h"
#include "logfiles.h"
#include "logcon.h"
#include "coremod.h"
//#include "logcls.h"
//#include "logobj.h"


/*
 *	TODO:
 *		- Order the Header files properly
 *		- Add a good explination for every header file
 * */

#define BIT(x) (1<<x)

#endif
