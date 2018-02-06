#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

template <class T, class Comparator>
class MaxHeap {
	public:
		MaxHeap (int d, Comparator comp);
		~MaxHeap ();

		void add (const T & item);
		const T & peek () const;
		void remove ();
		bool isEmpty ();
		void heapify ();
		void sink ();
	private:
		int _d;
		Comparator _comp;
		int _size;
		deque<T> theDeq;
				
};

#include "heapImpl.cpp"
#endif
