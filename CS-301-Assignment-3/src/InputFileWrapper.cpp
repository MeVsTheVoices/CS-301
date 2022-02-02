/*
 * InputFileWrapper.cpp
 *
 *  Created on: Feb 2, 2022
 *      Author: Joshua Dunne
 */

#include "InputFileWrapper.hpp"

using InputFunctionWithArgument = std::function<std::string(int)>;
using InputFunctionWithoutArgument = std::function<std::string()>;

#include <iostream>

InputFileWrapper::InputFileWrapper() {
	InputFunctionWithoutArgument getLength = [this]() {
		return std::to_string(mList.size());
	};
	mFunctionMapWithoutArgument["GetLength"] = getLength;

	InputFunctionWithoutArgument printList = [this]() {
		std::string s;
		for (auto i : mList)
			s += i;
		return s;
	};
	mFunctionMapWithoutArgument["PrintList"] = printList;

	/*mFunctionMapWithoutArgument["PrintList"] = printList;
	mFunctionMapWithoutArgument["IsFull"] = isFull;
	mFunctionMapWithoutArgument["MakeEmpty"] = makeEmpty;
	mFunctionMapWithoutArgument["Quit"] = quit;*/

	InputFunctionWithArgument putItem = [this](int a) {
		mList.push_front(a);
		return std::to_string(a) + " is in list";
	};
	mFunctionMapWithArgument["PutItem"] = putItem;
	/*mFunctionMapWithArgument["GetItem"] = getItem;
	mFunctionMapWithArgument["DeleteItem"] = deleteItem;*/
}

#include <sstream>

std::string InputFileWrapper::execute(const std::string s) {
	if (s == "Quit")
		return "";

	std::stringstream splitter(s);

	std::string command;
	splitter >> command;

	if (mFunctionMapWithoutArgument.contains(command)) {
		return mFunctionMapWithoutArgument[command.c_str()]();
	}
	else if (mFunctionMapWithArgument.contains(command)) {
		std::string argument;
		splitter >> argument;
		return mFunctionMapWithArgument[command.c_str()](stoi(argument));
	}
	else {
		return s + " is not a valid command";
	}
}

