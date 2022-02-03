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
#include <algorithm>

InputFileWrapper::InputFileWrapper(int maxSize) :
			mMaxSize(maxSize) {
	InputFunctionWithoutArgument getLength = [this]() {
		return std::string("Length is ") + std::to_string(mList.size());
	};
	mFunctionMapWithoutArgument["GetLength"] = getLength;

	InputFunctionWithoutArgument printList = [this]() {
		std::string s;
		for (auto i : mList)
			s += std::to_string(i);
		return s;
	};
	mFunctionMapWithoutArgument["PrintList"] = printList;

	InputFunctionWithoutArgument isFull = [this]() {
		if (mList.size() >= mMaxSize)
			return std::string("List is full");
		else
			return std::string("List is not full");
	};
	mFunctionMapWithoutArgument["IsFull"] = isFull;

	InputFunctionWithoutArgument makeEmpty = [this]() {
		mList.clear();
		return std::string("list emptied");
	};
	mFunctionMapWithoutArgument["MakeEmpty"] = makeEmpty;

	//mFunctionMapWithoutArgument["Quit"] = quit;

	InputFunctionWithArgument putItem = [this](int a) {
		if (mList.size() >= mMaxSize)
			return std::string("list is already full");
		mList.push_front(a);
		return std::to_string(a) + " is in list";
	};
	mFunctionMapWithArgument["PutItem"] = putItem;

	InputFunctionWithArgument getItem = [this](int a) {
		if (std::find(mList.begin(), mList.end(), a) != mList.end())
			return std::to_string(a) + " is in list";
		else
			return std::to_string(a) + " not in list";
	};
	mFunctionMapWithArgument["GetItem"] = getItem;

	InputFunctionWithArgument deleteItem = [this](int a) {
		bool found = false;
		for (auto i = mList.begin(); i != mList.end(); i++) {
			if (*i == a) {
				i = mList.erase(i);
				found = true;
			}
		}
		if (found)
			return std::to_string(a) + " is deleted";
		else
			return std::to_string(a) + " couldn't be found to be deleted";
	};
	mFunctionMapWithArgument["DeleteItem"] = deleteItem;
}

#include <sstream>

std::string InputFileWrapper::execute(const std::string s) {
	std::stringstream splitter(s);

	std::string command;
	splitter >> command;

	if (command == "Quit")
		return "";
	else if (mFunctionMapWithoutArgument.contains(command)) {
		return mFunctionMapWithoutArgument[command.c_str()]();
	}
	else if (mFunctionMapWithArgument.contains(command)) {
		std::string argument;
		splitter >> argument;
		return mFunctionMapWithArgument[command.c_str()](stoi(argument));
	}
	else {
		return command + " is not a valid command";
	}
}

