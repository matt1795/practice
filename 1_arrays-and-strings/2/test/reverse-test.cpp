// Reverse Test
//
// Author: Matthew Knight
// File Name: reverse-test.cpp
// Date: 2018-09-12
//
// This test has two cases, first, simply reversing a string, and secondly,
// handling an empty string

#include "reverse.hpp"

#include <gtest/gtest.h>
#include <string>

// Normal string
TEST(Reverse, NormalString) {
	std::string test("hello");
	std::string expected("olleh");
	std::string result(reverse(test.c_str()));
	ASSERT_STREQ(result.c_str(), expected.c_str());
}

// String made up of only the null terminator
TEST(Reverse, EmptyString) {
	std::string test("");
	std::string expected("");
	std::string result(reverse(test.c_str()));
	ASSERT_STREQ(result.c_str(), expected.c_str());
}
