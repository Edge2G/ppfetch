#include <iostream> 
#include <string>
#include <fstream>
#include <unistd.h>

using namespace std;

string getUser()
{
	/*
	*	Get the current UID and read the /etc/passwd file
	*	Read each line and get the username that matches
	*	the UID
	*	
	*	Each line has the following structure:
	*
	* 	username:passwd(encrypted):uid:gid:homedir:shell
	*/

	ifstream file("/etc/passwd");
	if (!file) 
	{
		cerr << "Error reading input file!";
		return "";
	}

	int userID = getuid();
	string userName, uidString, line;
	u_int32_t colonCount;

	while (getline(file, line))
	{
		colonCount = 0;
		userName = "";
		uidString = "";

		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == ':')
			{
				colonCount ++;
				continue;
			} 

			switch (colonCount)
			{
			case 0:
				userName.push_back(line[i]);
				continue;
			case 1:
				continue;
			case 2:
				uidString.push_back(line[i]);
				continue;
			case 3:
				break;
			}
		}

		if (userID == stoi(uidString)) break;
	}

	return userName;
}