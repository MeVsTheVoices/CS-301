/*
 * Trotter.hpp
 *
 *  Created on: Jan 24, 2022
 *      Author: joshuadunne
 */

#ifndef TROTTER_HPP_
#define TROTTER_HPP_

#include <vector>

using namespace std;

//create startingAt, startingAt + 1, startingAt + 2, ..., endingAt
void createListOfNaturalNumbers(vector<int>& vectorToFill, int startingAt, int endingAt);

void createListOfDirections(vector<bool>& vectorPointsLeft, int ceil);

bool isElementMobile(const vector<int>& elements, const vector<bool>& isLeft, int i);

int getIndexOfLargestMobile(const vector<int>& elements, const vector<bool>& isLeft);

void swapInts(vector<int>::iterator a, vector<int>::iterator b);

void swapBools(vector<bool>& a, vector<bool>& b, int aIndex, int bIndex);

int swapLargestMobileElement(vector<int>& elements, vector<bool>&isLeft, int largestMobileIndex);

void reverseDirectionOfAllLargerElements(const vector<int>& elements, vector<bool>& isLeft, int movedMobile);

bool doOnePermutation(vector<int>& elements, vector<bool>& isLeft);

#endif /* TROTTER_HPP_ */
