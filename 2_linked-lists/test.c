// Chapter 2 test program
//
// Author: Matthew Knight
// File Name: test.c
// Date: 2018-09-14
//
// This program contains all tests for chapter two questions.

#include "linked-list.h"

#include <assert.h>
#include <stdlib.h>

int main() {
	// Question 1	
	int len = 6;
	struct int_list_t *dup = create_list(len, 2, 3, 2, 7, 8, 9);
	assert(remove_dup(dup) == 0);
	assert(get_length(dup) == len - 1);
	
	free_list(dup);

	// Question 2
	struct int_list_f_t *list = create_f_list(len, 2, 3, 2, 7 ,8, 9);
	assert(get_nth_last(list, 2)->val == 7);

	// Question 3
	assert(del_node(list->list.next) == 0);
	assert(get_length(list) == len - 1);
	
	free_list(list);

	// Question 4
	struct int_list_t *lhs = create_list(3, 2, 1, 5);
	struct int_list_t *rhs = create_list(3, 0, 0, 5);
	struct int_list_t *result = NULL;
	struct int_list_t *left = lhs, *right = rhs, *cursor;
	int carry = 0;
	
	// apply 
	while (!(left == NULL && right == NULL)) {
		struct int_list_t *elem = add_nodes(left, right);
		elem->val += carry;
		carry = elem->val / 10;
		elem->val %= 10;

		if (result == NULL) {
			result = elem;
			cursor = result;
		} else {
			cursor->list.next = elem;
			elem->list.prev = cursor;
			cursor = elem;
		}
		if (left != NULL)
			left = left->list.next;
		if (right != NULL)
			right = right->list.next;
	}

	// go through list and make sure answer is correct
	int i = 0;
	cursor = result;
	for (; cursor != NULL; cursor = cursor->list.next) {
		switch (i) {
			case 0:
				assert(cursor->val == 2);
				break;
			case 1:
				assert(cursor->val == 1);
				break;
			case 2:
				assert(cursor->val == 0);
				break;
			case 3:
				assert(cursor->val == 1);
				break;
		}
		i++;
	}
	
	// Question 5
	struct int_list_t *circle = create_list(len, 0, 1, 2, 3, 4, 5);

}
