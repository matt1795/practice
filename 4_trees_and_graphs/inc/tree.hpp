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
#include <functional>
#include <list>
#include <memory>
#include <vector>

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
	public:
		Node(T &val);
		~Node();
	};

	class Probe {
		friend class Tree;
		Node *parent;
		std::array<int, 2> ht;

	public:
		// ctor
		Probe(Node *parent);
		void addHeight(int height);
	};
	
	// private members
	Node *tree;
	
	// rotate node in one direction
	void rotate(Direction dir, Node **node);

	// recursively rotate 
	void recursiveRotate(Direction dir, Node **node, int num);

	// get height of a node
	int nodeHeight(Node *node);
	
	// traverse using different methods and call callback
	void preorder(
		Node *node, 
		std::function<void (Node *node, int depth)> callback, 
		int depth
	);

public:
	// default ctor
	Tree();
	
	// generate minimum height tree from sorted array
	Tree(T *arr, size_t len);

	// insert value into tree
	void insert(T val);

	// get height of the tree
	int height();
	
	// get list of values of each node at each level
	std::unique_ptr<std::vector<std::list<T>>> getList();

	// check if the tree is balanced
	bool balanced();

	// dtor
	~Tree();
};

#include "./tree.cpp"

#endif
