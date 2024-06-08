#include <string>
#include <fstream>

using namespace std;

string getManufacturer()
{
	/*
	*	Information can be found in the 
	*	/sys/devices/virtual/dmi/id/ directory
	*/

	ifstream vendorFile("/sys/devices/virtual/dmi/id/sys_vendor");
	string vendor;
	getline(vendorFile, vendor);

	ifstream versionFile("/sys/devices/virtual/dmi/id/product_version");
	string version;
	getline(versionFile, version);

	ifstream nameFile("/sys/devices/virtual/dmi/id/product_name");
	string productName;
	getline(nameFile, productName);

	string manufacturerName = vendor + " " + version + " " + productName;

	return manufacturerName;
}