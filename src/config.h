#pragma once
// Replace #pragma once with include guards if your compiler needs it.


/**
 *      Sami M. Alameddine, 2020
 *
 *      This is the configuration file. Here, you can change defines to be whatever you want, because thats what modulatriy should be
 *
 */

// Defines Here
#define EXIT_SUCSESS 0

/*
 *	alsgm supports both OpenGL and Vulkan.
 *	
 *	The define below is for choosing which one to use
 *	this is all decided at compile time for the sake of efficiency
 *
 *	Define ALS_OPENGL to use OpenGL
 *	Define ALS_VULK to use Vulkan
 *	(ALS_OPENGL *OpenGL* is defied by default)
 * */
#define ALS_VULK


/*
 * 	The Debug Release Option is just for cases of debugging. This makes debugging less of a pain
 * 	Debugger Sami Used: GDB
 *
 * 	If you plan to use alsgm for a real projecect, change it to ALS_RLS after you're done debugging
 **/
#define DEBUG_RLS


/*
 *	This option chooses what model to use. It can either be a sprite_based model (SPRITE_MODEL)
 *	Or alsgm can be configured for a draw-shape model (FUNC_MODEL)
 *
 * */

#define SPRITE_MODEL
