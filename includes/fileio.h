/*
 * fileio.h
 *
 *  Created on: Sep 26, 2020
 *      Author: keith
 */

#ifndef FILEIO_H_
#define FILEIO_H_
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../includes/constants.h"
/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*
  returns True - file opened successfully
          False - file not opened*/
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode = std::ios_base::in);

/*iff myfile is open then close it*/
void closeFile(std::fstream& myfile);

/* serializes all content in entries to file outputfilename
 * check out utils for helpful type conversion functions
 * BTW serialize means the process of translating a data structure
 * into a format that can be stored in a file
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in the vector entries
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writetoFile(std::vector<constants::entry>  &entries, const std::string &outputfilename);


#endif /* FILEIO_H_ */
