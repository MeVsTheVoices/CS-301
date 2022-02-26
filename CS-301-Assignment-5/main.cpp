/*
 * main.cpp
 *
 *  Created on: Feb 20, 2022
 *      Author: Joshua Dunne
 */

#include "DynamicStack.hpp"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

void readInFile(AS5::DynamicStack<int>&, std::istream& inputFile);
void readOutFile(AS5::DynamicStack<int>&, std::ostream& outputFile);


int main() {
	AS5::DynamicStack<int> stack;


	static const std::string inputFileName = "a.in";
	static const std::string outputFileName = "a.out";

	std::ifstream inputFile;
	inputFile.open(inputFileName);

	std::vector<int> lines;

	while (!inputFile.eof()) {
		int line;
		inputFile >> line;
		std::cout << line << std::endl;
		lines.push_back(line);
	}

	std::ofstream outputFile;
	outputFile.open(outputFileName);

	for (auto i : lines) {
		stack.push(i);
	}

	while (!stack.isEmpty()) {
		int popped = stack.pop();
		outputFile << popped;
		std::cout << popped << std::endl;
	}

	return 0;

}


