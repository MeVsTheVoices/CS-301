/*
 * Trotter_unit_test.cpp
 *
 *  Created on: Jan 24, 2022
 *      Author: Joshua Dunne
 */

#include "Trotter_unit_test.hpp"

#include <iostream>

#include <iterator>

//test, from most basic to those compositing others
void doAllTrotterUnitTests() {
	checkCreateListOfNaturalNumbers();
	checkCreateListOfDirections();
	checkGetIndexOfLargestMobile();
	checkSwap();
	checkSwapLargestMobileElement();
	checkReverseDirectionOfAllLargerElements();
	checkDoOnePermutation();
	checkDoAllPermutations();
}

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

//using the specification given, gonna test out some simple cases
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

		for (int j = 0; j < testLength; j++) {
			elements.push_back(testsI[i][j]);
			isLeft.push_back(testsB[i][j]);
		}
		assert(getIndexOfLargestMobile(elements, isLeft) == results[i]);
	}
}

//should've used bitset, ended up needing two functions to swap ints and bools
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

	int newLargestMobileIndex = swapLargestMobileElement(elements, isLeft, largestIndex);

	assert(newLargestMobileIndex == 2);
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

	int rTest3I[] = {2, 3, 1};
	bool rTest3B[] = {false, true, true};

	reverseDirectionOfAllLargerElements(elements, isLeft, 2);

	for (int i = 0; i < testLength; i++) {
		assert(rTest3I[i] == elements[i]);
		assert(rTest3B[i] == isLeft[i]);
	}
}

//use the specification to make sure we're doing a single permutation correctly
void checkDoOnePermutation() {
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

		int test1IR[] = {1, 3, 2};
		bool test1IB[] = {true, true, true};
		int test2IR[] = {3, 2, 1};
		bool test2IB[] = {false, true, true};
		int test3IR[] = {2, 1, 3};
		bool test3IB[] = {true, true, false};

		int* testsI[] = {test1I, test2I, test3I};
		bool* testsB[] = {test1B, test2B, test3B};

		int* testsIR[] = {test1IR, test2IR, test3IR};
		bool* testsBR[] = {test1IB, test2IB, test3IB};

		cout << "testing single permutation" << endl;

		//loop through each test case, make sure that we're getting the correct result
		for (int i = 0; i < numbTests; i++) {
			elements.clear();
			isLeft.clear();

			for (int j = 0; j < testLength; j++) {
				elements.push_back(testsI[i][j]);
				isLeft.push_back(testsB[i][j]);
			}

			doOnePermutation(elements, isLeft);

			for (int j = 0; j < testLength; j++) {
				assert(elements[j] == testsIR[i][j]);
				assert(isLeft[j] == testsBR[i][j]);
			}
		}
}

#include <algorithm>

void checkDoAllPermutations() {
	cout << "testing permutations" << endl;
	for (int a = 3; a < 8; a++) {
		vector<vector<int> > permutations;
		vector<int> elements;
		createListOfNaturalNumbers(elements, 1, a);
		doAllPermutations(permutations, elements);

		for (auto i : permutations) {
			for (auto j : i)
				cout << j << ' ';
			cout << '\t';
		}
		cout << endl;

		cout << "should be " << factorial(a) << endl;

		sort(permutations.begin(), permutations.end());
		auto it = std::unique(permutations.begin(), permutations.end());

		//check that each permutation is unique
		assert(it == permutations.end());
		//check that there are the correct number of permutations
		assert(permutations.size() == factorial(a));

		auto isContainedInRange = [a](int b) { return (b >= 1 && b <= a); };

		//assert that the permutations generated contain only those element in the original set
		for (auto i : permutations)
			assert(std::all_of(i.begin(), i.end(), isContainedInRange));
	}
}
