/*
 * InputFileWrapper.hpp
 *
 *  Created on: Feb 2, 2022
 *      Author: Joshua Dunne
 */

#ifndef INPUTFILEWRAPPER_HPP_
#define INPUTFILEWRAPPER_HPP_

#include <map>
#include <functional>
#include <list>

using InputFunctionWithArgument = std::function<std::string(int)>;
using InputFunctionWithoutArgument = std::function<std::string()>;

class InputFileWrapper final {
private:
	std::map<std::basic_string<char>, InputFunctionWithArgument> mFunctionMapWithArgument;
	std::map<std::basic_string<char>, InputFunctionWithoutArgument> mFunctionMapWithoutArgument;

	std::list<int> mList;
public:
	InputFileWrapper();

	std::string execute(const std::string);
};


#endif /* INPUTFILEWRAPPER_HPP_ */
