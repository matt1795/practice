// Remove duplicates test
//
// Author: Matthew Knight
// File Name: remove-duplicates-test.c
// Date: 2018-09-13
//
// This program tests the remove duplicates function, see work.md for details

#include "remove-duplicates.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// handle null pointer
	assert(removeDuplicates(NULL) == 1);

	// handle empty strings
	char c = '\0';
	assert(removeDuplicates(&c) == 0);
	assert(c == '\0');

	// handle string with unique characters.
	char unique[] = "abcdef";
	char expected[] = "abcdef";
	assert(removeDuplicates(unique) == 0);
	assert(strcmp(unique, expected) == 0);
	
	// handle string with duplicate characters
	char duplicate[] = "aabbccddeeff";
	assert(removeDuplicates(duplicate) == 0);
	assert(strcmp(duplicate, expected) == 0);
}
