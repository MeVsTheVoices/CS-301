/*
 * Trotter.cpp
 *
 *  Created on: Jan 24, 2022
 *      Author: Joshua Dunne
 */

#include "Trotter.hpp"

#include <algorithm>
#include <iostream>

void createListOfNaturalNumbers(vector<int>& vectorToFill, int startingAt, int endingAt) {
	vectorToFill.reserve((endingAt-startingAt) + 1);
	for (int i = 0; i < (endingAt-startingAt) + 1; i++)
		vectorToFill.push_back(startingAt + i);
}

void createListOfDirections(vector<bool>& vectorPointsLeft, int ceil) {
	vectorPointsLeft.reserve(ceil);
	for (int i = 0; i < ceil; i++)
		vectorPointsLeft.push_back(true);
}

bool isElementMobile(const vector<int>& elements, const vector<bool>& isLeft, int i) {
	 if ((i > 0) && isLeft[i] && (elements[i] > elements[i - 1]))
		 return true;
	 else if ((i < (elements.size() -1 )) && (!isLeft[i]) && (elements[i] > elements[i + 1]))
		return true;
	return false;
}

int getIndexOfLargestMobile(const vector<int>& elements, const vector<bool>& isLeft) {
	int indexOf, valueOf;
	indexOf = -1;
	valueOf = INT_MIN;
	for (int i = 0; i < elements.size(); i++) {
		if (isElementMobile(elements, isLeft, i) && (elements[i] > valueOf)) {
			indexOf = i;
			valueOf = elements[i];
		}
	}
	return indexOf;
}

void swapInts(vector<int>::iterator a, vector<int>::iterator b) {
	int hold = *a;
	*a = *b;
	*b = hold;
}

void swapBools(vector<bool>& a, vector<bool>& b, int aIndex, int bIndex) {
	bool hold = a[aIndex];
	a[aIndex] = b[bIndex];
	b[bIndex] = hold;
}

int swapLargestMobileElement(vector<int>& elements, vector<bool>&isLeft, int largestMobileIndex) {
	int newLargestMobileIndex;
	vector<int>::iterator a = elements.begin() + largestMobileIndex;
	vector<int>::iterator b;
	if (isLeft[largestMobileIndex])
		b = elements.begin() + (largestMobileIndex - 1);
	else
		b = elements.begin() + (largestMobileIndex + 1);
	swapInts(a, b);
	int aIndex = largestMobileIndex;
	int bIndex;
	if (isLeft[largestMobileIndex])
		bIndex = aIndex - 1;
	else
		bIndex = aIndex + 1;
	newLargestMobileIndex = bIndex;
	swapBools(isLeft, isLeft, aIndex, bIndex);
	return newLargestMobileIndex;
}


void reverseDirectionOfAllLargerElements(const vector<int>& elements, vector<bool>& isLeft, int movedMobile) {
	int movedMobileValue = elements[movedMobile];

	for (int i = 0; i < elements.size(); i++) {
		if (movedMobileValue < elements[i])
			isLeft[i] = !isLeft[i];
	}
}

bool doOnePermutation(vector<int>& elements, vector<bool>& isLeft) {
	int indexOfMobileBeforeMove = getIndexOfLargestMobile(elements, isLeft);
	if (indexOfMobileBeforeMove == -1)
		return false;
	int indexOfMobileAfterMove = swapLargestMobileElement(elements, isLeft, indexOfMobileBeforeMove);
	reverseDirectionOfAllLargerElements(elements, isLeft, indexOfMobileAfterMove);
	return true;
}

void doAllPermutations(vector<vector<int> >& results, const vector<int>& elements) {
	vector<int> newElements(elements);
	results.push_back(newElements);
	vector<bool> isLeft(elements.size(), true);
	int fac = factorial(elements.size());
	while (fac-- > 1) {
		doOnePermutation(newElements, isLeft);
		results.push_back(newElements);
	}
}

int factorial(int upTo) {
	int r = 1;
	for (int i = 2; i <= upTo; i++)
		r *= i;
	return r;
}
