/*
 * IsPalindrome.hpp
 *
 *  Created on: Mar 7, 2022
 *      Author: Feast
 */

#ifndef ISPALINDROME_HPP_
#define ISPALINDROME_HPP_


#include <string>
#include <algorithm>

bool isPalindrome_(std::string str1, std::string str2) {
	if (str1.length() > 0 && str2.length() > 0)
		if (str1[0] == str2[0])
			return isPalindrome_(str1.substr(1), str2.substr(1));
		else
			return false;
	return true;
}


bool isPalindrome(std::string str) {
	std::string backwards;
	backwards.resize(str.length());
	std::reverse_copy(str.begin(), str.end(), backwards.begin());
	return isPalindrome_(str, backwards);
}

#endif /* ISPALINDROME_HPP_ */
