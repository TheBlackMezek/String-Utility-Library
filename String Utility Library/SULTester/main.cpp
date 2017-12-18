
#include <iostream>
#include <vector>

#include "SUL.h"

struct Location;

struct LocationConnection
{
	Location* destination;
	std::string command;
};

struct Location
{
	std::string desc;
	std::vector<LocationConnection> connections;
};





int main()
{
	std::vector<Location> locs;
	size_t loc = 0;


	Location baseloc;
	baseloc.desc = "A brightly lit white room with soothing electronic music.";
	locs.push_back(baseloc);

	sul::test::testEraseWord();


	std::string line;

	while (line != "exit")
	{
		std::getline(std::cin, line);
		std::cout << std::endl;

		if (line == "look")
		{
			std::cout << locs[loc].desc << std::endl;
		}
		//New description
		else if (sul::getWord(line, 0) == "descnew")
		{
			//line.erase(0, 8);
			sul::eraseWord(line, 0);
			locs[loc].desc = line;
		}
		//Append to description
		else if (sul::getWord(line, 0) == "descapp")
		{
			//line.erase(0, 8);
			sul::eraseWord(line, 0);
			locs[loc].desc = locs[loc].desc + line;
		}

		std::cout << std::endl;
	}

}
