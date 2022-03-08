/*
 * main.cpp
 *
 *  Created on: Mar 7, 2022
 *      Author: Feast
 */


#include "IsPalindrome.hpp"

#include <vector>
#include <iostream>

int main() {
	//simple lambda to communicate results
	auto isPalindromeLambda = [](std::string str) -> bool {
		if (isPalindrome(str)) {
			std::cout << str << " is a palindrome" << std::endl;
			return true;
		}
		else {
			std::cout << str << " is not a palindrome" << std::endl;
			return false;
		}
	};


	//define some palindromes, some not
	std::vector<std::string> arePalindromes {
		"civic",
		"radar",
		"level",
		"rotor",
		"kayak"
	};

	std::vector<std::string> areNotPalindromes {
		"busy",
		"working",
		"going",
		"shows",
		"takes"
	};

	//combine these palindromes in to one vector
	std::vector<std::string> mightBePalindromes;

	mightBePalindromes.insert(mightBePalindromes.end(), arePalindromes.begin(), arePalindromes.end());
	mightBePalindromes.insert(mightBePalindromes.end(), areNotPalindromes.begin(), areNotPalindromes.end());

	//shuffle that vector
	std::random_shuffle(mightBePalindromes.begin(), mightBePalindromes.end());

	//using the lambda, communicate which strings are palindromes, which aren't
	std::for_each(mightBePalindromes.begin(), mightBePalindromes.end(), isPalindromeLambda);

	//quick check to make sure all palindromes are taken as palindromes
	if (std::all_of(arePalindromes.begin(), arePalindromes.end(), isPalindrome))
		std::cout << "all palindromes come back as palindromes" << std::endl;

	//another quick check to make sure all non palindromes come back as non palindromes
	if (std::none_of(areNotPalindromes.begin(), areNotPalindromes.end(), isPalindrome))
		std::cout << "all non palindromes come back as non palindromes" << std::endl;

	while (true) {
		std::cout << "enter something to test as a palindrome: ";
		std::string str;
		getline(std::cin, str);
		if (isPalindrome(str))
			std::cout << str << " is a palindrome" << std::endl;
		else
			std::cout << str << " is not a palindrome" << std::endl;
	}


	return 0;
}

