/*
 * utilities.h
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_
#include <string>
	//uppercase a string, useful for confirming that To==TO==to==tO
	void toUpper(std::string &myString);

	//take an int return a string
	std::string intToString(int Number);

	//get rid of some unwanted chars
	//returns: 	true if length >0
	//   		false if its empty
	bool strip_unwanted_chars(std::string &mystring);

	//returns: true file is there, false if not
	bool does_file_exist(const std::string &file_name);

#endif /* UTILITIES_H_ */
