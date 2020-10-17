#ifndef ALSAMI_GAME_ENGINE_INTEGRATED_HDR
#define ALSAMI_GAME_ENGINE_INTEGRATED_HDR
/*Standard Library Links. All have*/
#include <GL/gl.h>
#include <X11/Xlib.h>
/*Xlib (The Window System For Linux x.org) Requires you to use -lX11 in the compiler opetions to link the library*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Pthread (The Library for Multithreading), requires you to use the compiler option -lpthread to link the library*/
#include <pthread.h>
#include <sys/socket.h>

/*Local Links*/
// Config File
#include "config.h"
#include "logfile.h"
#include "coremod.h"


/*
 *	TODO:
 *		- Order the Header files properly
 *		- Add a good explination for every header file
 * */

#define BIT(x) (1<<x)

#endif
