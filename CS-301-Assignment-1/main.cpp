/*
 * main.cpp
 *
 *  Created on: Jan 22, 2022
 *      Author: Joshua Dunne
 */

#include "NumberBucket.hpp"

#include <iostream>

using namespace std;

int main() {
	NumberBucket nb;

	if (nb.isEmpty())
		cout << "bucket is empty" << endl;

	for (int i = 0; i < 5; i++) {
		cout << "pushing " << i << " on to bucket" << endl;
		nb.push(i);
		cout << "bucket now has " << nb.get_size() << " elements" << endl;
	}

	for (int i = 4; i >= 0; i--) {
		cout << "popping " << nb.top() << endl;
		nb.pop();
		cout << "bucket now has " << nb.get_size() << " elements" << endl;
	}

	if (nb.isEmpty())
		cout << "bucket is empty" << endl;
}
