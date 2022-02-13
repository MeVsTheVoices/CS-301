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

void Gradebook::setWeights(std::string categories[], float weights[], int numberOf) {
	float sum = 0.0f;
	for (int i = 0; i < numberOf; i++) {
		sum += weights[i];
	}
	if (sum != WEIGHT_SUM)
		throw new std::invalid_argument("weights don't add together to be 100%");
	else {
		for (int i = 0; i < numberOf; i++) {
			mWeights[categories[i]] = weights[i];
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
	for(auto i : mWeights) {
		mGrades[i.first][name] = std::vector<float>();
	}
}


void Gradebook::processGrades(const std::string& category, std::function<float(const std::string&, int)> request, int which) {
//	std::map<std::string, std::map<std::string, std::vector<float>> > mGrades;
	auto& gradeSet = mGrades[category];
	for(auto& i : gradeSet) {
		float grade = request(i.first, mUserIDs[i.first]);
		std::cout << "got grade " << grade << std::endl;
		std::cout << "new size " << i.second.size() << std::endl;
		Utility::reserveSize(i.second, which);
		std::cout << "new size " << i.second.size() << std::endl;
		i.second[which - 1] = grade;
	}
}

void Gradebook::changeGrade(const std::string& category, const std::string& name, int which, float newGrade) {
	Utility::reserveSize(mGrades[category][name], which);
	mGrades[category][name][which] = newGrade;
}


void Gradebook::calculateGrades(std::map<std::string, float>& grades) {
	for (auto i : mWeights) {
		auto category = i.first;
		auto weight = i.second;
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

void Gradebook::dumpGrades() const {
	for (auto i : mGrades) {
		for (auto j : i.second) {
			for (auto k : j.second) {
				std::cout << i.first << ' ' << j.first << ' ' << k << std::endl;
			}
		}
	}
}


#endif /* GRADEBOOK_CPP_ */
