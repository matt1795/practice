// Rotate Ninety Function test
//
// Author: Matthew Knight
// File Name: rotate-ninety-test.c
// Date: 2018-09-15
//
// This program tests a function for rotating a square matrix by 90 degrees.
// It tests for even and odd length matrices (side length). It also makes sure
// that a NULL pointer is handled correctly.

#include "rotate-ninety.h"

#include <assert.h>
#include <stdbool.h>

// function for comparing matrices
bool matcmp(uint32_t *lhs, uint32_t *rhs, size_t size);

int main() {
	// handles null correctly
	assert(rotate_ninety(NULL, 2) == 1);

	// correct handling of odd length array
	uint32_t oddMat[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};
	
	uint32_t oddExpected[3][3] = {
		{ 7, 4, 1 },
		{ 8, 5, 2 },
		{ 9, 6, 3 }
	};
	
	assert(rotate_ninety(oddMat, 3) == 0);
	assert(matcmp(oddMat, oddExpected, 3));

	// rotate even length array
	uint32_t evenMat[4][4] = {
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16 }
	};

	uint32_t evenExpected[4][4] = {
		{ 13, 9, 5, 1 },
		{ 14, 10, 6, 2 },
		{ 15, 11, 7, 3 },
		{ 16, 12, 8, 4 }
	};

	assert(rotate_ninety(evenMat, 4) == 0);
	assert(matcmp(evenMat, evenExpected, 4));
}

// function for comparing matrices
bool matcmp(uint32_t *lhs, uint32_t *rhs, size_t size) {
	int i, j;
	for (i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			unsigned int offset = i + size*j;
			if (*(lhs + offset) != *(rhs + offset)) {
				return false;
			}
		}
	}

	// all elements are equal;
	return true;
}
