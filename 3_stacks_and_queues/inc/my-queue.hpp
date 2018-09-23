// MyQueue Class Interface
//
// Author: Matthew Knight
// File Name: my-queue.hpp
// Date: 2018-09-22
//
// This class implements a basic queue by using two stacks

#ifndef MY_QUEUE_HPP
#define MY_QUEUE_HPP

#include <stack>

template <typename T>
class MyQueue {
	std::stack<T> bucket;
	std::stack<T> queue;
	
	// transfer from bucket to queue
	void transfer();

public:
	MyQueue();
	
	// check if MyQueue is empty
	bool empty();

	// get size of MyQueue
	size_t size();

	// push value into the MyQueue
	void push(T &val);

	// pop value from MyQueue
	void pop();

	// get reference to first element
	T &first();
};

#endif // MY_QUEUE_HPP
