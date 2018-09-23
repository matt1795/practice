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
Tree<T>::Node::Node(T &val) : val(val), left(nullptr), right(nullptr) {}

// Node destructor
template <typename T>
Tree<T>::Node::~Node() {
	if (left != nullptr)
		delete left;
	if (right != nullptr)
		delete right;
};

// Probe ctor
template <typename T>
Tree<T>::Probe::Probe(Node *parent) : parent(parent), left(-1), right(-1) {}

// add value to probe
template <typename T>
void Tree<T>::Probe::addHeight(int height) {
	if (left < 0)
		left = height;
	else if (right < 0)
		right = height;
}

// Tree ctor
template <typename T>
Tree<T>::Tree() : tree(nullptr) {}

// insert value into tree
template <typename T>
void Tree<T>::insert(T &val) {
	if (tree == nullptr) {
		tree = new Node(val);
	} else {
		Node *cursor = tree;
		while (true) {
			// compare values
			if (val > cursor->val) {
				if (cursor->left == nullptr) {
					cursor->left = new Node(val);
					break;
				} else {
					cursor = cursor->left;
				}
			} else {
				if (cursor->right == nullptr) {
					cursor->right = new Node(val);
					break;
				} else {
					cursor = cursor->right;
				}
			}
		}
	}
}

// check if the tree is balanced
template <typename T>
bool Tree<T>::balanced() {
	std::stack<Tree::Probe> stack;
	Node *cursor = tree;

	while (!stack.empty()) {
		// left is unexplored
		if (stack.front().left < 0) {
			if (cursor->left == nullptr) {
				stack.front().left = 0;
			} else {
				stack.emplace(cursor);
				cursor = cursor->left;
			}
		// right is unexplored
		} else if (stack.front().right < 0) {
			if (cursor->right == nullptr) {
				stack.front().right = 0;
			} else {
				stack.emplace(cursor);
				cursor = cursor->right;
			}
		// both node's height have been determined
		} else {
			// definition of unbalanced
			if (std::abs(stack.front().right - stack.front().left) > 1) {
				return false;
			} else {
				int height = std::max(stack.front().right, stack.front().left);

				stack.pop();
				if (!stack.empty())
					stack.front().addHeight(height);
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
