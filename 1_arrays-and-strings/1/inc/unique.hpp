// Unique Character Functions
//
// Author: Matthew Knight
// File Name: unique.h
// Date: 2018-09-12
//
// These functions test whether the characters within a string are all unique.
// They simply use different implementations.

#ifndef UNIQUE_CHARS_H_
#define UNIQUE_CHARS_H_

// Using an external data structure
bool uniqueChars(const char *str);

// Using no external data structure
bool uniqueCharsInPlace(const char *str);

#endif // UNIQUE_CHARS
