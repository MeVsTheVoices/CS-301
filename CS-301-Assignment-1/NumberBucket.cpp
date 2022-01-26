/*
 * NumberBucket.cpp
 *
 *  Created on: Jan 22, 2022
 *      Author: joshuadunne
 */

#include "NumberBucket.hpp"

int NumberBucket::pop() {
	int hold;
	hold = mNB.top();
	mNB.pop();
	return hold;
}

size_t NumberBucket::get_size() const {
	return mNB.size();
}

bool NumberBucket::isEmpty() const {
	return mNB.empty();
}

void NumberBucket::push(int n) {
	mNB.push(n);
}

int NumberBucket::top() const {
	return mNB.top();
}
