#pragma once
// Replace #pragma once with include guards if your compiler needs it.


/**
 *      Sami M. Alameddine, 2020
 *
 *      This is the configuration file. Here, you can change defines to be whatever you want, because thats what modulatriy should be
 *	If you're cofused by the wording here, Please read the README
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
#define IGNORE_GRAPHICS
#define ALS_VULK


/*
 * 	The Debug Release Option is just for cases of debugging. This makes debugging less of a pain
 * 	Debugger Sami Used: GDB
 *
 * 	If you plan to use alsgm for a real project, change it to ALS_RLS after you're done debugging
 **/
#define DEBUG_RLS

/*
 *	This option selects which ISA that your game gets compiled to. Mostly used for functions that are definied in ISA-specific assmebly and what standard int to use (i386_64 defied by default)
 *	i386					elf32 x86_32 IA_32
 *	i386_64					elf64 x84_64 IA_64
 * */
#define i386_64


/*
 *	This option chooses what model to use. It can either be a sprite_based model (SPRITE_MODEL)
 *	Or alsgm can be configured for a draw-shape model (FUNC_MODEL)
 *
 * */

#define SPRITE_MODEL

/*
 *  Remove this if this is a release buiild, but this is just for testing, and declares specific things in the header files
 *
 **/
#define EXAMPLE
