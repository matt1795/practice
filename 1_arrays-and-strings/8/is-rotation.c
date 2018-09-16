// Is Rotation Implementation File
//
// Author: Matthew Knight
// File Name: is-rotation.c
// Date: 2018-09-16
//
// This function checks if str1 is a rotation of str2

#include "is-rotation.h"

#include <string.h>

bool is_rotation(const char *str1, const char *str2) {
	// Check for NULLS
	if (str1 == NULL || str2 == NULL)
		return false;

	// Check len
	int len = strlen(str1);
	if (strlen(str2) != len)
		return false;

	// allocate memory, copy string twice
	char *buf = (char*)malloc(2*len + 1);

	strcpy(buf, str1);
	strcpy(buf + len, str1);
	
	// check for substring in buf, free buf
	char *result = strstr(buf, str2);
	free(buf);

	if (result != NULL)
		return true;
	else
		return false;
}
