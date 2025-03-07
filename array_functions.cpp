/*
 * functionstocomplete.cpp
 *
 *  Updated on on: Sep 28th, 2019
 *      Author: Steven
 */

//============================================================================

#include "array_functions.h"
#include "constants.h"
#include "utilities.h"

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

//============================================================================

//============================================================================
//	stuff you will need
const int EMPTY_ARRAY_SIZE = 0;
const int FIRST_TIME_SEEN = 1;
const int NO_OCCURANCES = -1;

//============================================================================
struct entry {
	std::string word;
	int num_occurances;
};

entry myEntryArray[constants::MAX_WORDS];

int array_size = EMPTY_ARRAY_SIZE;
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
	std::string word_at_i = " ";
	if (i < array_size) {
		word_at_i = myEntryArray[i].word;
	}
	return word_at_i;
}

//get data at a particular location
int getArrayWord_NumbOccur_At(int i){
	int num_of_occ = NO_OCCURANCES;
	if (i < array_size) {
		num_of_occ = myEntryArray[i].num_occurances;
	}
	return num_of_occ;
}

/*Keep track of how many times each token seen*/
void processToken(std::string &token){
	if (strip_unwanted_chars(token)) {
		for (int i = 0; i < array_size; i++) {
			std::string temp1 = token;
			std::string temp2 = myEntryArray[i].word;
			toUpper(temp1);
			toUpper(temp2);
			if (temp1 == temp2) {
				myEntryArray[i].num_occurances++;
				return;
			}
		}
	entry new_entry;
	new_entry.word = token;
	new_entry.num_occurances = FIRST_TIME_SEEN;
	myEntryArray[array_size] = new_entry;
	array_size++;
	}
}

/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(std::string &myString){
	std::stringstream ss(myString);
	std::string temp_token;
	
	while (getline(ss, temp_token, constants::CHAR_TO_SEARCH_FOR)) {
		processToken(temp_token);
	}
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream){
	if (!myfstream.is_open()) {
		return false;
	} else {
		std::string line;
		while (!myfstream.eof()) {
			getline(myfstream, line);
			processLine(line);
		}
	return true;
	}
}

/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream &myfile, const std::string &myFileName, 
		std::ios_base::openmode mode) {
	myfile.open(myFileName.c_str(), mode);
	return myfile.is_open();
}

/*iff myfile is open then close it*/
void closeFile(std::fstream &myfile){
	if (myfile.is_open()) {
		myfile.close();
	}
	return;
}

/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const std::string &outputfilename){
	if (array_size == EMPTY_ARRAY_SIZE) {
		return constants::FAIL_NO_ARRAY_DATA;
	}

	std::ofstream myOutputFile;
	myOutputFile.open(outputfilename.c_str());

	if (!myOutputFile.is_open()) {
		return constants::FAIL_FILE_DID_NOT_OPEN;
	}
	
	for ( int i = 0; i < array_size; i++) {
		myOutputFile << myEntryArray[i].word << " " << myEntryArray[i].num_occurances << std::endl;
	}
	myOutputFile.close();
	return constants::SUCCESS;
}

/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so){
	int i;
	int j;
	entry temp_entry;

	switch (so) {

		case constants::sortOrder::ASCENDING:
			for (i = 1; i < array_size; i++) {
				for (j = i; j > 0; j--) {
					std::string temp1 = myEntryArray[j].word;
					std::string temp2 = myEntryArray[j - 1].word;
					toUpper(temp1);
					toUpper(temp2);
					if(temp1 < temp2) {
						temp_entry = myEntryArray[j];
						myEntryArray[j] = myEntryArray[j - 1];
						myEntryArray[j-1] = temp_entry;
					}
				}
			}
			break;

		case constants::sortOrder::DESCENDING:
			for (i = 1; i < array_size; i++) {
				for (j = i; j > 0; j--) {
					std::string temp1 = myEntryArray[j].word;
					std::string temp2 = myEntryArray[j - 1].word;
					toUpper(temp1);
					toUpper(temp2);
					if(temp1 > temp2) {
						temp_entry = myEntryArray[j];
						myEntryArray[j] = myEntryArray[j - 1];
						myEntryArray[j-1] = temp_entry;
					}
				}
			}
			break;

		case constants::sortOrder::NUMBER_OCCURRENCES:
			for (i = 1; i < array_size; i++) {
				for (j = i; j > 0; j--) {
					if(myEntryArray[j].num_occurances < myEntryArray[j - 1].num_occurances) {
						temp_entry = myEntryArray[j];
						myEntryArray[j] = myEntryArray[j - 1];
						myEntryArray[j-1] = temp_entry;
					}
				}
			}
			break;

		case constants::sortOrder::NONE:
		default:
			break;
	}
	return;
}
//===========================================================================

//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!
