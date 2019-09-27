/*
 * functionstocomplete.cpp
 *
 *  Updated on on: Sep 24th, 2019
 *      Author: Steven
 */

//============================================================================
//	TODO add necessary includes here
#include "array_functions.h"
#include "constants.h"
#include "utilities.h"
#include <string>
//============================================================================

//============================================================================
//	stuff you will need
const int EMPTY_ARRAY_SIZE = 0;
const int FIRST_TIME = 1;
//============================================================================
//TODO define a structure to track words and number of times they occur
struct entry {
	st::string word;
	int num_occurances;
};

//TODO add a global array of entry structs (global to this file)

entry words_array[constants::MAX_WORDS];

//TODO add variable to keep track of next available slot in array

int array_size = EMPTY_ARRAY_SIZE;

//TODO define all functions in header file
//============================================================================
//zero out array that tracks words and their occurrences
void clearArray() {
	array_size = EMPTY_ARRAY_SIZE;
}
//how many unique words are in array
int getArraySize(){
	return array_size;
}
//get data at a particular location
std::string getArrayWordAt(int i){
	if (i <= array_size) {
		return words_array[i].word;
	}
	return constants::FAIL_NO_ARRAY_DATA;
}
//
int getArrayWord_NumbOccur_At(int i){
	if (i <= array_size) {
		return words_array[i].num_occurances;
	}
	return constants::FAIL_NO_ARRAY_DATA;
}
/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream){
	return false;
}
/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(std::string &myString){
	return;
}
/*Keep track of how many times each token seen*/
void processToken(std::string &token){
	return;
}
/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream &myfile, const std::string &myFileName, 
		std::ios_base::openmode mode) {
	myFile.open(myFileName.c.str(), mode);
	return myFile.is_open();
}
/*iff myfile is open then close it*/
void closeFile(std::fstream &myfile){
	if (myFile.is_open()) { 
		myFile.close();
	}
}
/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const std::string &outputfilename){
	return -1;
}
/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so){
	return;
}
//===========================================================================

//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!
