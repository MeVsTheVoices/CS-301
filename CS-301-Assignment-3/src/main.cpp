/*
 * main.cpp
 *
 *  Created on: Feb 2, 2022
 *      Author: Joshua Dunne
 */

#include "InputFileWrapper.hpp"

#include <string>
#include <iostream>

#include <fstream>

int main() {
	InputFileWrapper fileWrapper(5);


	const std::string inputFileName("specification/listData");
	std::ifstream inputFile(inputFileName, std::ios::in);
	if (!inputFile.good()) {
		std::cout << "failed to open input file " << inputFileName << std::endl;
		return -1;
	}

	const std::string outputFileName("example_output.txt");
	std::ofstream outputFile(outputFileName);
	if (outputFile.bad()) {
		std::cout << "failed to open output file " << outputFileName << std::endl;
		return -1;
	}

	std::string aLine;
	while(std::getline(inputFile, aLine)) {
		std::string s(fileWrapper.execute(aLine));
		std::cout << s << std::endl;
		outputFile << s << std::endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}


