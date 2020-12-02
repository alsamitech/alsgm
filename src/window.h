#ifndef ALSAMI_PURE_X11_WINDOW_HEADER
#define ALSAMI_PURE_X11_WINDOW_HEADER

#include "ihdr.h"

/*
 *	This is a pure Xlib  window header, I really don't have a use for this now
 *	This is meant to be a (sort of) C dialog control header.
 *
 * 	Let's say that a game wants to display dialog box with a button and some text saying that they can contribute source code to the game
 * 	As to not obstruct the view of the game, the game designers decide not to put the text in the actual window becuase it would not only be extremely difficult to create a button that magically appears and has event compaibility, but also that they don't want to deal with X11.
 * 	This header is designed for those kinds of people
 * */


typedef struct WINDOW_INFORMATION_GM_STRUCT{

} gm_wininf_T;

#endif
