// Linked List structures
//
// Author: Matthew Knight
// File Name: linked-list.h
// Date: 2018-09-18
//
// This header defines the structures for a single and doubly linked lists. They
// may be added to other structures to enable them to be operated on by
// different functions. I have also included nodes specifically for integers
// since it looks like all the questions can be handled with basic integers for
// data.

#ifndef LINKED_LIST_PRACTICE_H
#define LINKED_LIST_PRACTICE_H

#include <stdlib.h>
#include <stdbool.h>

// single linked list
struct forward_list {
	struct forward_list *next;
};

// doubly linked list
struct list {
	struct list *next;
	struct list *prev;
};

// list that contains integers
struct int_list_t {
	struct list list;
	int val;
};

// forward list containing integers
struct int_list_f_t {
	struct forward_list list;
	int val;
};

// list element creation
struct int_list_t *create_int_elem(int val);
struct int_list_f_t *create_int_f_elem(int val);

// free list memory starting from the head
int free_list(struct list *head);

// Check to see if values in a list are unique
bool is_unique(struct int_list_t* head);

// get length of a list
int get_length(struct int_list_t* head);

// create list with variable arguments
struct int_list_t *create_list(int, ...);
struct int_list_f_t *create_f_list(int, ...);

// removes duplicate values from a list
int remove_dup(struct int_list_t* head);

// delete node from singly linked list
int del_node(struct int_list_f_t *head);

// get nth last node in foward list
struct int_list_f_t *get_nth_last(struct int_list_f_t *head, unsigned int n);

// adds the values of two nodes and returns a pointer to a newly created one
// with their summed value
struct int_list_t *add_nodes(struct int_list_t *lhs, struct int_list_t *rhs);

#endif
