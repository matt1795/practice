# Question 1.8

Assume you have a method isSubstring which checks if one word is a substring of
another. Given two strings, s1 and s2, write code to check if s2 is a rotation
of s1 using only one call to isSubstring. (ie. "waterbottle" is a rotation of
"erbottlewat").

## Testing

The function declaration will be:

```
bool is_rotation(const char *str1, const char *str2);
```

Eg: is str1 a rotation of string 2?

The test cases will be:
	- one string is null
	- both strings are null
	- one string is not a rotation of another
	- one string is a rotation.

## Solution

First I will assume that we are only dealing with strings with zero white space,
so really, just single words. For pointer safety, the first thing that needs to
be done is ensure that the strings are the same length, otherwise they cannot be
rotations.

Secondly what we will do is allocate space that is 2n + 1 times the length of
the string. The string will be copied in twice so that somewhere in that string
the unrotated string exists. Then we can run strstr which behaves like
isSubstring.
