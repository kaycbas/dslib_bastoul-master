#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <fstream>

using namespace std;

struct Pair {
	string name1;
	string name2;
};

int main (int argc, char *argv[]) {

	if (argc != 2) {
		cout << "Error: enter two command line arguments." << endl;
		return 0;
	}

	ifstream ifile (argv[1]);
	if (ifile.fail()) {
		cout << "Could not open file." << endl;
		return 0;
	}

	int numStds;
	ifile >> numStds;
	
	unordered_map<double, string> stds;
	unordered_set<double> std_skills;
	string temp_name;
	double temp_skill;
	for (int i=0; i<numStds; ++i) {
		ifile >> temp_name;
		ifile >> temp_skill;
		std_skills.insert(temp_skill);
		stds[temp_skill]=temp_name;
	}

	double sum = 0;
	std::unordered_set<double>:: iterator it;
	for (it=std_skills.begin(); it!=std_skills.end(); ++it) {
		sum += *it;
	}
	double team_skill = sum/(numStds/2);
	
	double match;
	std::unordered_set<double>:: iterator it2;
	bool fail = false;
	for (it=std_skills.begin(); it!=std_skills.end() && !fail; ++it) { 
		match = team_skill - *it;
		it2 = std_skills.find(match);
		if (it2==std_skills.end()) {
			cout << "Impossible pairings." << endl;
			fail = true;
		}
		else 
			cout << stds[*it] << " " << stds[*it2] << endl;
	}

	return 0;
}
