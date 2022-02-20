/*
 * DynamicStack_test.cpp
 *
 *  Created on: Feb 20, 2022
 *      Author: Joshua Dunne
 */

#include "DynamicStack_test.hpp"

#include <iostream>

namespace AS5 {

void testDynamicStack() {
	DynamicStack<int> aStack;

	for (int i = 0; i <= 500; i++) {
		std::cout << i << ' ';
		aStack.push(i);
	}
	std::cout << std::endl;

	for (int i = 500; i >= 0; i--) {
		std::cout << i << ' ';
		assert(aStack.pop() == i);
	}
	std::cout << std::endl;

}

} /* namespace AS5 */
