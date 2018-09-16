// Is Rotation Test Program
//
// Author: Matthew Knight
// File Name: test.c
// Date: 2018-09-16
//
// This program tests the is_rotation function as described by this problem
// question. It first tests some boundary cases such as null pointer handling,
// and then makes sure it returns the correct results for a rotated and not
// rotated string

#include "is-rotation.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
	// Handling null pointers
	char *str = "waterbottle";
	assert(is_rotation(NULL, str) == false);
	assert(is_rotation(str, NULL) == false);
	assert(is_rotation(NULL, NULL) == false);

	// string is not a rotation
	char *not_rotation = "hello";
	assert(is_rotation(not_rotation, str) == false);

	// string is a rotation
	char *rotation = "erbottlewat";
	assert(is_rotation(rotation, str) == true);

	return 0;
}
