# Question 1.4

Write a method to decide if two strings are anagrams or not.

## Testing

We will have the following function signature:

```
void isAnagram(char *str1, char *str2);
```

The test cases will be:

- strings are anagrams
- strings are not anagrams
- one of the string pointers is NULL

## Solution

This function will ignore all non-alphabetic characters, and will not care
about case.

There will be an array of 26 integers that correspond to a historgram bin for an
alphabetic character. We will scan through str1 and increment the bins for each
character, and then scan through str2 and decrement each bin. Finally, we will
check to see if every bin is 0, if so then we know that they have equal numbers
of the same characters -- the definition of an anagram.
