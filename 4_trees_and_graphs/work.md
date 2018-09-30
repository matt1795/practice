# Question 4.1

Implement a function to check if a tree is balanced. For the purposes of this
question, a balanced tree is defined to be a tree such that no two leaf nodes
differ in distance from the root by more than one.

# Question 4.2

Given a directed graph, design an algorithm to find out whether there is a route
between two nodes.

# Question 4.3

Given a sorted (increasing order) array, write an algorithm to create a binary
tree with minimal height.

# Question 4.4

Given a binary search tree, design an alogorithm which creates a linked list of
all the nodes at each depth (ie., if you have a tree of depth D, you'll have D
linked lists).

# Question 4.5

Write an algorithm to find the 'next' node. (ie., in-order successor) of a given
node in a binary search tree where each node has a link to its parent.

## Solution

Pseudocode:

```
nextInOrder(node) {
	if node has a right child
		if node's right child has a left child
			go left as long as you can
			return that node
		else
			return right child
	else if node is a left child
		if node has no parent
			return null
		else
			return parent
	else if node has a left child and a parent
		go up until parent is null
			if cursor is a left child
				return parent
		return null
	else
		return null

}
```

# Question 4.6

Design an algorithm and write code to find the first common ancestor of two
nodes in a binary tree. Avoid storing additional nodes in a data structure.
NOTE: this is not necessarily a binary search tree.

# Question 4.7

You have two very large binary trees: T1 with millions of nodes, and T2, with
hundreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.

# Question 4.8

You are given a binary tree in which each node contains a value. Design an
algorithm to print all paths ewhich sum up to that value. Note that it can be
any path in the tree -- it does not have to start at the root.

