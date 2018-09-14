# Question 1.3

Design an algorithm and write code to remove duplicate characters in a string
without using any additional buffer. NOTE: One or two additional variables are
fine. An extra copy is not. Follow up: Write the test cases for this method

## Testing

The function declaration will look like the following:

```
void removeDuplicates(char *str);
```

This function will alter a string in place. The following test cases will be
tested:

- A string with unique strings
- A string with some duplicate characters
- An empty string
- A null pointer passed as a string to avoid segement faults

## Solution

The function will use the parameter passed to pass the string by reference to
scan accross the string. We will then use a second pointer and a counter
variable. The order of operations for this algorithm is first for the string
pointer to reference the beginning character, and the cursor pointer will be
initialized to the following character, and the count is initially zero. (Oh
also, we initially check that the string pointer is not NULL).

First the characters that the pointers reference are compared. If they are
different and the counter is 0, then the cursor moves to the next character. If
they are the same, then the counter is incremented and the cursor moves on.
Finally, if the character is different, and the counter is greater than one,
then the character gets copied to a preceding position with a relative position
equal to the counter value.
