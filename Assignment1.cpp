#include "Numbers.h"
#include "Functions.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int userChoice;
	bool run = true;
	bool valid = true;
	string userFile;

	while (valid == true) {
		userFile = validFile();
		Numbers Num(userFile);
		if (Num.readFile() == 0) {
			continue;
		}
		else {
			valid = false;
		}
	}

	Numbers Num(userFile);
	cout << "File opened successful!" << endl;
	Num.readFile();

	//switch case for whatever valid number user chooses
	while (run == true) {
		displayMenu();
		userChoice = userMenuOption();

		switch (userChoice) {
		case 1:
			Num.checkNumber();
			Num.printData();
			break;
		case 2:
			Num.modifyNumber();
			Num.printData();
			break;
		case 3:
			Num.addNumber();
			Num.printData();
			break;
		case 4:
			Num.replaceNumber();
			Num.printData();
			break;
		case 5:
			cout << endl;
			cout << "Thank you for using Text File Number Reader!" << endl;
			cout << "Quitting program..." << endl;
			run = false;
			break;
		default:
			cout << "An unexpected error occured. Please restart program and try again.";
		}
	}

	return 0;
}