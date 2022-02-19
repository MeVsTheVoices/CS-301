/*
 * main.cpp
 *
 *  Created on: Feb 12, 2022
 *      Author: Joshua Dunne
 */

#include "Gradebook.hpp"

#include <iostream>
#include <fstream>

void setupNewSemester(Gradebook& book, std::ostream& transactionFile);
void addNewStudent(Gradebook& book, std::ostream& transactionFile);
void recordAssignment(Gradebook& book, std::ostream& transactionFile, const std::string& category);
void recordAssignmentForAll(Gradebook& book, std::ostream& transactionFile, const std::string& category, int which);
void changeGrade(Gradebook& book, std::ostream& transactionFile);
void calculateGrades(Gradebook& book, std::ostream& transactionFile);

int main() {
	Gradebook book;

	const std::string transactionFileName = "Grades.trn";
	const std::string datFileName = "Grades.dat";

	std::ofstream transactionFile;
	transactionFile.open(transactionFileName, std::ofstream::out | std::ofstream::app);

	std::ofstream datFile;
	datFile.open(datFileName, std::ofstream::out);

	char transactionChoice = 'S';
	while (transactionChoice != 'Q') {
		std::cout << "S/A/P/T/F/C/G/O/Q: ";
		std::cin >> transactionChoice;
		switch (transactionChoice) {
		case 'S':
			//start semester
			setupNewSemester(book, transactionFile);
			break;
		case 'A':
			//add student
			addNewStudent(book, transactionFile);
			break;
		case 'P':
			//programming assignment
			recordAssignment(book, transactionFile, "Programming");
			break;
		case 'T':
			//test score
			recordAssignment(book, transactionFile, "Test");
			break;
		case 'F':
			//final score
			recordAssignment(book, transactionFile, "Final");
			break;
		case 'C':
			//change grade
			changeGrade(book, transactionFile);
			break;
		case 'G':
			//calculate final grade
			calculateGrades(book, transactionFile);
			break;
		case 'O':
			//output grade data
			book.dumpGrades(std::cout);
			book.dumpGrades(transactionFile);
			book.dumpGrades(datFile);
			break;
		case 'Q':
			//quit
			break;
		default:
			//invalid input
			break;
		}
	}

	return 0;
}

void setupNewSemester(Gradebook& book, std::ostream& transactionFile) {
	int numberOfTypes = 3;
	std::string types[] = { "Programming", "Test", "Final" };
	float weights[numberOfTypes];
	int numberOfEach[numberOfTypes];
	for (int i = 0; i < numberOfTypes; i++) {
		std::cout << "weight for " << types[i] << " (0-100): ";
		std::cin >> weights[i];
		transactionFile << "weight for " << types[i] << " (0-100): " << weights[i] << std::endl;
		std::cout << "number of " << types[i] << " (integer > 0): ";
		std::cin >> numberOfEach[i];
		transactionFile << "number of " << types[i] << " (integer > 0): " << numberOfEach[i] << std::endl;
	}
	//void setGradebookDetails(std::string categories[], float weights[], int numberPerCategory[], int numberOf);
	book.setGradebookDetails(types, weights, numberOfEach, numberOfTypes);
}

void addNewStudent(Gradebook& book, std::ostream& transactionFile) {
//	void addStudent(const std::string& name, const int id);
	std::cout << "enter new student name (max 20 characters): ";
	std::string name;
	std::cin >> name;
	transactionFile << "enter new student name (max 20 characters): " << name << std::endl;

	std::cout << "enter new student id (1-9999): ";
	int id;
	std::cin >> id;
	transactionFile << "enter new student id (1-9999): " << id << std::endl;

	book.addStudent(name, id);
}

void recordAssignment(Gradebook& book, std::ostream& transactionFile, const std::string& category) {
	std::cout << "enter assignment #: ";
	int which;
	std::cin >> which;
	transactionFile << "enter assignment #: " << which << std::endl;

	recordAssignmentForAll(book, transactionFile, category, which);
}

void recordAssignmentForAll(Gradebook& book, std::ostream& transactionFile, const std::string& category, int which) {
	auto getFunc = [&](const std::string& name, int id, const std::string& category, int which) {
			std::cout << "enter grade for " << name << " (" << id
					  << ") for " << category << " #" << which << ": ";
			float grade;
			std::cin >> grade;
			transactionFile	<< "enter grade for " << name << " (" << id
					  	  	<< ") for " << category << " #" << which << ": " << grade << std::endl;
			return grade;
	};
	book.processGrades(category, getFunc, which);
}

void changeGrade(Gradebook& book, std::ostream& transactionFile) {
	std::cout << "enter student ID: ";
	int studentID;
	std::cin >> studentID;
	transactionFile << "enter student ID: " << studentID << std::endl;

	std::cout << "enter assignment category: ";
	std::string category;
	std::cin >> category;
	transactionFile << "enter assignment category: " << category << std::endl;

	std::cout << "enter assignment number #: ";
	int which;
	std::cin >> which;
	transactionFile << "enter assignment number #: " << which << std::endl;

	//void changeGrade(const std::string& category, int studentId, int which, float newGrade);
	std::cout << "enter new grade: ";
	float newGrade;
	std::cin >> newGrade;
	transactionFile << "enter new grade: " << newGrade << std::endl;

	book.changeGrade(category, studentID, which, newGrade);
}

void calculateGrades(Gradebook& book, std::ostream& transactionFile) {
	std::map<std::string, float> grades;
	book.calculateGrades(grades);
	for (auto i : grades) {
		std::cout << i.first << " totaled " << i.second << std::endl;
		transactionFile << i.first << " totaled " << i.second << std::endl;
	}
}
