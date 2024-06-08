#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string getOS()
{
	ifstream file("/etc/os-release");
	if (!file)
	{
		cerr << "Error reading input file!";
		exit(1);
	}

	bool foundName = false;
	string osInfo, line;
	getline(file, line);

	for (int i = 0; i < sizeof(line); i++)
	{
		if (line[i] == '"')
		{
			foundName = true;
			continue;
		}

		if (foundName)
		{
			osInfo.push_back(line[i]);
		}
		
	}

	return osInfo;
}