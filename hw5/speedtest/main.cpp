#include <iostream>
#include "ilist.h"
#include "linkedlist.h"
#include "arraylist.h"
#include "plusonearraylist.h"
#include "plustenarraylist.h"
#include "doublingarraylist.h"
#include "stack.h"

using namespace std;

int main () {

	PlusOneArrayList<int> oneArray;
	DoublingArrayList<int> inhArray;
	
	int i=0;
	int num;
	while (i<31)
	{
		cout << "enter num: \n";
		cin >> num;
		inhArray.insert(i, num);
		i++;
	}
	
	i=0;
	while (i<10)
	{
		num = inhArray.get(i);
		cout << "num: " << num << endl;
		i++;
	}

	return 0;
}
