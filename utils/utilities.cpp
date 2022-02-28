/*
 * utilities.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "../includes/utilities.h"

using namespace std;

//look up transform in algorithm, this API is fragile, does not work for non-ascii char sets
void toUpper(string &myString) {
	std::transform(myString.begin(), myString.end(), myString.begin(),
			::toupper);
}

//convert an int to a string
//return the string
string intToString(int Number) {
	std::stringstream ss;
	ss << Number;
	return ss.str();
}

//delete badchar if its in the string
void strip_char(string &s, char badchar){
	const int NUMBER_CHARS_TO_ERASE = 1;
	if (s.empty())
		return;

	std::size_t found = s.find(badchar);
	if (found!=std::string::npos)
		s.erase(found,NUMBER_CHARS_TO_ERASE);
}

//get rid of some unwanted chars
//returns: 	true if length >0
//   		false if its empty
bool strip_unwanted_chars(string &mystring){
	strip_char(mystring,'\r');
	strip_char(mystring,'.');
	strip_char(mystring,' ');
	strip_char(mystring,',');
	return (mystring.length()>0);
}

//returns: true file is there, false if not
bool does_file_exist(const std::string &file_name){
	std::ifstream fle(file_name);
	return fle.good();
}
