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
	int numberOfEachCategory[] = {1, 2, 3};
	book.setWeights(categories, weights, numberOfCategories);

	book.addStudent("Josh", 1234);
	book.addStudent("Bill", 4321);

	for (int i = 0; i < numberOfCategories; i++) {
		auto category = categories[i];
		for (int j = 0; j < numberOfEachCategory[i]; j++) {
			auto getFunc = [category, j](const std::string& name, int id){
					std::cout << "enter grade for " << name << " (" << id
							  << ") for " << category << " #" << j + 1 << ": ";
					float grade;
					std::cin >> grade;
					return grade;
			};
			book.processGrades("Programs", getFunc, i + 1);
		}
	}

	book.dumpGrades();
	return 0;
}

