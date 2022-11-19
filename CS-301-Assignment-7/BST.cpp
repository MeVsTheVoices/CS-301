/*
 * BST.cpp
 *
 *  Created on: Mar 24, 2022
 *      Author: Feast
 */

#include "BST.hpp"

#include <iostream>

namespace Assignment7 {

void BST::insert(int x) {
	insert(mRoot, x);
}

void BST::insert(Node* &node, int x) {
	if (node == nullptr) {
		node = newNode(x);
		return;
	}
	if (x < (node->mData)) {
		if (node->mLeftNode == nullptr) {
			node->mLeftNode = newNode(x);
			return;
		}
		else {
			insert(node->mLeftNode, x);
		}
	}
	if (x > (node->mData)) {
		if (node->mRightNode == nullptr) {
			node->mRightNode = newNode(x);
			return;
		}
		else {
			insert(node->mRightNode, x);
		}
	}
}

void BST::traverseInOrder(std::function<void(int)> queue) {
	traverseInOrder(mRoot, queue);
}


BST::Node* BST::newNode(int x) {
	Node* aNewNode = new Node;
	aNewNode->mData = x;
	aNewNode->mLeftNode = nullptr;
	aNewNode->mRightNode = nullptr;
	return aNewNode;
}

void BST::traverseInOrder(Node* node, std::function<void(int)> queue) {
	if (node != nullptr) {
		traverseInOrder(node->mLeftNode, queue);
		queue(node->mData);
		traverseInOrder(node->mRightNode, queue);
	}
}

} /* namespace Assignment7 */
