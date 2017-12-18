
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
	std::string name;
	std::string desc;
	std::vector<LocationConnection> connections;
};





Location* findLoc(std::string name);




std::vector<Location> locs;


int main()
{
	//size_t loc = 0;
	Location* loc;


	Location baseloc;
	baseloc.name = "start";
	baseloc.desc = "A brightly lit white room with soothing electronic music.";
	locs.push_back(baseloc);
	loc = &locs[0];


	std::string line;

	while (line != "exit")
	{
		std::getline(std::cin, line);
		std::cout << std::endl;

		if (line == "look")
		{
			std::cout << loc->desc << std::endl;
		}
		//New description
		else if (sul::getWord(line, 0) == "descnew")
		{
			//line.erase(0, 8);
			sul::eraseWord(line, 0);
			loc->desc = line;
		}
		//Append to description
		else if (sul::getWord(line, 0) == "descapp")
		{
			//line.erase(0, 8);
			sul::eraseWord(line, 0);
			loc->desc = loc->desc + line;
		}
		//List all locations
		else if (line == "locs")
		{
			for (int i = 0; i < locs.size(); ++i)
			{
				std::cout << i << ": " << locs[i].name << std::endl;
			}
		}
		//Create a new location
		else if (sul::getWord(line, 0) == "newloc")
		{
			Location l;
			l.name = sul::getWord(line, 1);
			sul::eraseWord(line, 0);
			sul::eraseWord(line, 0);
			l.desc = line;

			locs.push_back(l);
			loc = &locs[locs.size() - 1];

			std::cout << loc->desc << std::endl;
		}
		//Add a location connection
		else if (sul::getWord(line, 0) == "connect")
		{
			if (findLoc(sul::getWord(line, 1)) != nullptr)
			{
				LocationConnection l;
				l.destination = findLoc(sul::getWord(line, 1));
				sul::eraseWord(line, 0);
				sul::eraseWord(line, 0);
				l.command = line;

				loc->connections.push_back(l);
			}
		}
		//List connections
		else if (line == "cons")
		{
			for (int i = 0; i < loc->connections.size(); ++i)
			{
				std::cout << loc->connections[i].command << ": " << loc->connections[i].destination->name << std::endl;
			}
		}
		//Travel through connection
		else if (sul::getWord(line, 0) == "go")
		{
			sul::eraseWord(line, 0);
			std::string command = line;

			for (int i = 0; i < loc->connections.size(); ++i)
			{
				if (loc->connections[i].command == line)
				{
					loc = loc->connections[i].destination;
					std::cout << loc->desc << std::endl;
					break;
				}
			}

		}

		std::cout << std::endl;
	}

}




Location* findLoc(std::string name)
{
	for (int i = 0; i < locs.size(); ++i)
	{
		if (locs[i].name == name)
		{
			return &locs[i];
		}
	}

	return nullptr;
}
