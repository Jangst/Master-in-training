#include "pch.h"
#include "encrypt.h"
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <sstream>


std::string encrypt::getinput(std::string inputPhrase)
{
	 input = inputPhrase;
	 
	return input;
}

std::string encrypt::getOutput()
{
	std::map<char, char> key;
	key['a'] = 'v';
	key['b'] = 'a';
	key['c'] = 'i';
	key['d'] = 'e';
	key['e'] = 'j';
	key['f'] = 'p';
	key['g'] = 'h';
	key['h'] = 'd';
	key['i'] = 'f';
	key['j'] = 'y';
	key['k'] = 'z';
	key['l'] = 'm';
	key['m'] = 't';
	key['n'] = 'g';
	key['o'] = 'o';
	key['p'] = 'q';
	key['q'] = 's';
	key['r'] = 'x';
	key['s'] = 'n';
	key['t'] = 'u';
	key['u'] = 'b';
	key['v'] = 'r';
	key['w'] = 'w';
	key['x'] = 'k';
	key['y'] = 'l';
	key['z'] = 'c';

	
		

		std::vector<char> charKey(input.size());
		for (int i = 0; i < input.size(); i++) {
			charKey[i] = tolower(input[i]);

		}
		
		for (std::vector<char>::iterator i = charKey.begin(); i < charKey.end(); i++) {

					std::cout << *i << " = ";
					*i = key[*i];
					std::cout << *i << std::endl;

		}
		
			
		std::string newArray(charKey.begin(), charKey.end());
		output = newArray;
	
		std::cout << " Your newly encrypted phrase is = " << output << std::endl;
			return output;
	
}


