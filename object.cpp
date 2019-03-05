#include "pch.h"
#include "object.h"
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>


std::string encrypt::getinput(std::string inputPhrase)
{
	input = inputPhrase;
	return input;
}

std::string encrypt::getEncryptOutput()
{
	std::map<char, char> key;
	key['a'] = 'v'; key['b'] = 'a'; key['c'] = 'i'; key['d'] = 'e'; key['e'] = 'j';
	key['f'] = 'p'; key['g'] = 'h'; key['h'] = 'd'; key['i'] = 'f'; key['j'] = 'y';
	key['k'] = 'z'; key['l'] = 'm'; key['m'] = 't'; key['n'] = 'g'; key['o'] = 'o';
	key['p'] = 'q'; key['q'] = 's'; key['r'] = 'x'; key['s'] = 'n'; key['t'] = 'u';
	key['u'] = 'b'; key['v'] = 'r'; key['w'] = 'w'; key['x'] = 'k'; key['y'] = 'l';
	key['z'] = 'c';			//encrypt key

		std::vector<char> charKey(input.size());
		for (int i = 0; i < input.size(); i++) {	//breaking up input into char
			charKey[i] = tolower(input[i]);
		}
		for (std::vector<char>::iterator i = charKey.begin(); i < charKey.end(); i++) {

			std::cout << *i << " = ";
			*i = key[*i];					//converting old string to encrypted
			std::cout << *i << std::endl;
		}
		std::string newArray(charKey.begin(), charKey.end());
		output = newArray;
		std::cout << " Your newly encrypted phrase is = " << output << std::endl;
		std::ofstream oFile;
		oFile.open("txt.txt");
		oFile << output;			//print output to file for later use
		oFile.close();
		return output;
}

bool encrypt::getValidInput(std::string inputPhrase)
{
	input = inputPhrase;
	validInput = false;
	std::map<char, char> key;
	key['a'] = 'v';key['b'] = 'a';key['c'] = 'i';key['d'] = 'e';key['e'] = 'j';
	key['f'] = 'p';key['g'] = 'h';key['h'] = 'd';key['i'] = 'f';key['j'] = 'y';
	key['k'] = 'z';key['l'] = 'm';key['m'] = 't';key['n'] = 'g';key['o'] = 'o';
	key['p'] = 'q';key['q'] = 's';key['r'] = 'x';key['s'] = 'n';key['t'] = 'u';
	key['u'] = 'b';key['v'] = 'r';key['w'] = 'w';key['x'] = 'k';key['y'] = 'l';
	key['z'] = 'c';

	std::vector<char> charKey(input.size());
	for (int i = 0; i < input.size(); i++) {
		charKey[i] = tolower(input[i]);					
	}
	for (std::vector<char>::iterator i = charKey.begin(); i < charKey.end(); i++) {

		for (std::map<char, char>::iterator j = key.begin(); j != key.end(); j++) {

			if (j->first != *i) continue;			//verifying guess
			validInput = true;
		}
		
	}
	return validInput;
}

std::string encrypt::getEncryptInput(std::string line)
{
	std::map<char, char> key;
	key['v'] = 'a'; key['a'] = 'b'; key['i'] = 'c'; key['e'] = 'd'; key['j'] = 'e';
	key['p'] = 'f'; key['h'] = 'g'; key['d'] = 'h'; key['f'] = 'i'; key['y'] = 'j';
	key['z'] = 'k'; key['m'] = 'l'; key['t'] = 'm'; key['g'] = 'n'; key['o'] = 'o';
	key['q'] = 'p'; key['s'] = 'q'; key['x'] = 'r'; key['n'] = 's'; key['u'] = 't';
	key['b'] = 'u'; key['r'] = 'v'; key['w'] = 'w'; key['k'] = 'x'; key['l'] = 'y';
	key['c'] = 'z';

	std::vector<char> charKey(line.size());
	for (int i = 0; i < line.size(); i++) {	//breaking up input file into char array
		charKey[i] = tolower(line[i]);
	}
	for (std::vector<char>::iterator i = charKey.begin(); i < charKey.end(); i++) {

		std::cout << *i << " = ";
		*i = key[*i];					//decrypting file to output
		std::cout << *i << std::endl;
	}
	std::string newArray(charKey.begin(), charKey.end());
	output = newArray;
	std::cout << " Your newly decrypted phrase is = " << output << std::endl;
	return output;
}


