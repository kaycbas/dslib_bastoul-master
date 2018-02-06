#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int numLines;
	int i;
	int k;
	string line;
	string container;
	int *words;
	

	if (argc<2)						//makes sure user enter enough command line arguments
	{
		cout << "Please enter more arguments.\n";
		return 0;
	}

	ifstream ifile (argv[1]);			//opens file in ifstream

	if (ifile.fail()) 						//checks success
	{
    cout << "Could not open file.\n";
    return 0;
  }

	ifile >> numLines;						//reads in first nymber (number of lines)
	words = new int [numLines];		//dynamically allocates 'words' array with num lines
	ifile.seekg (2, ios::cur);		//moves reader spot to start of next line
	
	for (i=0; i<numLines; i++)		//loop reads in each line
	{
		getline (ifile, line);
		stringstream ss (line);		//puts string 'line' in a stringstream
	
		k=0;

		while (ss)		//loop reads each word until end of line
		{
			ss >> container;	//arbitrary container
			k++;			//counts number of words
		}

		words[i]=k-1;		//stores number of words in an array
	}
	
	for (i=numLines-1; i>=0; i--){		//outputs number of words in each line 
		cout << words[i] << endl;
	}

	return 0;
}





