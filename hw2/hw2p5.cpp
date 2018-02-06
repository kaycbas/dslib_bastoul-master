#include <iostream>
#include <fstream>
#include <vector>
#define RED 1
#define YELLOW 2
#define GREEN 3
#define BLUE 4

using namespace std;

bool search (int pos, int color);
bool colorCheck (int pos, int color);

char *map;
int *posColor;

int numRows;
int numCols;
int numCntrs;

int main(int argc, char *argv[])
{
	int i;
	int position;
	int color;
	bool outcome;

	vector<char> countries;
	vector<int> cntrColor;


	if (argc<2)						
	{
		cout << "Please enter more arguments.\n";
		return 0;
	}

	ifstream ifile (argv[1]);			

	if (ifile.fail()) 						
	{
    cout << "Could not open file.\n";
    return 0;
  }

	ifile >> numCntrs;
	ifile >> numRows;
	ifile >> numCols;

	map = new char[numRows*numCols];		//dynamic allocation of map and color arrays
	posColor = new int[numRows*numCols];	

	ifile.seekg (2, ios::cur);
	char temp;
	for (i=0; i<(numRows*numCols); i++)  //filling map[] and initializing posColor[]
	{
		map[i] = ifile.get();
		posColor[i] = 0;
		if (i%numCols==numCols-1) {
			ifile.seekg (1, ios::cur);
		}
	}

	position = 0;
	color = RED;

	outcome = search (position, color);

	for (position=0; position<(numRows*numCols); position++) {	//getting countries and their colors
		bool found = false;
		for (i=0; i<countries.size(); i++) {
			if (map[position] == countries[i]) {
				found = true;
			}
		}
		if (found==false) {
			countries.push_back(map[position]);
			cntrColor.push_back(posColor[position]);
		}
	}

	for (i=0; i<countries.size(); i++) {		//printing countries with colors
		cout << countries[i] << " " << cntrColor[i] << endl;
	}	
	

return 0;
}


bool search (int pos, int color) {		//recursive search function
	if (pos>=(numRows*numCols)) {
		return true;
	}
	if (colorCheck(pos, color)) {
		posColor[pos] = color;
		for (color=RED; color<=BLUE; color++) {
			if (search(pos+1, color)) {
				return true;
			}
		}
	}
	return false;
}


bool colorCheck (int pos, int color) {	//checks if valid color placement
	bool validity = true;

	if (pos%numCols != 0) {
		if (map[pos-1] == map[pos]) {
			if (posColor[pos-1] != color) {
				validity = false;
			}
		}
		if (map[pos-1] != map[pos]) {
			if (posColor[pos-1]==color) {		
				validity = false;
			}
		}
	}

	if (pos>=numCols) {
		if (map[pos-numCols] == map[pos]) {
			if (posColor[pos-numCols] != color) {
				validity = false;
			}
		}
		if (map[pos-numCols] != map[pos]) {
			if (posColor[pos-numCols]==color) {		
				validity = false;
			}
		}
	}

	return validity;
}














