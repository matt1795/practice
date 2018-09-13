// Reverse String Function
//
// Author: Matthew Knight
// File Name: reverse.cpp
// Date: 2018-09-12
//
// This function takes a C string and returns a copy of the string reversed.

#include "reverse.hpp"

#include <cstdlib>

// see above for function description
const char *reverse(const char *str) {
	const char *cursor = str - 1;
	
	// zip to end of string
	for (;*(cursor + 1) != '\0'; cursor++)
		;

	// determin size and allocat memory
	size_t len = cursor - str + 2;	
	char *rev = (char*)malloc(len);
	char *insert = rev;
	
	// copy in reverse order
	for(;cursor >= str; cursor--)
		*insert++ = *cursor;

	// finish it off with an null terminator
	rev[len - 1] = '\0';
	return rev;
}

