/*
 * NumberBucket.h
 *
 *  Created on: Jan 22, 2022
 *      Author: joshuadunne
 *      Class:  CS-301
 */

#ifndef NUMBERBUCKET_HPP_
#define NUMBERBUCKET_HPP_

#include <stack>

using namespace std;

class NumberBucket {
private:
	stack<int> mNB;
public:
	int pop();

	size_t get_size() const;

	bool isEmpty() const;

	void push(int n);

	int top() const;
};

#endif /* NUMBERBUCKET_HPP_ */
