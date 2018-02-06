#include <iostream>
#include <exception>
#include <cstdlib>
#include "rbbst.h"

/* -----------------------------------------------------
 * main for testing
 ------------------------------------------------------*/
using namespace std;

int main (void)
{
  int a[100];

 
  for (int i = 0; i < 100; i ++) a[i] = i;
  for (int i = 99; i > 0; i --)
  { 
    int j = rand () % (i+1);
    int b = a[i]; a[i] = a[j]; a[j] = b;
  }

  RedBlackTree<int, int> *T = new RedBlackTree<int, int> ();

  for (int i = 0; i < 100; i ++)
      T->add (a[i], a[i]*a[i]);
  cout << "***ITEMS ADDED***" << endl << endl;

  //T->print (); 


  cout << "***ITERATOR PRINT***" << endl;
  for( RedBlackTree<int, int>::iterator it = T->begin(); it != T->end(); ++it)
     {
        std::cout << "(" << it->first << "," << it->second << ") " ;
     } 
	
  std::cout << endl << endl;


  cout << "***LOOKUP PRINT***" << endl;  
  for (int i = 99; i >= 0; i --) 
      std::cout << T->lookup (i) << "\n";

  delete T; 
  return 0;
}
