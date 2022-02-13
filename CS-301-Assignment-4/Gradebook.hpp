/*
 * Gradebook.hpp
 *
 *  Created on: Feb 12, 2022
 *      Author: Joshua Dunne
 */

#ifndef GRADEBOOK_HPP_
#define GRADEBOOK_HPP_

#include <map>
#include <string>
#include <vector>
#include <functional>


class Gradebook final {
private:
	constexpr static float WEIGHT_SUM = 100.0f;
	const static int MAX_NAME_LENGTH = 20;
	const static int MIN_USER_ID = 1;
	const static int MAX_USER_ID = 9999;

	std::map<std::string, float> mWeights;
	std::map<std::string, int> mUserIDs;
	std::map<std::string, std::map<std::string, std::vector<float>> > mGrades;
public:
	void setWeights(std::string categories[], float weights[], int numberOf);
	void addStudent(const std::string& name, const int id);
	void processGrades(const std::string& category, std::function<float(const std::string&, int)>request, int which);
	void changeGrade(const std::string& category, const std::string& name, int which, float newGrade);
	void calculateGrades(std::map<std::string, float>& grades);
	void dumpGrades() const;
};



#endif /* GRADEBOOK_HPP_ */
