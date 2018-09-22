# Question 2.1

Write code to remove duplicates from an unsorted linked list. Follow up: How
would you solve this problem if a temporary buffer is not allowed?

## Solution

Using an external buffer/datastructure, a binary search tree or hash table could
be used to keep track of existing values and to keep lookup/comparison of new
values faster than a linear search for each element. If the value had a small
limited range, such an 8 bit value, an array of bools could be used as well.

Without any external datastructures you would be forced to run a linear search
for each element.

# Question 2.2

Implement an algorithm to find the nth to last element of a singly linked list.

## Solution

Create a cursor pointer and an offset pointer. Once the cursor pointer has
iterated to the nth value, start having the offset pointer iterate through the
list at the same time. Once the cursor pointer reaches the end, return the
offset pointer.

Alternatively you could using a pointer and a counter value and determine the
length of the list, then iterate the pointer again to len - n;

# Question 2.3

Implement an algorithm to delete a node in the middle of a single linkedess only
to that node.

## Solution

To delete this node, copy the next node to its position in memory, and then
delete the original copy of next.

# Question 2.4

You have two numbers represented by a linked list, where each node contains a
single digit. The digits are stored in reverse order, such that the 1's digit is
at the head of the list. Write a function that adds the two numbers and returns
the sum as a linked list.

## Solution

Add the values of the 1's digit. Create a node in the result list with the
result of the summation divided by 10. carry over the mod value when you add the
next two in the list. Oddly this is exactly how addition works.

# Question 2.5

Given a circular linked list, implement an algorithm which returns node at the
beginning of the loop. Definition: Circular linked list: a linked list in which
a node's next pointer points to an earlier node, so as to make a loop in the
linked list. (Eg. A->B->C->D->E->C) output: C.

## Solution

Note: solutions for this problem are dependent on the type of linked list.

For a doubly linked list, one would simply iterate through and make sure that
the two nodes beside a node in the list do match in their next and previous
pointers. Once that is not true, then the beginning of the loop is found.

As for a singly linked list, you run into a variation of the  duplication
problem. Here you'd need to search for duplicates of a next pointer down the
list, or use an external data structure to store visited nodes (hash table or
binary search) and compare that way  if time needed to be shorter than O(n!). 
