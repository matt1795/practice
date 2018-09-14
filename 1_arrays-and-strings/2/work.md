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

### Correction

In the above solution I use malloc to allocate memory. This was an oversight on
my part, it passed the test, however it is very unusable because it will likely
create a memory leak if the user of this function does not know to free the
memory afterwards. What might work better is to either change the string in
place, changing the function signature to void reverse(char *), or to allow the
user to manage memory for the output. This would require simply describing the
basic operation of the string, and letting them deal with things how they wish.
