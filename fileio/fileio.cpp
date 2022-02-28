#include "../includes/fileio.h"
using namespace std;

/*if you are debugging the file must be in the project parent directory
 in this case Project2 with the .project and .cProject files*
 returns True - file opened successfully
 False - file not opened*/
bool openFile(std::fstream &myfile, const std::string &myFileName,
		std::ios_base::openmode mode) {

	myfile.open(myFileName, std::ifstream::in);
	if (myfile.is_open()) {
		return true;

	}

//	  char c = myfile.get();
//
//	  while (myfile.good()) {
//	    std::cout << c;
//	    c = myfile.get();
//	  }

//	  myfile.close();
	return false;
}

/*iff myfile is open then close it*/
void closeFile(std::fstream &myfile) {
	if (myfile.is_open()) {
		myfile.close();

	}

//	  char c = myfile.get();
//
//	  while (myfile.good()) {
//	    std::cout << c;
//	    c = myfile.get();
//	  }

}

/* serializes all content in entries to file outputfilename
 * check out utils for helpful type conversion functions
 * BTW serialize means the process of translating a data structure
 * into a format that can be stored in a file
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in the vector entries
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writetoFile(std::vector<constants::entry> &entries,
		const std::string &outputfilename) {
	if (entries.size() == 0) {
		return constants::FAIL_NO_ARRAY_DATA;
	}

	std::string tempstring;

	ofstream file;
	file.open(outputfilename.c_str());
	if (!file.is_open()) {
		return constants::FAIL_FILE_DID_NOT_OPEN;
	}

	if (file.is_open()) {
		for (int i = 0; i <= entries.size()-1; i++) {
			tempstring = entries[i].word + " "
					+ to_string(entries[i].number_occurences);
			file << tempstring << endl;

		}
		file.close();
	}


	return constants::SUCCESS;
}

