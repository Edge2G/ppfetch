#include <iostream>

#include "getUser.hpp"
#include "getHost.hpp"
#include "getOS.hpp"
#include "getManufacturer.hpp"
#include "getKernel.hpp"
#include "getUptime.hpp"
#include "getCPU.hpp"

using namespace std;

/*
 * List of data from neofetch
 * --------------------------
 *
 *  - username and host			done
 *  - operating system			done
 *  - manufacturer name			done
 *  - kernel version			done
 *  - uptime					done
 *  - installed packages		tbd
 *  - shell						tbd
 *  - resolution				tbd
 *  - window manager			tbd
 *  - window manager theme		tbd
 *  - theme						tbd
 *  - icon theme				tbd
 *  - terminal					tbd
 *  - terminal font				
 *  - cpu						done	
 *  - gpu						tbd
 *  - memory usage				
 *  - colors?
 *
 */

int main(int argc, char *argv[])
{
	string userName = getUser();
	string hostName = getHost();
	string osName	= getOS();
	string manufacturer = getManufacturer();
	string kernelName = getKernel();
	string uptime = getUptime();
	string cpuName = getCPU();

	cout << userName << endl;
	cout << hostName << endl;
	cout << osName << endl;
	cout << manufacturer << endl;
	cout << kernelName << endl;
	cout << uptime << endl;
	cout << cpuName << endl;

	return 0;
}
