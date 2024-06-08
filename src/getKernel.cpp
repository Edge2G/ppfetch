#include <string>
#include <fstream>

using namespace std;

string getKernel()
{
	ifstream file("/proc/version");
	int spaceCount = 0;
	string kernelName, line;
	getline(file, line);

	for (int i = 0; i < sizeof(line); i++)
	{
		if (spaceCount == 3)
		{
			break;
		}

		if (line[i] == ' ')
		{
			spaceCount++;
			continue;
		}

		if (spaceCount == 2)
		{
			kernelName.push_back(line[i]);
		}
	}

	return kernelName;
}