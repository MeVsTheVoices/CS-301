/*
 * CirculeDoubleLinkedList.h
 *
 *  Created on: Mar 3, 2022
 *      Author: Feast
 */

#ifndef CIRCULARLYDOUBLYLINKEDLIST_H_
#define CIRCULARLYDOUBLYLINKEDLIST_H_

#include <iostream>

namespace Quiz6 {

class CircularlyDoublyLinkedList {
protected:
	struct DataType {
		int mData;
		DataType* mNext;
		DataType* mPrevious;

		DataType(int data) :
					mData(data) {
			mNext = nullptr;
			mPrevious = nullptr;
		}
	};

	DataType* mFirst;
	DataType* mLast;
public:

	CircularlyDoublyLinkedList() {
		mFirst = nullptr;
		mLast = nullptr;
	}

	virtual ~CircularlyDoublyLinkedList() {}

	void append(int data) {
		DataType* created = new DataType(data);
		if (mLast != nullptr) {
			mLast -> mNext = created;
		}
		else {
			mFirst = created;
		}
		created -> mPrevious = mLast;
		created -> mNext = mFirst;
		mLast = created;
	}

	void insert(int data) {
		DataType* created = new DataType(data);
		if (mFirst != nullptr) {
			mFirst -> mPrevious = created;
		}
		else {
			mLast = created;
		}
		created -> mNext = mFirst;
		created -> mPrevious = mLast;
		mFirst = created;
	}

	void print() {
		DataType* i;
		i = mFirst;
		if (i == nullptr) return;
		do {
			std::cout << i -> mData << std::endl;
			if ((i -> mNext == nullptr) || (i -> mNext == mFirst))
				return;
			i = i -> mNext;
		} while (true);
	}
};

} /* namespace Quiz6 */

#endif /* CIRCULARLYDOUBLYLINKEDLIST_H_ */
