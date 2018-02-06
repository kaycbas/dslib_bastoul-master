#ifndef Q_SORT_H
#define Q_SORT_H

#include <iostream>
#include <string>

using namespace std;

struct Student{
	string name;
	int ability;
};

struct IntComp{
	bool operator()(const int val1, const int val2){
		return val1 < val2;
	}	
};


struct StdComp{
	bool operator()(const Student std1, const Student std2){
		return std1.ability < std2.ability;
	}
}; 

template <class T, class Comparator>
bool doCompare (const T item1, const T item2, Comparator comp)
{
	return comp(item1, item2);
}

template <class T, class Comparator>
int partition (T *array, int s, int e, Comparator comp){
	T pivot = array[e];

	while (s < e){
		while (doCompare(array[s], pivot, comp))
			s++;
		while (doCompare(pivot, array[e], comp))
			e--;
		//if (array[s] == array[e])
			//s++;
		if (s < e){
			T temp = array[s];
			array[s] = array[e];
			array[e] = temp;
		}
	}

	return e;	
}


template <class T, class Comparator>
void qsort(T *array, int s, int e, Comparator comp){
	if (s < e){
		int m = partition (array, s, e, comp);
		qsort(array, s, m-1, comp);
		qsort(array, m+1, e, comp);
	}
}

#endif
