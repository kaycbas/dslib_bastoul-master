#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>

using namespace std;

/* -----------------------------------------------------
	Exceptions
 ------------------------------------------------------*/

class KeyNotFoundException : public std::exception
{ // thrown when the user searches for a non-existing key
public:
   	KeyNotFoundException () throw () {}
	~KeyNotFoundException () throw () {}
};

/* -----------------------------------------------------
	Regular Binary Tree Nodes
 ------------------------------------------------------*/

template <class KeyType, class ValueType>
class Node {
public:
	Node (const KeyType & k, const ValueType & v, Node<KeyType, ValueType> *p)
        // the default is to create new nodes as leaves
	{ _item.first = k; _item.second = v; _parent = p; _left = _right = NULL; }

	const std::pair<KeyType, ValueType> & getItem () const
	{ return _item; }

	//	std::pair<KeyType, ValueType> & getItem ()
	//	{ Return; }

	const KeyType & getKey () const
	{ return _item.first; }

	const ValueType & getValue () const
	{ return _item.second; }

	void setValue (ValueType val) 
	{ _item.second = val; }

        /* the next three functions are virtual because for Red-Black-Trees,
           we'll want to use Red-Black nodes, and for those, the 
           getParent, getLeft, and getRight functions should return 
           Red-Black nodes, not just ordinary nodes.
           That's an advantage of using getters/setters rather than a struct. */

	virtual Node<KeyType, ValueType> *getParent () const
	{ return _parent; }

	virtual Node<KeyType, ValueType> *getLeft () const
	{ return _left; }

	virtual Node<KeyType, ValueType> *getRight () const
	{ return _right; }


	void setParent (Node<KeyType, ValueType> *p)
	{ _parent = p; }

	void setLeft (Node<KeyType, ValueType> *l)
	{ _left = l; }

	void setRight (Node<KeyType, ValueType> *r)
	{ _right = r; }

	virtual ~Node ()
	{ }

protected:
	std::pair<KeyType, ValueType> _item;
	Node <KeyType, ValueType> *_left, *_right, *_parent;
};


/* -----------------------------------------------------
	Regular Binary Search Tree
 ------------------------------------------------------*/

template <class KeyType, class ValueType>
class BinarySearchTree {
	public:
		BinarySearchTree () { root = NULL; }
		~BinarySearchTree () { deleteAll (root); }

		const ValueType & lookup (const KeyType & k) const {
			Node<KeyType,ValueType>* temp;
			temp = root;
			while (k!=temp->getKey() && temp!=NULL) {	//checks if correct node or done
				if (k<temp->getKey())	//goes left for k<, right for <k
					temp=temp->getLeft();
				else 
					temp=temp->getRight();
			}
			if (temp==NULL) {
				cout << "No such key found." << endl;
				return temp->getValue();
			}
			else 
				return temp->getValue();
		}

		void tree_insert (Node<KeyType,ValueType>* x) {	
			if (root==NULL) {
				root=x;
				return;
			}

			Node<KeyType,ValueType>* y = root;
			bool set = false;
			while (!set) {	//navigates tree until y hits null, then adds x
				if (x->getKey()==y->getKey()) {
					y->setValue(x->getValue());
					set=true;
				}
				else if (x->getKey() < y->getKey()) {
					if (y->getLeft()==NULL) {
						y->setLeft(x);
						x->setParent(y);
						set=true;
					}
					else 
						y=y->getLeft();
				}
				else {
					if (y->getRight()==NULL) {
						y->setRight(x);
						x->setParent(y);
						set=true;
					}		
					else
						y=y->getRight();
				}			
			}
		}
		
						
		void print () const
		{ 
			printRoot (root);
			std::cout << "\n";
		}

		class iterator {
			public:
			  iterator(Node<KeyType,ValueType>* root) 
				{
				  curr = root;
				  if(curr){
					while(curr->getLeft()){
					  curr = curr->getLeft();
					}
				  }
				}

			  const std::pair<KeyType,ValueType>& operator*() const
				{ return curr->getItem(); }

			  const std::pair<KeyType,ValueType>* operator->() const
				{ return &(curr->getItem()); }

			  bool operator==(const iterator& rhs) const
			  {
				return curr == rhs.curr; 
			  }

			  bool operator!=(const iterator& rhs) const
			  {
				return curr != rhs.curr;
			  }

			  iterator& operator++() {
				Node<KeyType,ValueType>* p;
				if (curr->getRight()) {	//steps right, goes all the way down-left
					curr=curr->getRight();	
					while (curr->getLeft())	
						curr=curr->getLeft();
				}
				else {	//finds the next correct parent
					p=curr->getParent();		
					while (p!=NULL && curr==p->getRight()) {	
						curr=p;
						p=p->getParent();
					}
					curr=p;
				}
			  }	
			  
			protected:
			  Node<KeyType, ValueType>* curr;
		};

		iterator begin() { iterator it (root); return it; }
		iterator end()   { iterator it (NULL); return it; }

	protected:
		Node<KeyType, ValueType> *root;
	
		void printRoot (Node<KeyType, ValueType> *r) const
		{
			if (r != NULL)
		  	{
				std::cout << "[";
				printRoot (r->getLeft());
				std::cout << " (" << r->getKey() << ", " << r->getValue() << ") ";
				printRoot (r->getRight());
				std::cout << "]";
		  	}
		}

		void deleteAll (Node<KeyType, ValueType> *r)
		{
		  if (r != NULL)
			{
			  deleteAll (r->getLeft());
			  deleteAll (r->getRight());
			  delete r;
			}
		}
};

