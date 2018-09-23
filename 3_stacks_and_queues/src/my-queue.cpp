// MyQueue Class Interface
//
// Author: Matthew Knight
// File Name: my-queue.cpp
// Date: 2018-09-22
//
// This class implements a basic queue by using two stacks

#include "my-queue.hpp"

// transfer from bucket to queue stack
template <typename T>
void MyQueue<T>::transfer() {
	while (!bucket.empty()) {
		queue.push(bucket.front());
		bucket.pop();
	}
}

// check if MyQueue is empty
template <typename T>
bool MyQueue<T>::empty() {
	return queue.empty() && bucket.empty();
}

// get size of MyQueue
template <typename T>
size_t MyQueue<T>::size() {
	return queue.size() + bucket.size();
}

// push value into the MyQueue
template <typename T>
void MyQueue<T>::push(T &val) {
	bucket.push(val);
}

// pop value from MyQueue
template <typename T>
void MyQueue<T>::pop() {
	if (queue.empty())
		transfer();
	queue.pop();
}

// get reference to first element
template <typename T>
T &MyQueue<T>::first() {
	if (queue.empty())
		transfer();
	return queue.front();
}
