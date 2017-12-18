#pragma once

#include <string>


namespace sul
{

	extern const size_t alphabetLength;
	extern const char lowerc[26];
	extern const char upperc[26];


	void toUpperCase(std::string& s);
	void toLowerCase(std::string& s);


	

	namespace test
	{
		void runAllTests();
		void helloWorld();
		void printAlphabet();
		void caseChanges();
	}

}
