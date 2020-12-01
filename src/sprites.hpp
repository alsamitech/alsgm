#ifndef ALSGM_SPRITES_HPP
#define ALSGM_SPRITES_HPP 
/* 
 * This is the sprite class.  
 *
 *	For object-oriented games, use this class. This calss has some private members that should not be changed, and some are static. The necessary functions for managing spries will also be in this header file
 *
 * 	The Bitmap representation of the sprite uses the PPM format. It is an incredibly simple format, so you should have no problem with writing a PPM image inline with your code.
 * */

#include "ihdr.h"
#include "aar.h"


float asgn_nm_cntr=0;

typedef struct SPRITED_STRUCT{
	uint32_t d;
	float width;
	float height;
	float r;	// red
	float g;	// green
	float b;	// blue
	float a;	// Alpha
	darray_T* textures;	
} sprited_T;
//  SPRITE Description

sprited_T* sprited_alloc(){
	sprited_T* sprited_i=(sprited_T*)calloc(1,sizeof(struct SPRITED_STRUCT));
}

class Sprite{
public:
	char* ppm_frontend;

	Sprite();
	~Sprite();
protected:
private:
#ifdef i386_64
	// Unsigned 64 bit integer that contains the Sprite Descriptor.
	uint64_t SPRITED;
#endif
#ifdef i386
	uint32_t SPRITED;
#endif

};

Sprite::Sprite(){
	// The constructor should assign the sprite's ID.
	// (among other things that I will define later)
	//float yin_sprite_als_xn = asgn_nm_cntr();
}

Sprite::~Sprite(){
	// This frees memory when a sprite gets destroyed
}

const uint8_t gm_4colorbox[] = {
	'p', '6', '\n',
	'#', 'b', 'y', ' ', 'k', 'h', 'o', 'r', 'a', 's', 'k', 'i', '\n',
	'2', ' ', '2', '\n',
	'2', '5', '5', '\n',
	255,0,0,
	0,255,255,
	0,0,255,
	255,0,255
};



#endif
