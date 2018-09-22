// Linked List structures
//
// Author: Matthew Knight
// File Name: linked-list.c
// Date: 2018-09-18
//
// This header defines the structures for a single and doubly linked lists. They
// may be added to other structures to enable them to be operated on by
// different functions. I have also included nodes specifically for integers
// since it looks like all the questions can be handled with basic integers for
// data.

#include "linked-list.h"

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

// list element creation
struct int_list_t *create_int_elem(int val) {
	struct int_list_t *elem = 
		(struct int_list_t*)malloc(sizeof(struct int_list_t));
	elem->val = val;
	return elem;
}

struct int_list_f_t *create_int_f_elem(int val) {
	struct int_list_f_t *elem = 
		(struct int_list_f_t*)malloc(sizeof(struct int_list_f_t));
	elem->val = val;
	return elem;
}

// free list memory starting from the head
int free_list(struct list *head) {
	struct list *term;
	while (head != NULL) {
		term = head;
		head = head->next;
		free(term);
	}
	return 0;
}

// check to see if all elements in a list are unique
bool is_unique(struct int_list_t *head) {
	for (; head != NULL; head = head->list.next) {
		// compare current node with all in list and return false id a duplicate
		// is found.
		for (
			struct int_list_t *cursor = head->list.next; 
			cursor != NULL;
			cursor = cursor->list.next
		) {
			if (cursor->val == head->val)
				return false;
		}
	}

	// all values are unique
	return true;
}

// get the length of a list
int get_length(struct int_list_t *head) {
	int count = 0;
	for (; head != NULL; head = head->list.next)
		count++;

	return count;
}

// create list from variable arguments
struct int_list_t *create_list(int num, ...) {
	va_list valist;
	va_start(valist, num);
	struct int_list_t *list = NULL, *last = NULL;	
	int i;
	for (i = 0; i < num; i++) {
		// create element
		struct int_list_t *elem = create_int_elem(va_arg(valist, int));

		if (list == NULL) {
			// first in list
			elem->list.next = NULL;
			elem->list.prev = NULL;
			list = elem;
		} else {
			// adding 
			last->list.next = elem;
			elem->list.next = NULL;
			elem->list.prev = last;
		}
		
		last = elem;
	}
	va_end(valist);
	return list;
}

// create forward list from variable arguments
struct int_list_f_t *create_f_list(int num, ...) {
	va_list valist;
	va_start(valist, num);
	struct int_list_f_t *list = NULL, *last = NULL;
	int i;
	for (i = 0; i < num; i++) {
		struct int_list_f_t *elem = create_int_f_elem(va_arg(valist, int));
		if (list == NULL) {
			elem->list.next = NULL;
			list = elem;
		} else {
			last->list.next = elem;
			elem->list.next = NULL;
		}
		last = elem;
	}

	return list;
}
// remove duplicate values from a list
int remove_dup(struct int_list_t *head) {
	for (; head != NULL; head = head->list.next) {
		struct int_list_t *cursor = head->list.next; 
		// compare current node with all in list and delete if it is a duplicate
		while (cursor != NULL) {

			if (cursor->val == head->val) {
				struct int_list_t *temp = cursor->list.next;
				cursor = cursor->list.prev;
				free(cursor->list.next);

				// stitch the list together.
				cursor->list.next = temp;
				temp->list.prev = cursor;
				cursor = temp;
			} else {
				cursor = cursor->list.next;
			}
		}
	}
	return 0;
}

// get nth last node of singly linked list
struct int_list_f_t *get_nth_last(struct int_list_f_t *head, unsigned int n) {
	int num = get_length(head) - n - 1;
	int i;
	for(i = 0; i < num; i++) {
		head = head->list.next;
	}

	return head;
}

// delete node from singly linked list
int del_node(struct int_list_f_t *head) {
	struct int_list_t *tmp = head->list.next;
	memcpy(head, tmp, sizeof(struct int_list_t));
	free(tmp);
	return 0;
}

// add values of two nodes, return a new node with their sum
struct int_list_t *add_nodes(struct int_list_t *lhs, struct int_list_t *rhs) {
	int val;
	if (lhs == NULL && rhs != NULL)
		val = rhs->val;
	else if (rhs == NULL && lhs != NULL)
		val = lhs->val;
	else if (rhs == NULL && lhs == NULL)
		val = 0;
	else
		val = lhs->val + rhs->val;

	struct int_list_t *result = (struct int_list_t*)malloc(sizeof(struct int_list_t));
	result->val = val;
	result->list.next = NULL;
	result->list.prev = NULL;
	return result;
}
