# Question 1.2

Write code to reverse a C-Style String. (C-String means that "abcd" is
represented as five characters, including the null character.)

## Testing

For this challenge, the definition will return a copy of the original string,
and look like this:

```
char *reverse(const char *str);
```

There will be two tests, first a simple reversal of a normal string, and second
the reversal of an empty string for a boundary case.

## Solution

The function described above will measure the length of the input string,
allocate memory for a new string using malloc, and copy characters over in a
reverse fashion. finally it will append the string with a null terminator. time
complexity is O(2n).

This function does not alter the original string (keeping it const) since it is
common for classes to prohibit external alterations of their string (eg.
std::string).
