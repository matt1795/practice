// Space Twenty Test Program
//
// Author: Matthew Knight
// File Name: test.c
// Date: 2018-09-15
//
// This function will be tested for the following cases:
// 
//	- string does not contain any spaces
//	- string contains spaces and buffer has enough room
//	- string contains spaces and buffer does not have enough room

#include "space-twenty.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// string with no spaces, it does not change
	char no_space[] = "nospace";
	char no_space_exp[] = "nospace";
	assert(space_twenty(no_space, strlen(no_space) + 1) == 0);
	assert(strcmp(no_space, no_space_exp) == 0);

	// string with space and has enough space in the buffer
	char space[25] = "here is a sentence";
	char space_expected[] ="here%20is%20a%20sentence";
	assert(space_twenty(space, 25) == 0);
	assert(strcmp(space, space_expected) == 0);
	
	// string with space and buffer is not long enough
	char space_short[] = "here is another sentence";
	assert(space_twenty(space_short, strlen(space_short)) == 1);
}
