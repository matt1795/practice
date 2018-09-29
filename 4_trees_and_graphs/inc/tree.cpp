// Tree Class Implementation
//
// Author: Matthew Knight
// File Name: tree.cpp
// Date: 2018-09-23
//
// This class is a basic tree container class

#include "tree.hpp"

#include <cmath>
#include <stack>

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
