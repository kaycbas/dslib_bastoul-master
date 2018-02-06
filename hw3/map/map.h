#include <string>

using namespace std;

template <class keyType, class valueType>
class Item
{
	public:
		Item();
		keyType* get_key();			//returns pointer to item key
		valueType* get_value();		//returns pointer to item value (aka name)

		valueType value;
		keyType key;
		Item<keyType, valueType> *prev, *next;	//list linkers
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


template <class keyType, class valueType>
class Map
{
  public:
    Map ();  // constructor for a new empty map

    ~Map (); // destructor

    int size () const; // returns the number of key-value pairs

    void add (const keyType & key, const valueType & value); 
      /* Adds a new association between the given key and the given value.
         If the key already has an association, it should throw an exception.
      */

   void remove (const keyType & key);
     /* Removes the association for the given key.
        If the key has no association, it should throw an exception. */

   valueType get (const keyType & key) const;
     /* Returns the value associated with the given key.
        If the key has no association, it should throw an exception. */

  private:
    List<keyType, valueType> internalStorage;
		int itemCount;
     /* You should store all of your associations inside one list.
        It is part of your assignment to figure out what types you 
        should store in that list.
        (Hint: you may need to add an additional definition.) */

     /* If you like, you can add further data fields and private
        helper methods.
        In particular, a 'find' function could be useful, which
        will find the index in the list at which a given key sits. */
};



#include "itemImpl.h"
#include "listImpl1.h"
#include "mapImpl.h"
