# Question 1.1

Implement an algorithm to determine if a string has all unique characters. What
if you can not use additional data structures?

## Testing

Ok so for this one we'll have three test cases:

- A string with unique characters
- A string with non-unique
- An empty string

The definition for our functions will be:

```
bool uniqueChars(char *str);
bool uniqueCharsInPlace(char *str).
```

The empty string test case will result in a true value since there are no
duplicate characters.

## Solution

*Note: I assume different cases of a character are technically unique
characters.

The first solution consists of creating an array of bools that have the
length of 256, since we are assuming 8 bit characters. This will act as a
histogram of alphabetic characters and we will scan across the string flipping
zero's to ones. Every time we flip a bit we check to make sure it is a one, if
it is a zero, then that means we have a duplicate, and we know that the string
does not contain unique chars. If we get to the end of the string, then we know
that all the chars are unique. The time complexity for this algorithm is O(n)
for the worst case scenario.

The second solution requires no extra data structures. This method uses two
pointers, one stays in one spot and the other is used to compare the first with
all characters preceding. Then the first pointer is incremented. If any
duplicates are found then the function returns false. The time complexity for
this algorithm is O(n!) for the worst case.
