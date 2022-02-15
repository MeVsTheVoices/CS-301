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
	book.setGradebookDetails(categories, weights, numberOfEachCategory, numberOfCategories);

	book.addStudent("Josh", 1234);
	book.addStudent("Bill", 4321);


	for (int i = 0; i < numberOfCategories; i++) {
		auto category = categories[i];
		for (int j = 0; j < numberOfEachCategory[i]; j++) {
			//std::function<float(const std::string&, int, const std::string&, int)> request, int which);
			static auto getFunc = [](const std::string& name, int id, const std::string& category, int which){
					std::cout << "enter grade for " << name << " (" << id
							  << ") for " << category << " #" << which << ": ";
					float grade;
					std::cin >> grade;
					return grade;
			};
			book.processGrades(category, getFunc, j + 1);
		}
	}

	book.dumpGrades();
	return 0;
}

