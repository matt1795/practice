// Rotate matrix by 90 degrees: Function Implementation
//
// Author: Matthew Knight
// File Name: rotate-ninety.c
// Date: 2018-09-14
//
// This function alters a matrix so that all of its elements are rotated by 90
// degrees. Note, this matrix is always a square.

#include "rotate-ninety.h"

#include <stdlib.h>
#include <stdint.h>

int rotate_ninety(uint32_t *mat, size_t size) {
	// Check for null
	if (mat == NULL) {
		return 1;
	}

	int ring, rowPos, side;

	for (ring = 0; ring < (size/2); ring++) {
		int i = ring;
		for (rowPos = 0; rowPos < size - 2*ring - 1; rowPos++) {
			int j = rowPos + ring;
			
			// save first val to buffer
			uint32_t offset = size*i + j; 
			uint32_t buf = *(mat + offset);
				
			for (side = 0; side < 4; side++) {
				// determine new coordinates
				int tempIndex = i;
				i = j;
				j = -tempIndex + size - 1;
				offset = size*i + j; 
				
				// swap values
				uint32_t temp = *(mat + offset);
				*(mat + offset) = buf;
				buf = temp;
			}
		}
	}

	// success
	return 0;
}
