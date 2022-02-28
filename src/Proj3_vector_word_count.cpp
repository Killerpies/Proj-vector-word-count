//============================================================================
// Name        : Proj3_vector_word_count.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../includes/constants.h"
#include "../includes/testing.h"
#include "../includes/array_functions.h"
#include "../includes/fileio.h"


using namespace std;
using namespace constants;

int main(int argc, char *argv[]) {

	string studentname = "Your";
	if (argc == 2) {
		//a command line param was passed in,
		//my script will pass in the student ID
		studentname = argv[1];
	}

	int grade=run_all_test();
	//what is your score
	cout<<studentname + " grade is "<<grade<<endl;
	return SUCCESS;
}
