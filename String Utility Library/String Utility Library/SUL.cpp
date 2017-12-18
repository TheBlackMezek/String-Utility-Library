#include "SUL.h"


#include <iostream>



const size_t sul::alphabetLength = 26;

const char sul::lowerc[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
							   'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

const char sul::upperc[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'K', 'L', 'M',
                               'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };









void sul::toUpperCase(std::string& s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		for (int n = 0; n < alphabetLength; ++n)
		{
			if (s[i] == lowerc[n])
			{
				s[i] = upperc[n];
				break;
			}
		}
	}
}

void sul::toLowerCase(std::string& s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		for (int n = 0; n < alphabetLength; ++n)
		{
			if (s[i] == upperc[n])
			{
				s[i] = lowerc[n];
				break;
			}
		}
	}
}











void sul::test::helloWorld()
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

void sul::test::caseChanges()
{
	std::string base = "Example String.";
	std::string ubase(base);
	std::string lbase(base);
	toUpperCase(ubase);
	toLowerCase(lbase);

	std::cout << "Base string:" << base << std::endl;
	std::cout << "toUpperCase(base):" << ubase << std::endl;
	std::cout << "toLowerCase(base):" << lbase << std::endl;

	std::cin.get();
}

