#include "qsort.h"
#include <fstream>
#include <map>

struct Score{
	string name;
	int score;
};

bool genMap (int, Student*, int*, Score*);
void toFile (int, Score*);

int main (int argc, char *argv[]){

	if (argc!=2){
		cout << "Enter more arguments." << endl;
		return 0;
	}

	ifstream ifile (argv[1]);

	if (ifile.fail()){ 	
    	cout << "Could not open file.\n";
		return 0;
	}

	int numStds;
	ifile >> numStds;

	Student students[numStds];
	int grades[numStds];
  	
	for (int i=0; i<numStds; i++){
		ifile >> students[i].name;
		ifile >> students[i].ability;
	}

	StdComp comp1;
	qsort (students, 0, numStds-1, comp1);
	
	for (int i=0; i<numStds; i++){
		ifile >> grades[i];
	}

	IntComp comp2;
	qsort (grades, 0, numStds-1, comp2);

	Score scores[numStds];
	bool success = genMap (numStds, students, grades, scores);

	if (!success){
		cout << "Impossible scoring." << endl;
		return 0;
	}
	else{
		toFile(numStds, scores);
	}
			
	return 0;
}


bool genMap (int numStds, Student *students, int *grades, Score *scores)
{
	for (int i=0; i<numStds; i++){
		if (students[i].ability < grades[i]){
			scores[i].name = students[i].name;
			scores[i].score = grades[i];
		}
		else
			return false;
	}
	return true;	
}

void toFile (int numStds, Score* scores){
	ofstream ofile ("output.txt");

	for (int i=0; i<numStds; i++){
		ofile << scores[i].name << " ";
		ofile << scores[i].score << endl;
	}		
}







