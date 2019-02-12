#pragma once
#include <iostream>


class encrypt {

public:
	std::string getinput(std::string inputPhrase);
	std::string getOutput();
	


private:
	std::string input;
	std::string output;

};