#include <iostream>
#include <sstream>

using namespace std;

int n;
int strLen;

void print (char *, int *);		//print function
void recurs (char *, int *);	//recursion function

int main(int argc, char *argv[])
{
	string charStr;
	string nStr;
	char *chars;
	int *a;
	int i;

	if (argc<3)									//checks command line arguments
	{
		cout << "Please enter more arguments.\n";
		return 0;
	}

	charStr = argv[1];
	strLen = charStr.length();	//gets string length
	chars = new char [strLen]; 	//allocates char array for characters
	stringstream ss1 (charStr);	//puts string in stringstream
	
	for (i=0; i<strLen; i++)		//fills char array with characters
	{
		chars[i] = ss1.get();
	}

	nStr = argv[2];							//gets n
	stringstream ss2 (nStr);		//puts n in stringstream
	ss2 >> n;										//stores n in a variable
	a = new int [n];						//allocates an array of length n

	for (i=0; i<n; i++)					//sets all array spots to 0
	{
		a[i]=0;
	}

	print (chars, a);						//calls functions
	recurs (chars, a);

	cout << endl;

	return 0;
}


void print (char *chars, int *a)  //prints characters of current combination
{
	int i;

	for (i=0; i<n; i++)
	{
		cout << chars[a[i]];
	}
	cout << " ";
}


void recurs (char *chars, int *a)
{
	int i, j;
	bool done=true;

	a[n-1]++;			//increments the last place in the set

	for (i=0; i<n; i++)			//base case: checks if on the final read
	{
		if (a[i]!=strLen-1)
		{
			done=false;
		}
	}
	if (done==true)
	{
		print (chars, a);
	}


	else										//recursive case
	{
		for (i=0; i<n-1; i++)	//checks if last place reached the end of the char array
		{
			for (j=0; j<n; j++)
			{
				if (a[j]==strLen)
				{
					a[j]=0;
					a[j-1]++;
				}
			}
		}

	print (chars, a);
	recurs (chars, a);
	}
}












	
