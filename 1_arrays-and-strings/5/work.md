# Question 1.5

Write a method to replace all spaces in a string with "%20".

## Testing

Due to considerations from the solution (next section) there will be some extra
test cases that are implementation specific.

Function signature:

```
int spaceTwenty(char *str, size_t len);
```

The int tells us the result. the str pointer points to a char buffer, and len
tells us the maximum length of that buffer.

## Solution

We create a copy of str and scan to the end of the string, counting spaces as we
go. We then determine the final length of the string and make sure it is within
bounds. We assign str to where the end of the string will be. Finally, we scan
through the string backwards copying characters and expanding spaces until the
two pointers are equal. Once that happens there is no more sections of the
string that need to be copied.
