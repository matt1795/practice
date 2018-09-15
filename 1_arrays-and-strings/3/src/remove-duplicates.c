// Remove Duplicate Character Function
//
// Author: Matthew Knight
// File Name: remove-duplicates.c
// Date: 2018-09-13
//
// This function takes a string and alters it to remove any duplicate strings.

#include <stdlib.h>

// Remove duplicate characters from a string
int removeDuplicates(char *str) {
	// No success if string pointer is null;
	if (str == NULL) {
		return 1;
	}
	for (; *str != '\0'; str++) {
		int count = 0;
		// compare characters, move characters over if need be
		for (char *cursor = str + 1; *(cursor - 1) != '\0'; cursor++) {
			if (*cursor == *str) {
				count++;
			} else if (count > 0) {
				*(cursor - count) = *cursor;
			}
		}
	}
	
	return 0;
}
