// Zero Row Column Test Program
//
// Author: Matthew Knight
// File Name: test.c
// Date: 2018-09-15
//
// This program tests this function which takes an NxM matrix and zeros out the
// rows and columns of elements that are of the value zero.
// Test cases:
//	- NULL input
//	- matrix with no zeros
//	- matrix with one zero
//	- matrix with overlapping zeros
//	- matrix with non-overlapping zeros
//	- matrix of all zeros

#include "zero-row-col.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

bool matcmp(int *mat1, int* mat2, size_t rows, size_t cols);

int main() {
	// NULL
	assert(zero_row_col(NULL, 2, 2) == 1);

	// No zeros
	int no_zeros[2][2] = {
		{ 3, 4 },
		{ 5, 6 }
	};
	
	int no_zeros_exp[2][2] = {
		{ 3, 4 },
		{ 5, 6 }
	};
	
	assert(zero_row_col(no_zeros, 2, 2) == 0);
	assert(matcmp(no_zeros, no_zeros_exp, 2, 2));

	// one zero
	int one_zero[3][2] = {
		{ 3, 0 },
		{ 4, 5 },
		{ 6, 7 }
	};
	
	int one_zero_exp[3][2] = {
		{ 0, 0 },
		{ 4, 0 },
		{ 6, 0 }
	};

	assert(zero_row_col(one_zero, 3, 2) == 0);
	assert(matcmp(one_zero, one_zero_exp, 3, 2));

	// overlapping zeros
	
	int overlap[3][2] = {
		{ 1, 0 },
		{ 2, 0 },
		{ 3, 4 }
	};
	
	int overlap_exp[3][2] = {
		{ 0, 0 },
		{ 0, 0 },
		{ 3, 0 }
	};

	assert(zero_row_col(overlap, 3, 2) == 0);
	assert(matcmp(overlap, overlap_exp, 3, 2));

	// non-overlapping zeros
	
	int non_overlap[3][3] = {
		{ 1, 2, 3 },
		{ 0, 4, 5 },
		{ 6, 0, 7 }
	};

	
	int non_overlap_exp[3][3] = {
		{ 0, 0, 3 },
		{ 0, 0, 0 },
		{ 0, 0, 0 }
	};

	assert(zero_row_col(non_overlap, 3, 3) == 0);
	assert(matcmp(non_overlap, non_overlap_exp, 3, 3));

	// all zeros
	int all_zeros[4][3] = {
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 }
	};
	
	int all_zeros_exp[4][3] = {
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 }
	};

	assert(zero_row_col(all_zeros, 4, 3) == 0);
	assert(matcmp(all_zeros, all_zeros_exp, 4, 3));
}

bool matcmp(int *mat1, int *mat2, size_t rows, size_t cols) {
	int i, j;
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			if (*(mat1 + cols*i + j) != *(mat2 + cols*i + j))
				return false;

	return true;
}
