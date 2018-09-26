// Tree Class Interface
//
// Author: Matthew Knight
// File Name: tree.hpp
// Date: 2018-09-23
//
// This class is a basic tree container class

#ifndef TREE_HPP
#define TREE_HPP

#include <array>

template <typename T>
class Tree {
	// children access and rotation definitiion
	enum Direction {
		LEFT = false,
		RIGHT = true
	};

	// subclass declaration
	class Node {
		friend class Tree;
		T val;
		std::array<Node*, 2> ch;
		// ctor and dtor
		Node(T &val);
		~Node();
	};

	class Probe {
		friend class Tree;
		Node *parent;
		std::array<int, 2> ht;

		// ctor
		Probe(Node *parent);
		void addHeight(int height);
	};
	
	// private members
	Node *tree;

	void rotate(Node **node, Direction dir);

	void recursiveRot(Node **node, Direction dir, int num);
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

#include "./tree.cpp"

#endif
