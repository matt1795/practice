// Zero Rows and Columns Interface
//
// Author: Matthew Knight
// File Name: zero-row-col.c
// Date: 2018-09-15
//
// This function takes an NxM matrix and zeros out the rows and columns of any
// elements that have a value of zero.

#include "zero-row-col.h"

#include <stdbool.h>
#include <stdlib.h>

// calculate offset
int offset(int i, int j, size_t cols) {
	return cols*i + j;
}

int zero_row_col(int *mat, size_t rows, size_t cols) {
	// make sure mat is not null
	if (mat == NULL)
		return 1;

	// allocate memory for flag buffers.
	bool *row_flags = (bool*)malloc(sizeof(bool)*rows);
	bool *col_flags = (bool*)malloc(sizeof(bool)*cols);

	// initialize to false
	int i;
	for (i = 0; i < rows; i++)
		row_flags[i] = false;

	for (i = 0; i < cols; i++)
		col_flags[i] = false;

	// scan array for zeros
	int j;
	for (i = 0; i < rows; i++) {
		for(j = 0; j < cols; j++) {
			if (*(mat + offset(i, j, cols)) == 0) {
				row_flags[i] = true;
				col_flags[j] = true;
			}
		}
	}

	// for each flag in row/col_flags, zero out corresponding row/column
	for (i = 0; i < rows; i++) {
		if (row_flags[i]){
			for (j = 0; j < cols; j++) {
				*(mat + offset(i, j, cols)) = 0;
			}
		}
	}
	
 	for (j = 0; j < cols; j++) {
		if (col_flags[j]){
			for (i = 0; i < rows; i++) {
				*(mat + offset(i, j, cols)) = 0;
			}
		}
	}
	
	// exit on success
	return 0;
}
