#include <cstdlib>
#include <sys/time.h>
#include "heap.h"
#define BILLION 1E9

struct IntComp{
	bool operator()(const int val1, const int val2){
		return val1 < val2;
	}	
};

void mix (int *array, int size);
double aveTime (double *times);

int main(){

	IntComp comp1;
	MaxHeap<int, IntComp> *theHeap;
	int array[1000];

	timespec start, end;
	double times[10];
	for (int i=0; i<10; i++){
		theHeap = new MaxHeap<int,IntComp> (2,comp1);
		mix (array, 1000);
		clock_gettime(CLOCK_REALTIME, &start);	
		for (int k=0; k<1000; k++)
			theHeap->add(array[k]);	
		clock_gettime(CLOCK_REALTIME, &end);
		times[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
		
	}
	double ave = aveTime(times);
	cout << "d=2 ave insert time: " << ave << endl;


	for (int i=0; i<10; i++){
		theHeap = new MaxHeap<int,IntComp> (3,comp1);
		mix (array, 1000);
		clock_gettime(CLOCK_REALTIME, &start);	
		for (int k=0; k<1000; k++)
			theHeap->add(array[k]);	
		clock_gettime(CLOCK_REALTIME, &end);
		times[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	ave = aveTime(times);
	cout << "d=3 ave insert time: " << ave << endl;

	for (int i=0; i<10; i++){
		theHeap = new MaxHeap<int,IntComp> (4,comp1);
		mix (array, 1000);
		clock_gettime(CLOCK_REALTIME, &start);	
		for (int k=0; k<1000; k++)
			theHeap->add(array[k]);	
		clock_gettime(CLOCK_REALTIME, &end);
		times[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	ave = aveTime(times);
	cout << "d=4 ave insert time: " << ave << endl;
		
	for (int i=0; i<10; i++){
		theHeap = new MaxHeap<int,IntComp> (10,comp1);
		mix (array, 1000);
		clock_gettime(CLOCK_REALTIME, &start);	
		for (int k=0; k<1000; k++)
			theHeap->add(array[k]);	
		clock_gettime(CLOCK_REALTIME, &end);
		times[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	ave = aveTime(times);
	cout << "d=10 ave insert time: " << ave << endl;

	for (int i=0; i<10; i++){
		theHeap = new MaxHeap<int,IntComp> (20,comp1);
		mix (array, 1000);
		clock_gettime(CLOCK_REALTIME, &start);	
		for (int k=0; k<1000; k++)
			theHeap->add(array[k]);	
		clock_gettime(CLOCK_REALTIME, &end);
		times[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	ave = aveTime(times);
	cout << "d=20 ave insert time: " << ave << endl;

	for (int i=0; i<10; i++){
		theHeap = new MaxHeap<int,IntComp> (50,comp1);
		mix (array, 1000);
		clock_gettime(CLOCK_REALTIME, &start);	
		for (int k=0; k<1000; k++)
			theHeap->add(array[k]);	
		clock_gettime(CLOCK_REALTIME, &end);
		times[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	ave = aveTime(times);
	cout << "d=50 ave insert time: " << ave << endl;

	for (int i=0; i<10; i++){
		theHeap = new MaxHeap<int,IntComp> (100,comp1);
		mix (array, 1000);
		clock_gettime(CLOCK_REALTIME, &start);	
		for (int k=0; k<1000; k++)
			theHeap->add(array[k]);	
		clock_gettime(CLOCK_REALTIME, &end);
		times[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	ave = aveTime(times);
	cout << "d=100 ave insert time: " << ave << endl;


	

	

	return 0;
}

void mix (int *array, int size){
	int p1, p2;
	int temp;
	for (int i=0; i<1000; i++){
		p1 = rand() % size;
		p2 = rand() % size;
		temp = array[p1];
		array[p1] = array[p2];
		array[p2] = temp;
	}
}

double aveTime (double *times){
	double ave;
	for (int i=0; i<10; i++)
		ave += times[i];
	ave /= 10;
	return ave;
}
