#ifndef ALSAMI_SPIRTE_CLASS_FILE_GM
#define ALSAMI_SPIRTE_CLASS_FILE_GM
/*
 *	This is the sprite class.  
 l
 *	For object-oriented games, use this class. This calss has some private members that should not be changed, and some are static. The necessary functions for managing spries will also be in this header file
 * */

float asgn_nm_cntr=0;

float ASSIGN_SPRITE_NUM(){
	asgn_nm_cntr++;
	return asgn_nm_cntr;
}

class Sprite{
public:
	Sprite();
	~Sprite();
protected:
private:
	float SPRITE_ID;	
}

Sprite::Sprite(){
	// The constructor should assign the sprite's ID.
	// (among other things that I will define later)
	float yin_sprite_als_xn = assgn_nm_cntr();
}

Sprite::~Sprite(){
	// This frees memory when a sprite gets destroyed
}
#endif
