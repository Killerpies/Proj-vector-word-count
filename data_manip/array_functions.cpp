#include "../includes/array_functions.h"
#include "../includes/utilities.h"
#include <algorithm>
using namespace std;

namespace KP {
//remove all elements from vector that tracks words and their occurrences
void clear(std::vector<constants::entry> &entries) {

}

//return how many unique words are in the vector
int getSize(std::vector<constants::entry> &entries) {
	return entries.size();
}
//get word at location i iff i<size(see above function), otherwise return the last word
//(this is lazy, should throw an exception instead)
std::string getWordAt(std::vector<constants::entry> &entries, int i) {
	if (i < entries.size()) {
		return entries[i].word;
	}
	return entries[entries.size()].word;
}
//get number_occurences at location i iff i<size(see above function), otherwise return the last number_occurences
//(this is lazy, should throw an exception instead)
int getNumbOccurAt(std::vector<constants::entry> &entries, int i) {
	if (i < entries.size()) {
		return entries[i].number_occurences;
	}
	return entries[entries.size()].number_occurences;
}

/*loop through the entire file, one line at a time
 * call processLine on each line from the file
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::vector<constants::entry> &entries,
		std::fstream &myfstream) {

	if (myfstream.is_open()) {
		string tp;
		while (getline(myfstream, tp)) { //read data from file object and put it into string.
			processLine(entries, tp);
		}
		return true;
	}
	return false;
}

/*take 1 line and extract all the tokens from it
 feed each token to processToken for recording*/
void processLine(std::vector<constants::entry> &entries, std::string &myLine) {
	stringstream ss(myLine);
	string tempToken;
	while (getline(ss, tempToken, constants::CHAR_TO_SEARCH_FOR)) {
		processToken(entries, tempToken);
	}

}
/*NOTE: first call strip_unwanted_chars from utilities to get rid of rubbish chars in the token
 * if the token is an empty string after this then return since we are not tracking empty strings
 *
 * Keep track of how many times each token seen, in other words look thru the entries vector that
 * holds entry structs to see if there is a struct that has entry.word==token,
 * if so increment entry.number_occurences, otherwise create a new entry struct for the token,
 * set entry.number_occurences=1 and add it to the entries vector*/
void processToken(std::vector<constants::entry> &entries, std::string &token) {
	strip_unwanted_chars(token);

	if (token == "") {
		return;
	}

	int size = entries.size();
	bool wordExists = false;
	string tempUppercase;
	string tempLowercase;
	locale loc;
	for (int i = 0; i < token.length(); ++i) {
		tempUppercase += toupper(token[i], loc);
	}
	for (int i = 0; i < token.length(); ++i) {
		tempLowercase += tolower(token[i], loc);
	}

	for (int i = 0; i < size; i++) {
		if (entries[i].word == tempLowercase
				|| entries[i].word == tempUppercase || entries[i].word == token) {
			entries[i].number_occurences += 1;
			wordExists = true;
//					cout << "this is a word " + entries[i].word;
		}
	}

	if (!wordExists) {
		constants::entry newEntry = { token, tempUppercase, 1 };
		entries.push_back(newEntry);
	}


}

bool compareAscending(const constants::entry& x, const constants::entry& y)
{
	return x.word_uppercase < y.word_uppercase;
}

bool compareDecending(const constants::entry& x, const constants::entry& y)
{
	return x.word_uppercase > y.word_uppercase;
}

bool compareNumberOccurences(const constants::entry& x, const constants::entry& y)
{
	return x.number_occurences > y.number_occurences;
}
/*
 * Sort entries based on so enum value.
 * Please provide a solution that sorts according to the enum
 * The presence of the enum implies a switch statement based on its value
 * See the course lectures and demo projects for how to sort a vector of structs
 */
void sort(std::vector<constants::entry> &entries, constants::sortOrder so) {

switch (so) {
case constants::NONE:
	break;
case constants::ASCENDING:
	std::sort(entries.begin(), entries.end(), compareAscending);

	break;
case constants::DESCENDING:
	std::sort(entries.begin(), entries.end(), compareDecending);
	break;
case constants::NUMBER_OCCURRENCES:
	std::sort(entries.begin(), entries.end(), compareNumberOccurences);
	break;
default:
	cout << "Invalid input" << endl;
}

}

}
