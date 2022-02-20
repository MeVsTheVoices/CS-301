/*
 * DynamicStack.hpp
 *
 *  Created on: Feb 20, 2022
 *      Author: Joshua Dunne
 */

#ifndef DYNAMICSTACK_HPP_
#define DYNAMICSTACK_HPP_

#include <vector>

namespace AS5 {

template<typename T>
class DynamicStack final {
private:
	std::vector<T> mStack;

	int mInitialCapacity;

public:
	DynamicStack(int initialCapacity = 1000) :
				mInitialCapacity(initialCapacity) {}

	T top() const {
		return mStack.front();
	}

	T isEmpty() const {
		return (mStack.size() == 0);
	}

	T isFull() const {
		return (mStack.size() >= mInitialCapacity);
	}

	T pop() {
		if (!isEmpty()) {
			T aReturn = mStack.back();
			mStack.pop_back();
			return aReturn;
		}
	}
	void push(T aElement) {
		if (!isFull())
			mStack.push_back(aElement);
	}
};

} /* namespace AS5 */

#endif /* DYNAMICSTACK_HPP_ */
