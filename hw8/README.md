Each part of the hw is in a separate folder with its own Makefile.

For the qsort and heap run time analysis I used a linux specific function called get_clocktime() which is more precise than the standard ctime. However in order to use it I needed to compile with the flag -lrt (discovered after some research online). For some reason this isn't working through the Makefile but it does on the command line (even though the exact same command line is executed). So for quicksort and heap the programs can be compiled from the command line using: g++ -o main main.cpp -lrt 

In heap the remove() function works up to 100 but past that it gives a seg fault. I didn't have the time to debug this so for my runtime analysis I only included the insert() times.

In the graph for P2, the time for endQsort at p=0 was actually 0.0048, not 0.00048, but since it was so different from all the other runtimes it was messing up the scale of the graph so I reduced it for viewing purposes. 
