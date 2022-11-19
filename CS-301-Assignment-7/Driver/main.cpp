/*
 * main.cpp
 *
 *  Created on: Mar 24, 2022
 *      Author: Feast
 */

#include "../BST.hpp"

#include <string>
#include <fstream>
#include <random>
#include <limits>
#include <iostream>
#include <queue>

const static std::string FILE_NAME = "a.out";

void writeToFile(int numberOf, std::ofstream& out);
void readFromFile(std::ifstream& in, Assignment7::BST& aTree);

int main() {
	std::ofstream out;
	out.open(FILE_NAME);
	writeToFile(200, out);
	out.close();

	Assignment7::BST aTree;
	std::ifstream in;
	in.open(FILE_NAME);
	readFromFile(in, aTree);

	//use of queue
	std::queue<int> aQueue;
	aTree.traverseInOrder([&aQueue](int a) {
		aQueue.emplace(a);
	});

	while (!aQueue.empty()) {
		int x;
		x = aQueue.front();
		std::cout << x << std::endl;
		aQueue.pop();
	}

	return 0;
}

void writeToFile(int numberOf, std::ofstream& out) {
	std::default_random_engine gen;
	std::uniform_int_distribution<int> dist(
		std::numeric_limits<int>::min(),
		std::numeric_limits<int>::max());
	for (int i = 0; i < numberOf; i++)
		out << dist(gen) << std::endl;
}

void readFromFile(std::ifstream& in, Assignment7::BST& aTree) {
	while (in.good() && !in.eof()) {
		int x;
		in >> x;
		aTree.insert(x);
	}
}


