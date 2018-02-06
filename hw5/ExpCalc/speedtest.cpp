#include <iostream>
#include "time.h"
#include "ilist.h"
#include "linkedlist.h"
#include "arraylist.h"
#include "plusonearraylist.h"
#include "plustenarraylist.h"
#include "doublingarraylist.h"
#include "stack.h"

using namespace std;

double MeasureFrontInsertTime(IList<int> * list, int insertCount = 15000)
{
    double time = 0.0;
    double start = clock();

    for(int i = 0; i < insertCount; ++i)
		{ 
			list->insert(0, i);
		}

		double end = clock();
		time = end - start;
		time /= CLOCKS_PER_SEC;

    return time;
}

double MeasureBackInsertTime(IList<int> * list, int insertCount = 15000)
{
    double time = 0.0;
    double start = clock();
    for(int i = 0; i < insertCount; ++i) 
		{
			list->insert(i, i);
		}

		double end = clock();
		time = end - start;
		time /= CLOCKS_PER_SEC;

    return time;
}

int main()
{
    double frontTime = 0.0, backTime = 0.0;
    IList<int> ** lists = new IList<int>*[8];

    lists[0] = new List<int>;          // front insert
    lists[1] = new List<int>;          // back  insert
    lists[2] = new PlusOneArrayList<int>;    // front insert
    lists[3] = new PlusOneArrayList<int>;    // back  insert
    lists[4] = new PlusTenArrayList<int>;    // front insert
    lists[5] = new PlusTenArrayList<int>;    // back  insert
    lists[6] = new DoublingArrayList<int>;   // front insert
    lists[7] = new DoublingArrayList<int>;   // back  insert

    for (int i = 0; i < 8; i += 2)
    {
        frontTime = MeasureFrontInsertTime(lists[i]);
        backTime  = MeasureBackInsertTime (lists[i + 1]);

				cout << "List " << i << " front insert time: " << frontTime << endl;
				cout << "List " << i+1 << " back insert time: " << backTime << endl;

        delete lists[i];
        delete lists[i + 1];
    }
    delete [] lists;
    return 0;
}
