/*
 * Gradebook.cpp
 *
 *  Created on: Feb 12, 2022
 *      Author: Joshua Dunne
 */

#ifndef GRADEBOOK_CPP_
#define GRADEBOOK_CPP_

#include "Gradebook.hpp"

#include <stdexcept>
#include <iostream>

namespace Utility {
	void reserveSize(std::vector<float>& x, int which) {
		if (x.size() < which) {
			for (int i = x.size(); i < which; i++)
				x.push_back(0);
		}
	}
}

void Gradebook::setGradebookDetails(std::string categories[], float weights[], int numberPerCategory[], int numberOf) {
	mCategories.clear();
	mUserIDs.clear();
	mGrades.clear();

	float sum = 0.0f;
	for (int i = 0; i < numberOf; i++) {
		sum += weights[i];
	}
	if (sum != WEIGHT_SUM)
		throw new std::invalid_argument("weights don't add together to be 100%");
	else {
		for (int i = 0; i < numberOf; i++) {
			CategoryAttribute attrib;
			attrib.mNumberPerCategory = numberPerCategory[i];
			attrib.mWeight = weights[i];
			mCategories.emplace(categories[i], attrib);
		}
	}
}

void Gradebook::addStudent(const std::string& name, const int id) {
	if(name.length() > MAX_NAME_LENGTH)
		throw new std::invalid_argument("student name exceeds max length of " + std::to_string(MAX_NAME_LENGTH));
	if ((id < MIN_USER_ID) || (id > MAX_USER_ID))
		throw new std::invalid_argument("user id outside of range " + std::to_string(MIN_USER_ID) + " - " + std::to_string(MIN_USER_ID));
	if (mUserIDs.contains(name))
		throw new std::invalid_argument("user already exists in gradebook " + name);
	mUserIDs[name] = id;
	for(auto i : mCategories) {
		mGrades[i.first][name] = std::vector<float>();
	}
}


void Gradebook::processGrades(
			const std::string& category,
			//calls for studentName, studentID, category, number
			std::function<float(const std::string&, int, const std::string&, int)> request, int which) {
//	std::map<std::string, std::map<std::string, std::vector<float>> > mGrades;
	/*if (which > mCategories[category].mNumberPerCategory)
		throw new std::invalid_argument(
					"attempting to add a " + category +
					" assignment larger than #" + std::to_string(mCategories[category].mNumberPerCategory));*/
	auto& gradeSet = mGrades[category];
	for(auto& i : gradeSet) {
		float grade = request(i.first, mUserIDs[i.first], category, which);
		Utility::reserveSize(i.second, which);
		i.second[which - 1] = grade;
	}
}

void Gradebook::changeGrade(const std::string& category, const std::string& name, int which, float newGrade) {
	if (which > mCategories[category].mNumberPerCategory)
		throw new std::invalid_argument(
					"attempting to add a " + category +
					" assignment larger than #" + std::to_string(mCategories[category].mNumberPerCategory));
	Utility::reserveSize(mGrades[category][name], which);
	mGrades[category][name][which - 1] = newGrade;
}


void Gradebook::calculateGrades(std::map<std::string, float>& grades) {
	for (auto i : mCategories) {
		auto category = i.first;
		auto weight = i.second.mWeight;
		auto gradedCategory = mGrades[category];
		for (auto j : gradedCategory) {
			float sum = 0;
			int numberOf = 0;
			for (;numberOf < j.second.size(); numberOf++)
				sum += j.second[numberOf];
			if (!grades.contains(j.first))
				grades[j.first] = 0.0f;
			grades[j.first] = (sum / static_cast<float>((numberOf + 1))) * (1.0f/(100.0f - weight));
		}
	}
}

void Gradebook::dumpGrades(std::ostream& o) const {
	for (auto i : mGrades) {
		std::cout << i.first << std::endl;
		for (auto j : i.second) {
			std::cout << '\t' << j.first << std::endl;
			int f = 0;
			for (auto k : j.second) {
				std::cout << "\t\t" << ++f << ' ' << k << std::endl;
			}
		}
	}
}


#endif /* GRADEBOOK_CPP_ */
