/*
 * main.cpp
 *
 *  Created on: Feb 12, 2022
 *      Author: Joshua Dunne
 */

#include "Gradebook.hpp"

#include <iostream>

int main() {
	Gradebook book;
	int numberOfCategories = 3;
	std::string categories[] = {"Programs", "Tests", "Exams"};
	float weights[] = {50.0f, 20.0f, 30.0f};
	book.setWeights(categories, weights, numberOfCategories);

	book.addStudent("Josh", 1234);

	book.processGrades("Programs", [](const std::string& name, int id){
		std::cout << "enter grade for " + name + " (" + std::to_string(id) + "): ";
		float grade;
		std::cin >> grade;
		return grade;
	}, 1);

	book.dumpGrades();
	return 0;
}

