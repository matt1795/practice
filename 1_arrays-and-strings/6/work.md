# Question 1.6

Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in
place?

## Testing

The function signature will look like the following:

```
int rotateNinety(uint32_t *mat, size_t side);
```

The function returns a 0 on success and 1 on failure. The two arguments are a
pointer to the matrix and the number of pixels on one side. The question defines
the matrix to b3 NxN meaning that it is a square.

The test cases are:

- matrix with an odd side number
- matrix with even side number
- A null pointer for mat
- a side number of 0

## Solution

Yes, you can rotate the matrix in place. What happens is that you can use a
single value buffer to swap the old and new value, transporting the old value to
its new location. The plan for this function is to start on the outside of the
image and move inwards as each "ring" is rotated.
