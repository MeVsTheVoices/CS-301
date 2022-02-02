/*
 * main.cpp
 *
 *  Created on: Feb 2, 2022
 *      Author: Joshua Dunne
 */

#include "InputFileWrapper.hpp"

#include <string>
#include <iostream>

int main() {
	InputFileWrapper fileWrapper;

	std::cout << fileWrapper.execute("GetLength") << std::endl;
	std::cout << fileWrapper.execute("PutItem 3") << std::endl;
	return 0;
}


