#include "SUL.h"


#include <iostream>



const size_t sul::alphabetLength = 26;

const char sul::lowerc[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
							   'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

const char sul::upperc[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'K', 'L', 'M',
                               'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };




void sul::test::testPrint()
{
	std::cout << "Hello world!" << std::endl;

	std::cin.get();
}

void sul::test::printAlphabet()
{
	for (int i = 0; i < sul::alphabetLength; ++i)
	{
		std::cout << sul::lowerc[i] << ' ' << sul::upperc[i] << std::endl;
	}

	std::cin.get();
}

