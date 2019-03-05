#pragma once
#include <iostream>


class encrypt {

public:
	std::string getinput(std::string inputPhrase);
	std::string getEncryptOutput();
	bool getValidInput(std::string inputPhrase);
	std::string getEncryptInput(std::string line);
private:
	std::string input;
	std::string output;
	bool validInput;
};