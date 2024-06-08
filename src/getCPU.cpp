#include <string>
#include <fstream>

using namespace std;

string getCPU()
{
	ifstream file("/proc/cpuinfo");
	bool nameFound = false;
	string line, modelName;

	while(!file.eof())
	{
		getline(file, line);
		if (line.substr(0, 10) == "model name")
		{
			break;
		}
	}

	modelName = line.substr(13, line.size()-1);
	return modelName;
}