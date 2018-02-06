#include <cstdlib>
#include <sys/time.h>
#include "qsort.h"
#define BILLION 1E9

using namespace std;


void t_mix(int *array, int size, int t);
double aveTime (double *times);

int main(){
	IntComp comp;
	int array[1000];

	for (int i=0; i<1000; i++)
		array[i] = i+1;

	timespec start, end;
	double time[20];

	for (int i=0; i<20; i++){
		clock_gettime(CLOCK_REALTIME, &start);
		endQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average endQsort time for t=0: " << aveTime(time) << endl;

	for (int i=0; i<20; i++){
		clock_gettime(CLOCK_REALTIME, &start);
		randQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average randQsort time for t=0: " << aveTime(time) << endl << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 50);
		clock_gettime(CLOCK_REALTIME, &start);
		endQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average endQsort time for t=50: " << aveTime(time) << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 50);
		clock_gettime(CLOCK_REALTIME, &start);
		randQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average randQsort time for t=50: " << aveTime(time) << endl << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 100);
		clock_gettime(CLOCK_REALTIME, &start);
		endQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average endQsort time for t=100: " << aveTime(time) << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 100);
		clock_gettime(CLOCK_REALTIME, &start);
		randQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average randQsort time for t=100: " << aveTime(time) << endl << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 300);
		clock_gettime(CLOCK_REALTIME, &start);
		endQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average endQsort time for t=300: " << aveTime(time) << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 300);
		clock_gettime(CLOCK_REALTIME, &start);
		randQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average randQsort time for t=300: " << aveTime(time) << endl << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 500);
		clock_gettime(CLOCK_REALTIME, &start);
		endQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average endQsort time for t=500: " << aveTime(time) << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 500);
		clock_gettime(CLOCK_REALTIME, &start);
		randQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average randQsort time for t=500: " << aveTime(time) << endl << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 1000);
		clock_gettime(CLOCK_REALTIME, &start);
		endQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average endQsort time for t=1000: " << aveTime(time) << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 1000);
		clock_gettime(CLOCK_REALTIME, &start);
		randQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average randQsort time for t=1000: " << aveTime(time) << endl << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 2000);
		clock_gettime(CLOCK_REALTIME, &start);
		endQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average endQsort time for t=2000: " << aveTime(time) << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 2000);
		clock_gettime(CLOCK_REALTIME, &start);
		randQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average randQsort time for t=2000: " << aveTime(time) << endl << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 5000);
		clock_gettime(CLOCK_REALTIME, &start);
		endQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average endQsort time for t=5000: " << aveTime(time) << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 5000);
		clock_gettime(CLOCK_REALTIME, &start);
		randQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average randQsort time for t=5000: " << aveTime(time) << endl << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 10000);
		clock_gettime(CLOCK_REALTIME, &start);
		endQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average endQsort time for t=10000: " << aveTime(time) << endl;

	for (int i=0; i<20; i++){
		t_mix (array, 1000, 10000);
		clock_gettime(CLOCK_REALTIME, &start);
		randQsort (array, 0, 1000, comp);
		clock_gettime(CLOCK_REALTIME, &end);
		time[i] = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	}
	cout << "Average randQsort time for t=10000: " << aveTime(time) << endl << endl;


	return 0;	
}

void t_mix (int *array, int size, int t){
	int p1, p2;
	int temp;
	for (int i=0; i<t; i++){
		p1 = rand() % size;
		p2 = rand() % size;
		temp = array[p1];
		array[p1] = array[p2];
		array[p2] = temp;
	}
}
		
double aveTime (double *times){
	double ave;
	for (int i=0; i<20; i++)
		ave += times[i];
	ave /= 20;
	return ave;
}
		






