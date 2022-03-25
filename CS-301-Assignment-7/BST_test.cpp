/*
 * BST_test.cpp
 *
 *  Created on: Mar 24, 2022
 *      Author: Feast
 */

#include "BST.hpp"

#include <queue>
#include <iostream>

namespace Assignment7 {

void doBST_tests() {
	std::queue<int> aQueue;

	BST aBST;

	for (int i = 0; i < 100; i++) {
		aBST.insert(i);
	}

	aBST.traverseInOrder([&aQueue](int a) {
		aQueue.emplace(a);
	});

	while (!aQueue.empty()) {
		std::cout << aQueue.front() << std::endl;
		aQueue.pop();
	}

}

} /* namespace Assignment7 */
