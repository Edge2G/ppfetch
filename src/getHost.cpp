#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string getHost()
{
	ifstream file("/etc/hostname");
	if (!file) 
	{
		cerr << "Error reading input file!";
		return "";
	}

	string hostName;

	getline(file, hostName);

	return hostName;
}