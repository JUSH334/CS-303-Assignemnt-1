#ifndef NUMBER_H_
#define NUMBER_H_

#include <iostream>
#include <fstream>

using namespace std;

class Numbers
{
private:
	//Variables
	static const int SIZE = 200; //constant size 
	int new_size = 100; // acts as a counter for the index of function addNumber()
	int array[SIZE]; //array initilized as constant 200 in size
	string fileName; //holds file name used
	
public:

	//Default Constructor
	Numbers();

	//Constructor
	Numbers(string fileName) {
		this->fileName = fileName;
	}

	//Displays options to user
	void printMenu();

	//Read in TXT file Member Function Declarations
	int readFile();
	void printData();

	//Number Member Function Declarations
	void checkNumber();
	void modifyNumber();
	void addNumber();
	void replaceNumber();

};

#endif 
