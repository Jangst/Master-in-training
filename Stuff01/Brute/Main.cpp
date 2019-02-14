// Brute.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "encrypt.h" 
#include <iostream>
#include <string>
#include <array>
#include <map>
#include <iterator>
#include <vector>
#include <sstream>
#include <exception>
#include <fstream>

encrypt EN;
void encryptStr();
void intro();

int main()
{
		intro();
		encryptStr();
}

void intro() {

	std::cout << " Welcome to the character relocation surgeon " << std::endl;
	std::cout << " Where we replace your P with a V  " << std::endl;
	std::cout << " Making you that phrase you've always wanted to be" << std::endl;
	std::cout << " Some fine print before we begin. We use only quality strings, no numbers " << std::endl;
	std::cout << " Our surgeon lacks the experience to deal with those extra digits. " << std::endl;
	std::cout << " If you wish to quit input '0' " << std::endl << std::endl; 

}

void encryptStr() {

	int inputCommand = 2;
	std::string inputPhrase;

	do {
		try {
			std::cout << " Input 1 to encrypt, 2 to encrypt, and 0 to end. " << std::endl;;
			std::cin >> inputCommand;
			if (inputCommand != 1 || 0) {		//exception verifying input
				throw 1;
			}
		}
		catch (...) {
			std::cout << " Exception occured. Use proper input "  << std::endl;
		}
		if (inputCommand == 1) {
			
			std::cout << " Please insert the phrase you'd like start with " << std::endl;
			std::cin >> inputPhrase;
			EN.getValidInput(inputPhrase);
			if (EN.getValidInput(inputPhrase) == true) {		//checking input is valid string

				std::cout << " You have input " << EN.getinput(inputPhrase) << std::endl;
				EN.getEncryptOutput();			//creating encryption and output to file
			}
			else {
				std::cout << " Input proper guess " << std::endl;

			}
		}
		else if (inputCommand == 2) {
			std::cout << " Input the file location you wish to upload. " << std::endl;
			std::string inputFile;
			std::cin >> inputFile;
			std::ifstream inFile;
			inFile.open(inputFile);				//Input encrpyted phrase from file
			if (inFile.is_open()) {
				try {
					std::string line;
					std::getline(inFile, line);
					EN.getValidInput(line);
					if (EN.getValidInput(line) != true) {	//exception for checking phrase validity
						throw 1;
					}
				}
				catch (...) {
					std::cout << " Exception thrown. Error with file has occured." << std::endl;
				}
			}
			else {
				std::cout << " Error with file upload. Check file location! " << std::endl;

			}
			inFile.close();
		}
		system("pause");
		system("CLS");				//reset screen for continuous use
	} while (inputCommand != 0);
	
	std::cout << " Have a nice day :D " << std::endl;	//ending on a happpy note
}





	











// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
