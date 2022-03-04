/*
 * CirculeDoubleLinkedList_test.cpp
 *
 *  Created on: Mar 3, 2022
 *      Author: Feast
 */

#include "CircularlyDoublyLinkedList.h"

int main() {

	Quiz6::CircularlyDoublyLinkedList aList;

	aList.insert(6);
	aList.insert(5);
	aList.insert(4);
	aList.insert(7);
	aList.insert(8);
	aList.insert(9);

	aList.append(12);
	aList.append(13);
	aList.append(14);
	aList.append(15);
	aList.append(16);

	aList.print();

	return 0;
}

