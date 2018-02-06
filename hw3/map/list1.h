using namespace std;

template <class keyType, class valueType>
struct Item
{
  valueType value;
	keyType key;
  Item<keyType, valueType> *prev, *next;
};


template <class keyType, class valueType>
class List
{
  public:
    List ();   // constructor

    ~List ();  // destructor

    int size () const;  // returns the number of elements in the list

    void insert (int position, const keyType &key, const valueType &value);
      /* Inserts val into the list before the given position,
         shifting all later items one position to the right.
         Inserting before 0 (i.e., position = 0) makes it the 
         new first element.
         Inserting before size() (i.e., position = size()) makes 
         it the new last element.
         Your function should throw an exception if position is
         outside the legal range, which would be 0-size() here. */

    void remove (int position);
      /* Removes the item from the given position, shifting all
         later items one position to the left.
         Your function should throw an exception if position is
         outside the legal range. */

    void set (int position, const keyType &key, const valueType &value);
      /* Overwrites the given position with the given value.
         Does not affect any other positions.  
         Your function should throw an exception if position is
         outside the legal range. */

    Item<keyType, valueType>* get (int position) const;
      /* Returns the item at the given position.
         Your function should throw an exception if position is
         outside the legal range. */

  private:
		Item<keyType, valueType> *head;


      /* You may add further private data fields or helper methods if 
         you choose. You should not alter the public signature. */
};


#include "listImpl1.h"

