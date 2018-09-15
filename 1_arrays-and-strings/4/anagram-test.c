// Anagram Function Test
//
// Author: Matthew Knight
// File Name: anagram-test.c
// Date: 2018-09-14
//
// This program tests the anagram function as described in work.md
// It goes over the following test cases:
//
//	- Strings are not anagrams
//	- Strings are anagrams
//	- One of the strings is a null ptr

#include "anagram.h"

#include <assert.h>
#include <stdbool.h>
#include <string.h>

int main() {
	// One of the strings is null
	char *str = "hello";
	assert(isAnagram(NULL, str) == false);

	// the strings are not anagrams
	char *notAnagram1 = "this";
	char *notAnagram2 = "is not";
	assert(isAnagram(notAnagram1, notAnagram2) == false);

	// the strings are anagrams
	char *anagram1 = "abcdefg";
	char *anagram2 = "BDcaegf";
	assert(isAnagram(anagram1, anagram2) == true);
}
