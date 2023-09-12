#include "Numbers.h"
#include <iostream>
#include <fstream>

int Numbers::readFile() {
	//reads a file and assigns it to an array

	ifstream fileOpen;
	fileOpen.open(fileName);

	//Checks if file opened properly
	if (!fileOpen.is_open()) {
		cout << "Could not open " << fileName << endl;
		cout << "Please try again." << endl;
		cout << endl;
		return 0;
	}
	else {
		//Read data and place in array
		for (int i = 0; i < SIZE; i++) {
			if (i < 100) {
				fileOpen >> array[i];
			}
		}
	}
	fileOpen.close();
	return 1;
}

void Numbers::printData() {
	//reads data in it's current state
	//counter that helps structure the data when displayed to user
	int count = 0;
	cout << endl; //whitespace
	for (int i = 0; i < SIZE; i++) {
		if (i >= new_size) { //does not display beyond appended values
			continue;
		}
		else if (count == 9) {
			cout << array[i] << endl;
			count = 0;
		}
		else {
			cout << array[i] << " ";
			count += 1;
		}
	}
	cout << endl;
}

void Numbers::checkNumber() {
	//checks if integer exists in array and returns its index
	int userNum;
	bool num_exist = false; //boolean condition to check if number exists or not
	cout << "Enter a number to check: ";
	cin >> userNum;
	for (int i = 0; i < SIZE; i++) {
		if (userNum == array[i]) {
			cout << "The integer " << userNum << " exists at index " << i << endl;
			num_exist = true;
		}
	}
	if (num_exist == false) {
		cout << "Number does not exist." << endl;
	}
}

void Numbers::modifyNumber() {
	//modifies value of integer via index
	//old number and new number placeholders
	int numIndex;
	int new_num;
	int old_num;
	bool run = true;

	while (run == true) {
		try {
			cout << "Enter an index of an integer to modify: ";
			cin >> numIndex;
			if (numIndex > SIZE || numIndex < 0 || numIndex >= new_size) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears input stream
				throw out_of_range("The index is out of range.");
			}
			else if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears input stream
				throw runtime_error("Input must be a number.");
			}
			int old_num = array[numIndex]; 
			for (int i = 0; i < SIZE; i++) {
				if (numIndex == i) {
					cout << "Enter a new integer for the index: ";
					cin >> new_num;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears input stream
						throw runtime_error("Input must be a number. Try again");
					}
					array[i] = new_num; //assigns new value
					cout << "The new integer at index " << i << " is " << new_num << endl;
					cout << "The old integer at index " << i << " was " << old_num << endl;
					run = false; //breaks loop
					break;
				}
			}
		}
		catch (out_of_range& ex) { //catches indexes that are beyond the initilized array size
			cerr << ex.what() << endl;
			cerr << endl;
		}
		catch (runtime_error& ex) { //if letters are typed
			cerr << ex.what() << endl;
			cerr << endl;
		}
		catch (...) { // catches whatever unexpected error occurs
			cerr << "Error has occured. Try again." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

void Numbers::addNumber() {
	//adds an integer at the end of the array
	int new_num;
	bool run = true;

	while (run == true) {
		try {
			cout << "Enter a new integer to append: ";
			cin >> new_num;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
				throw runtime_error("Input must be a number. Try again");
			}
			if (new_size == 200) { //checks if array is full and if so does not add anymore
				throw out_of_range("The array is full. cannot append more values.");
			}
			array[new_size] = new_num;
			new_size += 1;
			run = false; // breaks loop
		}
		catch (runtime_error& ex) { //if numbers are typed
			cerr << ex.what() << endl;
			cerr << endl;
		}
		catch (out_of_range& ex) { // array is already full
			cerr << ex.what() << endl;
			cerr << endl;
			run = false;
		}
		catch (...) { //catches whatever errors might come up
			cerr << "Error has occured. Try again." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

void Numbers::replaceNumber() {
	int del_num;
	cout << "Enter an index of an integer to delete it: ";
	cin >> del_num;
	if (del_num > new_size) { //if user tries to delete a value not displayed
		cout << "Enter an index with an assigned value. No changes occured." << endl;
	}
	else if (del_num < 0) { //if index less than 0
		cout << "Please enter a valid index. No changes occured." << endl;
	}
	else {
		new_size -= 1; //decrements in order to keep index open for potentially adding a number
		for (int i = del_num; i < SIZE; i++) {
			array[i] = array[i + 1];
		}
	}
}
