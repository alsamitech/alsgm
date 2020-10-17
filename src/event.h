#ifndef ALSAMI__GMENGN__EVNT__HDR
#define ALSAMI__GMENGN__EVNT__HDR

#include "ihdr.h"

/*
 *	Alternative Event Handling Module, not object oriented, and quite flexible.
 *	Modules from other sources:
 *		NONE
 *
 * */

int WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved;		// Window-Side Events
int AppTick,AppUpdate,AppRender;							// App-Side Events
int MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled;			// Curosor-Targeted events

int EventCategoryApplication		=BIT(0);
int EventCategoryInput			=BIT(1);
int EventCategoryKeyboard		=BIT(2);
int EventCategoryMouse			=BIT(3);
int EventCategoryMouseButton		=BIT(4);

struct ev{}


#endif
