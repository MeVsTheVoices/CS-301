/*
 * Trotter_unit_test.cpp
 *
 *  Created on: Jan 24, 2022
 *      Author: joshuadunne
 */

#include "Trotter_unit_test.hpp"

#include <iostream>

#include <iterator>

void doAllTrotterUnitTests() {
	checkCreateListOfNaturalNumbers();
	checkCreateListOfDirections();
	checkGetIndexOfLargestMobile();
	checkSwap();
	checkSwapLargestMobileElement();
	checkReverseDirectionOfAllLargerElements();
}

//vector<int> createListOfNaturalNumbers(vector<int>, int, int);
void checkCreateListOfNaturalNumbers() {
	int start = 1;
	int end = 25;
	vector<int> v;

	cout 	<< "testing creating a set of numbers "
			<< start << ", " << start + 1 << ", "
			<< start + 2 << ", ..., " << end << endl;

	createListOfNaturalNumbers(v, start, end);
	assert(v.size() == (end - start) + 1);
	for (int i = 0; i < (end - start) + 1; i++) {
		cout << v[i] << ' ';
		assert(v[i] == start + i);
	}
	cout << endl;
}

void checkCreateListOfDirections() {

}

void checkGetIndexOfLargestMobile() {
	vector<int> elements;
	vector<bool> isLeft;

	const int testLength = 3;
	const int numbTests = 3;

	int test1I[] = {1, 2, 3};
	bool test1B[] = {true, true, true};

	int test2I[] = {3, 1, 2};
	bool test2B[] = {true, true, true};

	int test3I[] = {2, 3, 1};
	bool test3B[] = {true, false, true};

	int* testsI[] = {test1I, test2I, test3I};
	bool* testsB[] = {test1B, test2B, test3B};

	int results[] = {2, 2, 1};

	cout << "testing getting largest mobile index" << endl;

	for (int i = 0; i < numbTests; i++) {
		elements.clear();
		isLeft.clear();

		cout << "test " << i << " is" << '\t';
		for (int j = 0; j < testLength; j++) {
			elements.push_back(testsI[i][j]);
			isLeft.push_back(testsB[i][j]);
			cout << elements.back() << ' ' << isLeft.back() << '\t';
		}
		cout << getIndexOfLargestMobile(elements, isLeft);
		assert(getIndexOfLargestMobile(elements, isLeft) == results[i]);
		cout << endl;
	}
}

void checkSwap() {
	cout << "checking swapInts function" << endl;
	{
		vector<int> a;
		a.push_back(1);
		a.push_back(2);

		swapInts(a.begin(), (a.begin() + 1));

		assert(a[0] == 2);
		assert(a[1] == 1);
	}

	cout << "checking swapBools function" << endl;
	{
		vector<bool> a;
		a.push_back(true);
		a.push_back(false);

		swapBools(a, a, 0, 1);

		assert(a[0] == false);
		assert(a[1] == true);
	}
}

void checkSwapLargestMobileElement() {
	cout << "checking swapping largest mobile element" << endl;

	const int testLength = 3;

	int test3I[] = {2, 3, 1};
	bool test3B[] = {true, false, true};

	vector<int> elements;
	vector<bool> isLeft;

	for (int i = 0; i < testLength; i++) {
		elements.push_back(test3I[i]);
		isLeft.push_back(test3B[i]);
	}

	int largestIndex = getIndexOfLargestMobile(elements, isLeft);

	cout << "largest index found is " << largestIndex << endl;

	for (int i = 0;i < testLength; i++) {
		cout << elements[i] << ' ' << isLeft[i] << '\t';
	}
	cout << endl;

	int newLargestMobileIndex = swapLargestMobileElement(elements, isLeft, largestIndex);

	cout << "now swapped" << endl;
	for (int i = 0;i < testLength; i++) {
		cout << elements[i] << ' ' << isLeft[i] << '\t';
	}
	cout << endl;

	cout << "largest mobile now in position " << newLargestMobileIndex << endl;
}

void checkReverseDirectionOfAllLargerElements() {
	cout << "checking reversing all larger than mobile element" << endl;

	const int testLength = 3;

	int test3I[] = {2, 3, 1};
	bool test3B[] = {true, false, true};

	vector<int> elements;
	vector<bool> isLeft;

	for (int i = 0; i < testLength; i++) {
		elements.push_back(test3I[i]);
		isLeft.push_back(test3B[i]);
	}

	for (int i = 0; i < testLength; i++) {
		cout << elements[i] << ' ' << isLeft[i] << '\t';
	}
	cout << endl;

	int rTest3I[] = {2, 3, 1};
	bool rTest3B[] = {false, true, true};

	reverseDirectionOfAllLargerElements(elements, isLeft, 2);

	for (int i = 0; i < testLength; i++) {
		cout << elements[i] << ' ' << isLeft[i] << '\t';
	}
	cout << endl;

	for (int i = 0; i < testLength; i++) {
		assert(rTest3I[i] == elements[i]);
		assert(rTest3B[i] == isLeft[i]);
	}
}
