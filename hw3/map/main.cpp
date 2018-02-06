#include <iostream>
#include <string>
#include <fstream>
#include "map.h"

using namespace std;

Map<string, string> contacts;
void read_file (char* filename);

int main (int argc, char *argv[])
{
	read_file (argv[1]);
	string input;
	bool done=false;

	while(!done)
	{
		cin >> input;
		
		if(input==".")
		{
			cout << "Goodbye.\n";
			return 0;
		}
		else
		{
			string name = contacts.get(input);
			if (name!="0")
				cout << name << endl;
		}
	}

	return 0;
}


void read_file (char* filename)
{
	string key, fname, lname, name;
	ifstream ifile (filename);

	if (ifile.fail()) 						
	{
    cout << "Could not open file.\n";
  }

	while (true)
	{
		ifile >> key;
		ifile >> fname;
		ifile >> lname;
		name = fname + " " + lname;
		contacts.add(key, name);
		if (ifile.eof())
			break;
	}
}






