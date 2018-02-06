#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Item {
	int val;
	Item *next;
};

bool isEven (int n) {
	return (n%2==0);
}

bool isSquare (int n) {
	return (sqrt(n)==floor(sqrt(n)));
}

bool isPrime (int n) {
	bool prime = true;
	int div;
	
	if (n<=1) {
		prime = false;
	}

	else {
		for (div=3; div<=floor(sqrt(n)+1); div++) {
			if (n%div==0) {
				prime = false;
			}
		}
	}
	return prime;
}

Item *filter (Item *filter, bool (*f)(int));

Item *head = NULL;
Item *tail = NULL;
Item *temp = NULL; 
int cpyLen=0;
char *letter;

int main(int argc, char *argv[])
{
	Item *newListHead = NULL;
	int exp;
	int i;

	if (argc<3)						
	{
		cout << "Please enter more arguments.\n";
		return 0;
	}

	letter = argv[2];
	ifstream ifile (argv[1]);			

	if (ifile.fail()) 						
	{
    cout << "Could not open file.\n";
    return 0;
  }

	while (ifile)				//creation of linked list
	{
		ifile >> exp;
		if (ifile)
		{
			temp = new Item;
			temp->val = exp;
			temp->next = NULL;
			
			if(head==NULL)
			{
				head = temp;
				tail = temp;
			}
			else
			{
				tail->next = temp;
				tail = tail->next;
			}
		}
	}

	
	if (*letter=='A'){												//various function calls
		newListHead = filter (head, &isEven);
	}

	else if (*letter=='B'){
		newListHead = filter (head, &isSquare);
	}

	else if (*letter=='C'){
		newListHead = filter (head, &isPrime);
	}

	else {
		cout << "Incorrect filter input." << endl;
		return 0;
	}

	
	if (newListHead==NULL) {
		cout << "No such subset." << endl;
		return 0;
	}

 else {									//printing of subset
		for (i=0; i<cpyLen; i++) {
			cout << newListHead->val << endl;
			newListHead = newListHead->next;
		}
	}

	return 0;
}




Item *filter (Item *lead, bool (*f)(int)) //recursive filter function
{
	if (lead==NULL) {
		return NULL;
	}

	else if (f(lead->val)) {
			Item *copy;
			copy = new Item;
			cpyLen++;
			copy->val = lead->val;
			copy->next = filter(lead->next, f);
			return copy;
	}

	else {
		return filter(lead->next, f);
	}
}
























