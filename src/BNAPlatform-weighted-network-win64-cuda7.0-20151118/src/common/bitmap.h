#ifndef _BITMAP_H_
#define _BITMAP_H_
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
using namespace std;
//  Created by Alps on 15/3/19.
//  Copyright (c) 2015年 chen. All rights reserved.
//


class BitMap{
public:
    BitMap(){
        bitmap = NULL;
        size = 0;
    }
	
    BitMap(size_t size){ // contractor, init the bitmap
        bitmap = NULL;
        bitmap = new unsigned char[size];
		//printf("BitMap Constractor!\n");
        if (bitmap == NULL) {
            printf("ErroR In BitMap Constractor!\n");
        }else{
            memset(bitmap, 0x0, size * sizeof(char));
            this->size = size;
        }
    }
	
	~BitMap(){
		if(bitmap != NULL)
			delete []bitmap;
		bitmap = NULL;
		//printf("BitMap Deconstractor!\n");
	}

    /*
     * set the index bit to 1;
     */
    bool bitmapSet(size_t index){
        size_t addr = index/8;
        int addroffset = index%8;
        unsigned char temp = 0x1 << addroffset;
        if (addr > (size+1)) {
            return 0;
        }else{
            bitmap[addr] |= temp;
            return 1;
        }
    }

    /*
     * return if the index in bitmap is 1;
     */
    bool bitmapGet(size_t index){
        size_t addr = index/8;
        int addroffset = index%8;
        unsigned char temp = 0x1 << addroffset;
        if (addr > (size + 1)) {
            return 0;
        }else{
            return (bitmap[addr] & temp) > 0 ? 1 : 0;
        }
    }

    /*
     * del the index from 1 to 0
     */
    bool bitmapDel(size_t index){
        if (bitmapGet(index) == 0) {
            return 0;
        }
        size_t addr = index/8;
        int addroffset = index%8;
        unsigned char temp = 0x1 << addroffset;
        if (addr > (size + 1)) {
            return 0;
        }else{
            bitmap[addr] ^= temp;
            return 1;
        }
    }

	void clear(){
		if(bitmap != NULL)
			delete []bitmap;
		bitmap = NULL;
		size = 0;
	}
	

protected:
    unsigned char *bitmap;
    size_t size;
};



#endif // _TIMER_H_

