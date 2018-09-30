// Tree Class Implementation
//
// Author: Matthew Knight
// File Name: tree.cpp
// Date: 2018-09-23
//
// This class is a basic tree container class

#include "tree.hpp"

#include <cmath>
#include <iostream>
#include <stack>
#include <memory>
#include <list>
#include <vector>

// Node ctor
template <typename T>
Tree<T>::Node::Node(T &val) 
	: val(val), ch({ nullptr, nullptr }) {}

// Node destructor
template <typename T>
Tree<T>::Node::~Node() {
	if (ch[LEFT] != nullptr)
		delete ch[LEFT];
	if (ch[RIGHT] != nullptr)
		delete ch[RIGHT];
};

// Probe ctor
template <typename T>
Tree<T>::Probe::Probe(Node *parent) 
	: parent(parent), ht({ -1, -1 }) {}

// add value to probe
template <typename T>
void Tree<T>::Probe::addHeight(int height) {
	if (ht[LEFT] < 0)
		ht[LEFT] = height;
	else if (ht[RIGHT] < 0)
		ht[RIGHT] = height;
}

// Tree ctor
template <typename T>
Tree<T>::Tree() : tree(nullptr) {}

// Ctor from sorted array
template <typename T>
Tree<T>::Tree(T *arr, size_t len) : tree(nullptr) {
	// first insert all values into the array consecutively
	for (int i = 0; i < len; i++) {
		insert(arr[i]);
	}
	
	// divide len by 2
	len = len >> 1;
	recursiveRotate(LEFT, &tree, len);
}

// rotate by a direction once
template <typename T>
void Tree<T>::rotate(Direction dir, Node **node) {
	if (*node == nullptr || (*node)->ch[!dir] == nullptr)
		return;

	Node *tmp = *node;
	*node = (*node)->ch[!dir];
	tmp->ch[!dir] = (*node)->ch[dir];
	(*node)->ch[dir] = tmp;
}

// rotate recursively
template <typename T>
void Tree<T>::recursiveRotate(Direction dir, Node **node, int num) {
	if (*node == nullptr)
		return;

	for (int i = 0; i < num; i++)
		rotate(dir, node);
	
	num = num >> 1;
	if (num > 0) {
		recursiveRotate(LEFT, &((*node)->ch[RIGHT]), num);
		recursiveRotate(RIGHT, &((*node)->ch[LEFT]), num);
	}
}

// insert value into tree
template <typename T>
void Tree<T>::insert(T val) {
	if (tree == nullptr) {
		tree = new Node(val);
	} else {
		Node *cursor = tree;
		bool dir;
		while (true) {
			// determine direction
			if (val < cursor->val)
				dir = LEFT;
			else
				dir = RIGHT;
			
			// continue, or insert node
			if (cursor->ch[dir] == nullptr) {
				cursor->ch[dir] = new Node(val);
				break;
			} else {
				cursor = cursor->ch[dir];
			}
		}
	}
}

// return height of a node using recursion
template <typename T>
int Tree<T>::nodeHeight(Node *node) {
	if (node == nullptr)
		return 0;
	else
		return std::max(nodeHeight(node->ch[RIGHT]), nodeHeight(node->ch[LEFT]))
			+ 1;
}

// return height of the tree
template <typename T>
int Tree<T>::height() {
	return nodeHeight(tree);
}

// traverse using preorder and call callback
template <typename T>
void Tree<T>::preorder(
	Node *node, 
	std::function<void (Node *node, int depth)> callback,
	int depth
) {
	if (node == nullptr)
		return;
	
	callback(node, depth);
	
	depth += 1;
	
	preorder(node->ch[LEFT], callback, depth);
	preorder(node->ch[RIGHT], callback, depth);
}


// get list of values of each node at each level
template <typename T>
std::unique_ptr<std::vector<std::list<T>>> Tree<T>::getList() {
	std::unique_ptr<std::vector<std::list<T>>> list(new std::vector<std::list<T>>);
	
	preorder(tree, [&](Node *node, int depth) {
		if ((*list).size() < depth + 1)
			(*list).resize(depth + 1);

		(*list)[depth].push_back(node->val);
	}, 0);
	
	return list;
}

// check if the tree is balanced
template <typename T>
bool Tree<T>::balanced() {
	std::stack<Probe> stack;
	Node *cursor = tree;
	
	// load root node
	if (cursor != nullptr) {
		stack.emplace(cursor);
	}

	while (!stack.empty()) {
		Probe probe = stack.top();	
		
		// One of the heights hasn't been determined
		if (stack.top().ht[LEFT] < 0 || stack.top().ht[RIGHT] < 0) {
			bool dir;
			// choose height to determine
			if (stack.top().ht[LEFT] < 0)
				dir = LEFT;
			else 
				dir = RIGHT;	
			
			if (cursor->ch[dir] == nullptr) {
				stack.top().ht[dir] = 0;
			} else {
				stack.emplace(cursor);
				cursor = cursor->ch[dir];
			}	
		// both node's height have been determined
		} else {
			// definition of unbalanced
			if (std::abs(stack.top().ht[LEFT] - stack.top().ht[RIGHT]) > 1) {
				return false;
			} else {
				int height = std::max(stack.top().ht[LEFT], stack.top().ht[RIGHT]);

				stack.pop();
				if (!stack.empty())
					stack.top().addHeight(height + 1);
			}
		}
	}

	return true;
}

// dtor
template <typename T>
Tree<T>::~Tree() {
	if (tree != nullptr)
		delete tree;
}
