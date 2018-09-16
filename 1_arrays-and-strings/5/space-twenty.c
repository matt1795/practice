// Space Twenty Function
//
// Author: Matthew Knight
// File Name: space-twenty.c
// Date: 2018-09-14
//
// This function replaces all spaces withing a string with "%20"

#include "space-twenty.h"

#define TAG_SIZE 3

static const char *tag = "%20";

int space_twenty(char *str, size_t len) {
	int count = 0;
	char *cursor = str;

	// move to end of string and count spaces
	for (; *cursor != '\0'; cursor++)
		if (*cursor == ' ')
			count++;
	
	// exit if there is nothing to do
	if (count == 0)
		return 0;

	// Calculate how long the new string is going to be.
	char *endPoint = cursor + (TAG_SIZE - 1) * count;
	
	// Check to see if we have enough space
	if (endPoint > str + len)
		return 1;

	// Copy string backwards
	for (; endPoint != cursor; cursor--) {
		if (*cursor == ' ') {
			int i;
			for (i = TAG_SIZE - 1; i > -1; i--) {
				*endPoint = tag[i];
				endPoint--;
			}
		} else {
			*endPoint = *cursor;
			endPoint--;
		}
	}
	
	// exit with success
	return 0;
}
