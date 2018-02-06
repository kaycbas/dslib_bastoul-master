#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include "ilist.h"
#include "arraylist.h"
#include "doublingarraylist.h"
#include "stack.h"

using namespace std;

void fConvert(char* f1, char* f2);
bool valid (string);
bool isVar (string);
void expBool ();
bool solve ();
//void validEqus();


void printf1();
void printf2();
void printstack();
void printEquBool();


Stack<int> theStack;
vector<int> f1;
vector<int> f2;
vector<int> popHold;
int equ = 1;


int main (int argc, char *argv[])
{
	fConvert(argv[1], argv[2]);

	expBool();
	

	return 0;
}


void fConvert(char* file1, char* file2)		//stores file data into vector<int>'s
{
	ifstream ifile (file2);

	if (ifile.fail()) 						
	{
    cout << "Could not open file.\n";
		return;
  }

	string line;
	bool done = false;
	bool found = false;
	bool eof = false;
	string str;
	string tempStr;
	int num;
	
	while (!done)		//stores the variable assignment file
	{
		line.erase();
		getline (ifile, line);	
		if (!ifile)
			done=true;

		else
		{
			stringstream ss (line);
			str = ss.get();

			tempStr = ss.peek();
			while (tempStr != " " && ss.good())
			{
				str += ss.get();
				tempStr = ss.peek();				
			}		
			num = atoi(str.c_str());

			f2.push_back(num);		//pushes number
		
			str = ss.get();
			str = ss.get();
		
			if (str == "T")		//follows number by its truth value
			{
				f2.push_back(-8);			//-8 = true
			}
			else if (str == "F")
			{
				f2.push_back(-7);		//-7 = false
			}
		}
	}

	ifstream ifile2 (file1);

	if (ifile2.fail()) 						
	{
    cout << "Could not open file.\n";
		return;
  }

  done = false;
	while (!done)			//stores equation data in f1 (replaces vars w/ their truth values)
	{
		getline (ifile2, line);
		stringstream ss (line);
		if (!ifile2.good())
		{
			done=true;
		}
		else if (done==false)
		{
			eof = false;
			while (!eof)
			{
				str = ss.get();
				if (isVar(str))
				{
					tempStr = ss.peek();
					while (isVar(tempStr))
					{
						str += ss.get();
						tempStr = ss.peek();				
					}	
				}

					if (valid(str) && ss.good())
					{
						if (str == "(")
							f1.push_back(-5);			//-5 = (
						else if (str == ")")		
							f1.push_back(-10);		//-10 = )
						else if (str == "&")
							f1.push_back(-1);			//-1 = AND
						else if (str == "|")
							f1.push_back(-2);			//-2 = OR
						else if (str == "~")
							f1.push_back(-3);

						else 
						{
							int num;
							int i;
							num = atoi(str.c_str());
							found = false;
							for (i=0; i<f2.size() && found==false; i++)		//replaces vars with bool vals
							{
								if (f2[i] == num)
								{
									found = true;
								}
							}
							f1.push_back(f2[i]);
						}							
					} 	
					if (!ss.good())
					{
						eof = true;	
						f1.push_back(-15);	
					}			
				}	
			}	
		}	
}


bool valid (string str)
{
	if (str == " ")
		return false;
	else 
		return true;
}

	
void expBool ()		//evaluates and prints expression truth value
{
	bool var1, var2, res;
	int op;
	bool error=false;

	for (int i=0; i<f1.size(); i++)		//loops through f1 vector containing all the equ info
	{
		if (f1[i] != -10 && f1[i] != -15)
		{
			error = false;		
			theStack.push(f1[i]);
		}
		else if (f1[i] == -10)		//hit a ), evaluates backwards to previous (, then re-pushes
		{
			while (theStack.top() != -5)	
			{
				if(theStack.top()==-8)
					var1 = true;
				else if(theStack.top()==-7)
					var1 = false;

				theStack.pop();

				if (theStack.top()==-3)
				{
					var1 = !var1;
					theStack.pop();
				}
				if (theStack.top()!=-5)
				{
					op = theStack.top();
					theStack.pop();

					if(theStack.top()==-8)
						var2 = true;
					else if(theStack.top()==-7)
						var2 = false;

					theStack.pop();
					if (theStack.top()==-3)
					{
						var1 = !var1;
						theStack.pop();
					}

					if (op == -1)
					{
							res = (var1 && var2);
							if (theStack.top()!=-5)
							{
								if (res)
									theStack.push(-8);
								else if (!res)
									theStack.push(-7);
							}
					}
					else if (op == -2)
					{
						res = (var1 || var2);
						if (theStack.top()!=-5)
						{
							if (res)
								theStack.push(-8);
							else if (!res)
								theStack.push(-7);
						}
					}
				}
				else if (theStack.top()==-5)
				{
					res=var1;
				}
			}
			theStack.pop();
			if (res)
				theStack.push(-8);
			else if (!res)
				theStack.push(-7);
		}
		else if (f1[i]==-15)		//hit newline marker
		{
			if (error)
				return;
			printEquBool();		//prints equation truth value
			error = true;
		}
	}

return;
}


/*
void validEqus()			////////////////////////////////////////
{
	int open, close, ops, vars;
	bool error = false;
	int equNum = 0;
	for (int i=0; i<f1.size(); i++)
	{
		if (f1[i]==-5)
			open++;
		if (f1[i]==-10)
			close++;
		if (f1[i]==-1 || f1[i]==-2)
			ops++;
		if (f1[i]==-7 || f1[i]==-8)
			vars++;
	
		if (f1[i]=-15)
		{
			if (open!=close)
				error = true;
			if (vars!=(ops+1))
				error = true;

			if (error)
			{
				cout << "Equation " << equNum << " invalid." << endl;
				for (int j=i; f1[j]!=-15; j--)
				{
					f1.erase(f1.begin()+(j-1));
				}
			}
			equNum++;
			error = false;
			open = 0;
			close = 0;
			vars = 0;
			ops = 0;
		}
	}
}
*/


void printEquBool ()
{
		cout << "Equation " << equ << " is ";
		if (theStack.top()==-8)
			cout << "true." << endl;
		else if (theStack.top()==-7)
			cout << "false." << endl;
		theStack.pop();
		while (!theStack.isEmpty())
		{
			theStack.pop();
		}
		equ++;
}

void printf1 ()
{
	cout << endl;
	cout << "########  f1  ########" << endl;
	for (int i=0; i<f1.size(); i++)
	{
		cout << "f1[" << i << "] = " << f1[i] << endl;
	}
	cout << "#############" << endl;
}

void printf2 ()
{
	cout << endl;
	cout << "########  f2  ########" << endl;
	for (int i=0; i<f2.size(); i++)
	{
		cout << "f2[" << i << "] = " << f2[i] << endl;
	}
	cout << "#############" << endl;
}

void stacktop ()
{
	cout << endl;
	cout << "theStack top " << theStack.top() << endl;
}


bool isVar (string str)
{
	if (str == "0" || str == "1" || str == "2" || str == "3" || str == "4" || str == "5" || str == "6" || str == "7" || str == "8" || str == "9")
		return true;
	else
		return false;
}







