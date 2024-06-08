#include <string>
#include <fstream>

using namespace std;

string getUptime()
{
	ifstream file("/proc/uptime");
	string uptime, line;
	getline(file, line);

	for (int i = 0; i < sizeof(line); i++)
	{
		if (line[i] == ' ')
		{
			break;
		}

		uptime.push_back(line[i]);
	}

	int uptimeSeconds = stoi(uptime);
	int minutesUp = uptimeSeconds/60;
	int secondsUp = uptimeSeconds%60;

	uptime = "";
	uptime = to_string(minutesUp) + " min " + to_string(secondsUp) + " sec";
	return uptime;
}