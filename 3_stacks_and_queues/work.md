# Question 3.1

Describe how you could use a single array ti implement three stacks.

## Solution

To implement three stacks in a single array, I would initialize the stack
pointers to be referencing positions next to one another. When the stacks push
or pop, they insert their elements, and instead of moving by one element, they
move by three, interleaving the elements of the three stacks. The convenient
part of this setup is that if you have an array length of 10, (lengths of 3, 3,
and 4) you do not need to split up the stacks into uneven lengths, you just
compare the pointer value to an end address, and that will determine if the
stack is full or not.

# Question 3.2

How would you design a stack which, in addition to push and pop, also has a
function min which returns the minimum element? Push, pop, and min should all
operate on O(1) time.

## Solution

I am unable to figure out all of this myself. The best solution I can come up
with is an ordered linked list/stack combination. The values would be contained
in the list, where the stack would actually be made up of pointers. Pushing
would mean inserting the value into the orderedlist, probably using a binary
insertion to get insertion time down to O(log n), poping would be O(1) because
the element is directly referenced in the stack, and min is O(1) (if we just
want to peak) because the first element in the list is the minimum element and
it increases O(n) if the minumum element is intended to be removed, since it
must be found in the stack and removed.

Note: I had to go read the book solution to clear something up. What we want is
only the value of the minimum element, not a reference to the element. In this
case when we push in an element, we look at the preceding element which also has
a value of the minimum value of the stack. If the minimum value is less than the
inserted, then we copy the value, else the new lowest value is the  

# Question 3.3

Imagine a literal stack of plates. If the stack gets too high, it might topple.
Implement a datastructure that creates new stacks once preceding ones reach a
threshold. push and pop should operate as if it was one big stack. Also,
implement popAt(index) which pops from a specific stack.

## Solution

Since the stacks come in a linear order, and they need to be dynamically
allocated, this will be implemented using a linked list, with an element being
made up of a stack implemented as a static length array.

# Question 3.4

Implement the towers of hanoi using stacks

## Solution

To solve the hanoi towers we can directly map the problem to three stacks.
The height of the initial tower can be supplied via an argument, and the size of
each plate can be represented by an integer. The algorithm just needs to push
and pop plates from the stacks.

# Question 3.5

Implement a MyQueue class which implements a queue using two stacks

## Solution

To do this, you'd have the queue stack and the temp stack. The queue stack
contains the order of elements as if this was a normal queue. Whenever a new
element is added to MyQueue, all elements within the queue stack are poped and
then pushed into the temp stack. The new element is then pushed into the queue
stack, and then all the elements in the temp stack are poped and pushed into the
queue stack.

Note: This can be done lazily by insering into the temp stack, and only moving
elements over if the queue stack is empty.

# Question 3.6

Write a program to sort a stack in ascending order. You should not make any
assumptions on implementation and only use the functions: push, pop, peek,
isEmpty.

## Solution

A second stack can be used, and we can take a single value out, and transfer
elements between the stacks in a way that is similar to iterating through a list
