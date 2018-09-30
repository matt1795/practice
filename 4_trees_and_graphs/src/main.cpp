// testing enums

#include "tree.hpp"

#include <iostream>
#include <array>
#include <cstdlib>

#define NUM 17

int main() {
	for (int i = 0; i < NUM; i++) {
		int *integers = (int*)malloc(sizeof(int)*i);
		
		for (int j = 0; j < i; j++)
			integers[j] = j;

		Tree<int> tree(integers, i);
		
		std::cout 
			<< std::endl
			<< "Nodes: " 
			<< i 
			<< ", Depth: " 
			<< tree.height() 
			<< std::endl;

		auto list = tree.getList();

		for (auto depth : *list) {
			for (auto val : depth) {
				std::cout << val << ", ";
			}
			std::cout << std::endl;
		}
		free(integers);
	}
}
