#include <iostream>
#include <string>


using namespace std;

//function implementation

void displayMenu() {
	//displays options to user
	cout << endl;
	cout << "Text File Number Reader" << endl;
	cout << "-------------------------" << endl;
	cout << "1. Check a Number" << endl;
	cout << "2. Modify a Number" << endl;
	cout << "3. Add a Number" << endl;
	cout << "4. Delete a Number" << endl;
	cout << "5. Quit" << endl;
}

int userMenuOption() {
	//processes a number input from user
	int userChoice;
	cout << endl;
	do {
		cout << "Enter a number option: ";
		cin >> userChoice;
		if (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4 && userChoice != 5) {
			cout << "Please enter a valid number option." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			return userChoice;
		}
	} while (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4 && userChoice != 5);
}

string validFile() {
	//validates that the file input is a text file
	string userChoice;
	string fileType = "txt"; // for comparing the file type input by user
	string subString;
	int index;
	cout << endl;
	do {
		cout << "Enter a text file: ";
		cin >> userChoice;

		index = userChoice.find("."); // finds index of dot
		subString = userChoice.substr(index + 1, userChoice.length()); //after the dot, checks if equal to "txt"

		if (fileType == subString) {
			return userChoice;
		}
		else {
			cout << "Must be a text (txt) file." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear input stream
		}
	} while (fileType != subString);
}