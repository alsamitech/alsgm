#ifndef ALSGM_DYNAMIC_CPP_ARR
#define ALSGM_DYNAMIC_CPP_ARR

/*
 *	(c) Sami Alameddine, 2020
 *
 *	Dynamic Yin Array
 *
 *	This is a dynamic array, but is not as complex as std::vector
 * */

template <typename YI, size_t SNX>

class yinarray{
public:
	// Constructor
	yinarray(){
		// allocate some memory for 2 elements
		yin_ralloc(2);
	}
	void YIN_PUSHBACK(const YI& pval_yin){
		if(yin_size>=yin_capacity){
			yin_ralloc(yin_capacity+yin_capacity/2);
		}
		yin_data[yin_size]=pval_yin;
		yin_size++;
	}

	const YI& operator[](size_t yindex) const
	{
		if(yindex>=yin_size){
			//assert
		}
		return yin_data[yindex];
	}
	YI& operatorn[](size_t yindex) const{
		return yin_data[yindex];
	}

	size_t Array_rsize() const {return yin_size;}
private:
	void yin_ralloc(size_t yin_ncap){
		// Allocate a new block of memory
		// Move old elements into new block
		// Delete
		YI* yin_nblock=new YI[yin_ncap];
		
		size_t if_yi_sz=yin_size;
		if(yin_ncap<if_yi_sz){
			if_yi_sz=yin_ncap;
		}

		for(size_t yin_iii=0;yin_iii<yin_size;yin_iii++)
			yin_nblock[yin_iii]=yin_data[yin_iii];
		delete[] yin_data;
		yin_data=yin_nblock;
		yin_capacity=yin_ncap;
	}
	YI* yin_data=nullptr;

	size_t yin_size=0;
	size_t yin_capacity=0;

	
};

#endif
