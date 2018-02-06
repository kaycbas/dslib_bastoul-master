#include <iostream>
#include "list.h"

using namespace std;

int main() {

	List<int> myList;
	int size;

	myList.insert(0, 2);
	myList.insert(1, 6);
	myList.insert(1, 7);

	size = myList.size();
	cout << size << endl;

	myList.insert(0, 5);
	myList.insert(4, 13);
	myList.insert(5, 19);

	size = myList.size();
	cout << size << endl;

	Item<int> *tempItem;
	tempItem = myList.get(5);	//seg fault on o.o.b.
	cout << tempItem->value << endl;
	

	return 0;
}
