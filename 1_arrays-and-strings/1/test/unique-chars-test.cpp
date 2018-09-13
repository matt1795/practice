// Unique char tests
//
// Author: Matthew Knight
// File Name: unique-chars-test.cpp
// Date: 2018-09-12
//
// This program goes through each of the test cases for each function as
// described in work.md

#include "unique.hpp"

#include <gtest/gtest.h>
#include <string>

// String with unique characters using data structure solution
TEST(UniqueChars, Unique) {
	std::string test("uniqe");
	ASSERT_TRUE(uniqueChars(test.c_str()));
}

// String with unique characters using in place solution
TEST(UniqueCharsInPlace, Unique) {
	std::string test("uniqe");
	ASSERT_TRUE(uniqueCharsInPlace(test.c_str()));
}

// String with duplicate characters using data structure solution
TEST(UniqueChars, Duplicate) {
	std::string test("duplicatte");
	ASSERT_FALSE(uniqueChars(test.c_str()));
}

// String with duplicate characters using in place solution
TEST(UniqueCharsInPlace, Duplicate) {
	std::string test("duplicatte");
	ASSERT_FALSE(uniqueCharsInPlace(test.c_str()));
}

// Empty String using data structure solution
TEST(UniqueChars, Null) {
	std::string test("");
	ASSERT_TRUE(uniqueCharsInPlace(test.c_str()));
}

// Empty String using in place solution
TEST(UniqueCharsInPlace, Null) {
	std::string test("");
	ASSERT_TRUE(uniqueCharsInPlace(test.c_str()));
}
