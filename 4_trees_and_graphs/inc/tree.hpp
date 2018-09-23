// Tree Class Interface
//
// Author: Matthew Knight
// File Name: tree.hpp
// Date: 2018-09-23
//
// This class is a basic tree container class

#ifndef TREE_HPP
#define TREE_HPP

template <typename T>
class Tree {
	// subclass declaration
	class Node {
		friend class Tree;
		T val;
		Node *left, *right;
		// ctor and dtor
		Node(T &val);
		~Node();
	};

	class Probe {
		friend class Tree;
		Node *parent;
		int left, right;

		// ctor
		Probe(Node *parent);
		void addHeight(int height);
	};

	// private members
	Node *tree;

public:
	// default ctor
	Tree();

	// insert value into tree
	void insert(T &val);

	// check if the tree is balanced
	bool balanced();

	// dtor
	~Tree();
};

#endif
