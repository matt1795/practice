// Unique Character Functions
//
// Author: Matthew Knight
// File Name: unique.c
// Date: 2018-09-12
//
// These functions test whether the characters within a string are all unique.
// They simply use different implementations.

#include "unique.hpp"

// Using an external data structure
bool uniqueChars(const char *str) {
	// initialize to false.
	bool hist[256] = { false };
	
	// store in the histogram and check if it's happened before
	for (; *str != '\0'; str++) {
		hist[(unsigned int)*str] ^= true;
		if (!hist[(unsigned int)*str])
			return false;
	}

	return true;
}

// Using no external data structure
bool uniqueCharsInPlace(const char *str) {
	for (; *str != '\0'; str++) {
		// compare one char to all the rest
		for (const char *cursor = str + 1; *cursor != '\0'; cursor++) {
			if (*cursor == *str) {
				return false;
			}
		}
	}
	return true;
}
