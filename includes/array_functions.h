/*
 * functionstocomplete.h
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */
#ifndef ARRAY_FUNCTIONS_H_
#define ARRAY_FUNCTIONS_H_
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>
#include "../includes/constants.h"

/*============================================================================
 * The following are declarations for functions that I will test
 * Please provide the definitions in the
 * included cpp file, do not erase the stuff I put in there please
 * DO NOT MODIFY THIS FILE, I WILL USE MY OWN COPY
/============================================================================*/

namespace KP{
	//remove all elements from vector that tracks words and their occurrences
	void clear(std::vector<constants::entry>  &entries);

	//return how many unique words are in the vector
	int getSize(std::vector<constants::entry>  &entries);

	//get word at location i iff i<size(see above function), otherwise return the last word
	//(this is lazy, should throw an exception instead)
	std::string getWordAt(std::vector<constants::entry>  &entries, int i);

	//get number_occurences at location i iff i<size(see above function), otherwise return the last number_occurences
	//(this is lazy, should throw an exception instead)
	int getNumbOccurAt(std::vector<constants::entry>  &entries,int i);

	/*loop through the entire file, one line at a time
	 * call processLine on each line from the file
	 * returns false: myfstream is not open
	 *         true: otherwise*/
	bool processFile(std::vector<constants::entry>  &entries,std::fstream &myfstream);

	/*take 1 line and extract all the tokens from it
	feed each token to processToken for recording*/
	void processLine(std::vector<constants::entry>  &entries,std::string &myLine);

	/*NOTE: first call strip_unwanted_chars from utilities to get rid of rubbish chars in the token
	 * if the token is an empty string after this then return since we are not tracking empty strings
	 *
	 * Keep track of how many times each token seen, in other words look thru the entries vector that
	 * holds entry structs to see if there is a struct that has entry.word==token,
	 * if so increment entry.number_occurences, otherwise create a new entry struct for the token,
	 * set entry.number_occurences=1 and add it to the entries vector*/
	void processToken(std::vector<constants::entry>  &entries,std::string &token);

	/*
	 * Sort entries based on so enum value.
	 * Please provide a solution that sorts according to the enum
	 * The presence of the enum implies a switch statement based on its value
	 * See the course lectures and demo projects for how to sort a vector of structs
	 */
	void sort(std::vector<constants::entry>  &entries, constants::sortOrder so);
}
#endif /* ARRAY_FUNCTIONS_H_ */
