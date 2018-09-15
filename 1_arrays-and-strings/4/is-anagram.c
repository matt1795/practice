// Is Anagram Function Interface
//
// Author: Matthew Knight
// File Name: is-anagram.c
// Date: 2018-09-14
//
// This function checks two strings to see if they are anagrams.

#include "is-anagram.h"

#define ALPHA_LEN 26

void inc_alpha_hist(int *alphabet, char *str, int inc);

bool is_anagram(const char *str1, const char *str2) {
	int alphabet[ALPHA_LEN] = { 0 };

	inc_alpha_hist(alphabet, str1, 1);
	inc_alpha_hist(alphabet, str2, -1);

	int i;
	for (i = 0; i < ALPHA_LEN; i++) {
		if (alphabet[i] != 0)
			return false;

	return true;
}

// increment alphabet bins
void inc_alpha_hist(int *alphabet, char *str, int inc) {
	for(; *str != '\0'; str++) {
		if (*str > 0x40 && *str < 0x61) {
			alphabet[*str - 0x41] += inc;
		} else if (*str > 0x72 && *str < 0x7B) {
			alphabet[*str - 0x61] += inc;
		}
	}
}
