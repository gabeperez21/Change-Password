// In this program, user will have to replace his old password with a new one. There is a minimum
// amount of upper case letters, lower case letters, digits, and special characters necessary to be 
// an acceptable password. New password has to also be unique. Passwords will be saved to a .dat file
// so that it can not be re-used.
// Fall 2021 Capstone Project
// Programmer: Gabriel Perez

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printBanner(int minLength = 9, ostream& os = cout); // DONE  
void printInstructions(int minLength = 9, int minUpperChar = 2, int minLowerChar = 2, int minDigit = 2,
	int minSpecialChar = 2, ostream& os = cout);    
bool myIsDigit(char inputChar);   // DONE   
bool myIsUpper(char inputChar);   // DONE
bool myIsLower(char inputChar);   // DONE
bool myIsSpecialChar(char inputChar);   // DONE
bool isValidPasswordLength(string password, int minLength = 9);    // DONE
int digitCount(string password);  // DONE
int upperCount(string password);  // DONE
int lowerCount(string password);  // DONE
int specialCharCount(string password);  // DONE
bool hasEnoughDigits(string password, int minDigit = 2);  // DONE
bool hasEnoughLowerChar(string password, int minLowerChar = 2);   // DONE
bool hasEnoughUpperChar(string password,int minUpperChar = 2);  // DONE
bool hasEnoughSpecialChar(string password, int minSpecialChar = 2);  // DONE
string getValidPassword(int minLength = 9, int minUpperChar = 2, int minLowerChar = 2, int minDigit = 2,
	int minSpecialChar = 2);   // DONE
bool isValidNewPassword(string password);
void writeToFile(string password);

// DONE DONE
int main() {
	system("Color 1F");
	system("Title Password Change Capstone  --  by Gabriel Perez");
	
	string password;
	printBanner();

	while (true) {
		printInstructions();

		cout << "\nPlease enter your new password: ";
		password = getValidPassword();

		cout << "\n\n\n***   new password ACCEPTED!!!! *********";

		writeToFile(password);
		cout << "\n\n\"" << password << "\" is now in the list of already used passwords.";

	}
	return 0;
}

// DONE  DONE
void printBanner(int minLength, ostream& os)
{   
	os << "\n"
		<< "\t\t                  Capstone Project                         \n"
		<< "\t\t           Valid Password Change Program                   \n"
		<< "\t\t             Password should be unique                     \n"
		<< "\t\t             at least " << minLength << " characters long                    \n"
		<< "\t\t   and contain at least a specific number of upper case,   \n"
		<< "\t\t  lower case letters as well digits and special characters \n"
		<< "\t\t                  by Gabriel Perez                         \n\n";
}

// DONE DONE
void printInstructions(int minLength, int minUpperChar, int minLowerChar, int minDigit,
	int minSpecialChar, ostream& os) {  
	os << "\n\n"
		<< "Your password has expired. You need to select a new password.\n"
		<< "    Make sure your new password fulfills the following requirements:\n"
		<< "       * is at least " << minLength << " characters long\n"
		<< "       * contains at least " << minUpperChar << " upper case characters\n"
		<< "       * contains at least " << minLowerChar << " lower case characters\n"
		<< "       * contains at least " << minDigit << " digits\n"
		<< "       * contains at least " << minSpecialChar << " special characters\n"
		<< "       * passwords are case sensitive\n"
		<< "       * passwords may contain white space other than new line\n"
		<< "         at the end and middle only\n"
		<< "       * has not been used before\n";
}

// DONE DONE
bool isValidPasswordLength(string passwordChar, int minLength) {   
	return passwordChar.length() >= minLength;
}

// DONE  DONE
bool myIsDigit(char inputChar){   
	// return (inputChar >= '0' && inputChar <= '9' ? true : false);
	return inputChar >= '0' && inputChar <= '9';
}

// DONE  DONE
bool myIsUpper(char inputChar) {
	return inputChar >= 'A' && inputChar <= 'Z';
}

// DONE  DONE
bool myIsLower(char inputChar){
	return inputChar >= 'a' && inputChar <= 'z';
}

// DONE  DONE
bool myIsSpecialChar(char inputChar) {
	return !myIsDigit(inputChar) && !myIsUpper(inputChar) && !myIsLower(inputChar);
}

// DONE DONE
int digitCount(string password) {
	int digitCount = 0;

	for (int index = 0; index < password.length(); index++) {
		if (myIsDigit(password[index]))
			digitCount++;
	}
	return digitCount;
}

// DONE DONE
int upperCount(string password) {
	int upperCount = 0;

	for (int index = 0; index < password.length(); index++) {
		if (myIsUpper(password[index]))
			upperCount++;
	}
	return upperCount;
}

// DONE DONE
int lowerCount(string password) {
	int lowerCount = 0;

	for (int index = 0; index < password.length(); index++) {
		if (myIsLower(password[index]))
			lowerCount++;
	}
	return lowerCount;
}

// DONE DONE
int specialCharCount(string password) {
	int specialCount = 0;

	for (int index = 0; index < password.length(); index++) {
		if (myIsSpecialChar(password[index]))
			specialCount++;
	}
	return specialCount;
}

// DONE  DONE
bool hasEnoughDigits(string password, int minDigit) {
	return digitCount(password) >= minDigit;
}

// DONE DONE
bool hasEnoughUpperChar(string password, int minUpperChar) {
	return upperCount(password) >= minUpperChar;
}

// DONE DONE
bool hasEnoughLowerChar(string password, int minLowerChar) {
	return lowerCount(password) >= minLowerChar;
}

// DONE DONE
bool hasEnoughSpecialChar(string password, int minSpecialChar) {
	return specialCharCount(password) >= minSpecialChar;
}

// DONE DONE
string getValidPassword(int minLength, int minUpperChar, int minLowerChar, int minDigit,
	int minSpecialChar) {   
	string password;

	cin >> ws;
	getline(cin, password);
	
	while (!isValidPasswordLength(password, minLength) || !hasEnoughDigits(password,minDigit) ||
		!hasEnoughUpperChar(password, minUpperChar) ||!hasEnoughLowerChar(password, minLowerChar) ||
		!hasEnoughSpecialChar(password, minSpecialChar) || !isValidNewPassword(password))
	{
		system("Color 5F");

		if (!isValidNewPassword(password))
			cout << "\a\n  Password is invalid because it has been used before";
		else {
			cout << "\a\nPassword is invalid because it does NOT have enough: "
				<< (!isValidPasswordLength(password) ? "\n\tlength" : "")
				<< (!hasEnoughDigits(password) ? "\n\tdigits" : "")
				<< (!hasEnoughUpperChar(password) ? "\n\tupper case letters" : "")
				<< (!hasEnoughLowerChar(password) ? "\n\tlower case letters" : "")
				<< (!hasEnoughSpecialChar(password) ? "\n\tspecial characters" : "");	
		}

		cout << "\n\n   ***  Please choose a new password: ";
		cin >> ws;
		getline(cin, password);
	}

	system("Color 1F");
	return password;
}

// DONE DONE
bool isValidNewPassword(string password) {
	string usedPasswords;
	ifstream myFile("Already Used Passwords.dat");

	if (myFile.fail()) {
		myFile.close();
		system("Color 5F");
		cout << ("\n   Password is INVALID because");
		cout << "\a\n\nFailed to open \"Already Used Passwords.dat\"."
			<< "\n   Program will exit now with code -1."
			<< "\n   Please hit ENTER to close the window.";
		cin.get(); 
		exit(-1);
	}

	while (myFile >> usedPasswords) {
		if (password == usedPasswords) {
			myFile.close();
			return false;
		}
	}

	myFile.close();
	return true;
}

// DONE DONE
void writeToFile(string password) {
	ofstream myFile("Already Used Passwords.dat", ios::app);
	// check if it opened correctly

	if (myFile.fail()) {
		myFile.close();
		system("Color 5F");
		cout << "\a\n\nFailed to open \"Already Used Passwords.dat\"."
			<< "\n   Program will exit now with code -2."
			<< "\n   Please hit ENTER to close the window.";
		cin.get();
		exit(-2);
	}

	if (isValidNewPassword(password)) 
		myFile << password << endl;
	
	myFile.close();
}
