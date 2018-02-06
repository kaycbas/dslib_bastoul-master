#include <iostream>
#include <exception>
#include <cstdlib>
#include "bst.h"

/* -----------------------------------------------------
 * Red-Black Nodes 
 ------------------------------------------------------*/
enum Color {red, black};

template <class KeyType, class ValueType>
class RedBlackNode : public Node<KeyType, ValueType>
{
public:
	RedBlackNode (KeyType k, ValueType v, RedBlackNode<KeyType, ValueType> *p)
	: Node<KeyType, ValueType> (k, v, p)
	  { color = red; }

	virtual ~RedBlackNode () {}

	Color getColor () const
	{ return color; }

	void setColor (Color c)
	{ color = c; }

        /* The type casting allows us to treat getParent, getLeft, getRight
           as returning RedBlackNode instead of Node */
	virtual RedBlackNode<KeyType, ValueType> *getParent () const
	{ return (RedBlackNode<KeyType,ValueType>*) this->_parent; }

	virtual RedBlackNode<KeyType, ValueType> *getLeft () const
	{ return (RedBlackNode<KeyType,ValueType>*) this->_left; }

	virtual RedBlackNode<KeyType, ValueType> *getRight () const
	{ return (RedBlackNode<KeyType,ValueType>*) this->_right; }

protected:
	Color color;
};



/* -----------------------------------------------------
 * Red-Black Search Tree
 ------------------------------------------------------*/

template <class KeyType, class ValueType>
class RedBlackTree : public BinarySearchTree<KeyType, ValueType>
{
public:
	void left_rotate (RedBlackNode<KeyType,ValueType>* x) { 
		RedBlackNode<KeyType,ValueType>* y;
		y=x->getRight();
		x->setRight(y->getLeft());
		if (y->getLeft()!=NULL)
			(y->getLeft())->setParent(x);
		y->setParent(x->getParent());
		if (x->getParent()==NULL)
			this->root=y;
		else {
			if (x==(x->getParent())->getLeft())
				(x->getParent())->setLeft(y);
			else
				(x->getParent())->setRight(y);
		}
		y->setLeft(x);
		x->setParent(y);
	}

	void right_rotate (RedBlackNode<KeyType,ValueType>* x) {
		RedBlackNode<KeyType,ValueType>* y;
		y=x->getLeft();
		x->setLeft(y->getRight());
		if (y->getRight()!=NULL)
			(y->getRight())->setParent(x);
		y->setParent(x->getParent());
		if (x->getParent()==NULL)
			this->root=y;
		else {
			if (x==(x->getParent())->getRight())
				(x->getParent())->setRight(y);
			else
				(x->getParent())->setLeft(y);
		}
		y->setRight(x);
		x->setParent(y);
	}

	//returns grandparent of n or NULL if none
	RedBlackNode<KeyType,ValueType>* grandparent (RedBlackNode<KeyType,ValueType>* n) {
		if (n!=NULL && (n->getParent()!=NULL))
			return n->getParent()->getParent();
		else
			return NULL;
	}	

	//returns uncle of n or NULL if none
	RedBlackNode<KeyType,ValueType>* uncle (RedBlackNode<KeyType,ValueType>* n) {
		RedBlackNode<KeyType,ValueType>* g = grandparent(n);
		if (g==NULL)
			return NULL;
		if (n->getParent()==g->getLeft())
			return g->getRight();
		else
			return g->getLeft();
	}

	//case1: n is root
	void case1 (RedBlackNode<KeyType,ValueType>* n) {
		if (n->getParent()==NULL)
			n->setColor(black);
		else	//if not case1, call case2
			case2(n);
	}

	//case2: parent is already black
	void case2 (RedBlackNode<KeyType,ValueType>* n) {
		if (n->getParent()->getColor()==black)
			return;
		else	//if not case2, call case3
			case3(n);
	}

	//case3: parent and uncle are both red
	void case3 (RedBlackNode<KeyType,ValueType>* n) {
		RedBlackNode<KeyType,ValueType>* u = uncle(n), *g;
		if ((u!=NULL) && (u->getColor()==red)) {
			n->getParent()->setColor(black);
			u->setColor(black);
			g=grandparent(n);
			g->setColor(red);
			case1(g);	//returns to case1
		}
		else 
			case4(n);	//if not case 3, call case4
	}

	//case4: parent is red, uncle is black, node & parent are not both left/right child
	void case4 (RedBlackNode<KeyType,ValueType>* n) {
		RedBlackNode<KeyType,ValueType>* g = grandparent(n);
		if ((n==(n->getParent()->getRight())) && (n->getParent()==g->getLeft())) {
			left_rotate (n->getParent());
			n=n->getLeft();
		}
		else if ((n==(n->getParent()->getLeft())) && (n->getParent()==g->getRight())) {
			right_rotate (n->getParent());
			n=n->getRight();
		}
		case5(n);	//calls case5
	}

	//case5: parent is red, uncle is black, node & parent are left children
	void case5 (RedBlackNode<KeyType,ValueType>* n) {
		RedBlackNode<KeyType,ValueType>* g = grandparent(n);
		n->getParent()->setColor(black);
		g->setColor(red);
		if (n==(n->getParent()->getLeft()))
			right_rotate(g);
		else
			left_rotate(g);
	}


	void add (KeyType key, ValueType value) {	//inserts and calls rb case1
	RedBlackNode<KeyType,ValueType>* x = new RedBlackNode<KeyType,ValueType> (key, value, NULL);
	this->tree_insert (x);
	case1(x);
	}
};
