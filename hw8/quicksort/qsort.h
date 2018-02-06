#include <iostream>

struct IntComp
{
	bool operator()(const int val1, const int val2)
	{
		return val1 < val2;
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
		if (array[s] == array[e])
			s++;
		else if (s < e){
			T temp = array[s];
			array[s] = array[e];
			array[e] = temp;
		}
	}

	return e;	
}

template <class T, class Comparator>
void endQsort(T *array, int s, int e, Comparator comp){
	if (s < e){
		int m = partition (array, s, e, comp);
		endQsort(array, s, m-1, comp);
		endQsort(array, m+1, e, comp);
	}
}

template <class T, class Comparator>
int randPartition (T *array, int s, int e, Comparator comp){
	int pivIndx = s + rand() % (e - s + 1);
	T pivot = array[pivIndx];
	std::swap (array[pivIndx], array[e]);

	while (s < e){
		while (doCompare(array[s], pivot, comp))
			s++;
		while (doCompare(pivot, array[e], comp))
			e--;
		if (array[s] == array[e])
			s++;
		else if (s < e){
			T temp = array[s];
			array[s] = array[e];
			array[e] = temp;
		}
	}

	return e;	
}

template <class T, class Comparator>
void randQsort (T *array, int s, int e, Comparator comp){
	if (s < e){
		int m = randPartition (array, s, e, comp);
		randQsort(array, s, m-1, comp);
		randQsort(array, m+1, e, comp);
	}
}




















