#ifndef ALSAMI_SPIRTE_CLASS_FILE_GM
#define ALSAMI_SPIRTE_CLASS_FILE_GM
/*
 *	This is the sprite class.  
 *
 *	For object-oriented games, use this class. This calss has some private members that should not be changed, and some are static. The necessary functions for managing spries will also be in this header file
 *
 * 	The Bitmap representation of the sprite uses the PPM format. It is an incredibly simple format, so you should have no problem with writing a PPM image inline with your code.
 * */

float asgn_nm_cntr=0;

float ASSIGN_SPRITE_NUM(){
	asgn_nm_cntr++;
	return asgn_nm_cntr;
}

class Sprite{
public:
	char* ppm_imgrep;

	Sprite();
	~Sprite();
protected:
private:
	float SPRITE_ID;	
};

Sprite::Sprite(){
	// The constructor should assign the sprite's ID.
	// (among other things that I will define later)
	float yin_sprite_als_xn = assgn_nm_cntr();
}

Sprite::~Sprite(){
	// This frees memory when a sprite gets destroyed
}

const char gm_4colorbox[] = {
	'p', '6' '\n',
	'#', 'b', 'y', ' ', 'k', 'h', 'o', 'r', 'a', 's', 'k', 'i', '\n',
	'2', ' ', '2', '\n',
	'2', '5', '5', '\n',
	255,0,0,
	0,255,255,
	0,0,255,
	255,0,255
}

#endif
