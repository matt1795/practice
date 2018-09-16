// Anagram Function Test
//
// Author: Matthew Knight
// File Name: test.c
// Date: 2018-09-14
//
// This program tests the anagram function as described in work.md
// It goes over the following test cases:
//
//	- Strings are not anagrams
//	- Strings are anagrams

#include "is-anagram.h"

#include <assert.h>
#include <stdbool.h>
#include <string.h>

int main() {
	// the strings are not anagrams
	char *not_anagram1 = "this";
	char *not_anagram2 = "is not";
	assert(is_anagram(not_anagram1, not_anagram2) == false);

	// the strings are anagrams
	char *anagram1 = "abcdefg";
	char *anagram2 = "BDcaegf";
	assert(is_anagram(anagram1, anagram2) == true);
}
