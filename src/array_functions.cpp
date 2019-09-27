/*
 * functionstocomplete.cpp
 *
 *  Updated on on: Sep 24th, 2019
 *      Author: Steven
 */

//============================================================================
//	TODO add necessary includes here
#include "array_functions.h"
#include <string>
//============================================================================

//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur

//TODO add a global array of entry structs (global to this file)

//TODO add variable to keep track of next available slot in array

//TODO define all functions in header file
void clearArray() {

}

int getArraySize(){
	return -1;
}

std::string getArrayWordAt(int i){
	return "TODO";
}

int getArrayWord_NumbOccur_At(int i){
	return -1;
}

bool processFile(std::fstream &myfstream){
	return false;
}

void processLine(std::string &myString){
	return;
}

void processToken(std::string &token){
	return;
}

bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode = std::ios_base::in) {
	return false;
}

void closeFile(std::fstream& myfile){
	return;
}

int writeArraytoFile(const std::string &outputfilename){
	return -1;
}

void sortArray(constants::sortOrder so){
	return;
}


//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!
