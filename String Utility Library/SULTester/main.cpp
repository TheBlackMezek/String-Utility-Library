
#include <iostream>
#include <vector>
#include <fstream>

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

void saveLocs();
void loadLocs();




std::vector<Location> locs;


int main()
{
	//size_t loc = 0;
	Location* loc;


	//Location baseloc;
	//baseloc.name = "start";
	//baseloc.desc = "A brightly lit white room with soothing electronic music.";
	//locs.push_back(baseloc);
	//loc = &locs[0];

	loadLocs();
	loc = &locs[0];


	std::string line;

	while (line != "exit")
	{
		std::getline(std::cin, line);
		std::cout << std::endl;

		//Print description
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

	saveLocs();

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

void saveLocs()
{
	std::ofstream file;
	file.open("WorldSave.txt");

	for (int i = 0; i < locs.size(); ++i)
	{
		file << locs[i].name << std::endl;
		file << locs[i].desc << std::endl;
		for (int n = 0; n < locs[i].connections.size(); ++n)
		{
			file << locs[i].connections[n].command << std::endl;
			file << locs[i].connections[n].destination->name << std::endl;
		}
		file << "CONNECTIONS_END" << std::endl;
	}

	file.close();
}

void loadLocs()
{
	std::ifstream file;
	file.open("WorldSave.txt");

	//load all locations and connections from file
	std::string line;
	while (std::getline(file, line))
	{
		Location l;
		l.name = line;

		std::getline(file, line);
		l.desc = line;

		std::getline(file, line);
		while (line != "CONNECTIONS_END")
		{
			LocationConnection c;
			c.command = line;

			std::getline(file, line);
			c.command = c.command + ' ' + line;

			l.connections.push_back(c);

			std::getline(file, line);
		}

		locs.push_back(l);
	}

	file.close();



	//set all connection destinations
	for (int i = 0; i < locs.size(); ++i)
	{
		for (int n = 0; n < locs[i].connections.size(); ++n)
		{
			std::string& command = locs[i].connections[n].command;
			std::string conname = sul::getWord(command, 1);

			for (int q = 0; q < locs.size(); ++q)
			{
				if (locs[q].name == conname)
				{
					command.erase(command.find(' '), command.npos);
					locs[i].connections[n].destination = &locs[q];
					break;
				}
			}

		}
	}

}
