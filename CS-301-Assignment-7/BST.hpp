/*
 * BST.hpp
 *
 *  Created on: Mar 24, 2022
 *      Author: Feast
 */

#ifndef BST_HPP_
#define BST_HPP_

#include <functional>

namespace Assignment7 {

class BST {
public:

	struct Node {
		int mData;
		Node* mRightNode;
		Node* mLeftNode;
	};

	void insert(int x);

	void traverseInOrder(std::function<void(int)> queue);

protected:

	void insert(Node* &node, int x);

	Node* newNode(int x);

	void traverseInOrder(Node* node, std::function<void(int)> queue);

private:

	Node* mRoot = nullptr;

};

} /* namespace Assignment7 */

#endif /* BST_HPP_ */
