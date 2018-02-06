
template <class T>
List<T>::List()
{
	head=NULL;
}

template <class T>
List<T>::~List()
{
}

template <class T>
int List<T>::size() const
{
	Item<T> *temp;
	int size=0;
	if (head==NULL)
		return size;
	else
	{
		temp=head;
		while (temp!=NULL)
		{
			size++;
			temp=temp->next;
		}
		return size;
	}
}

template <class T>
void List<T>::insert(int position, const T& val)
{
	int s=size();
	if (position<0 || position>s)
	{
		cout << "Out of bounds\n";
		return;
	}

	Item<T> *newItem = new Item<T>;
	newItem->value=val;

	if (head==NULL) 
	{
		head=newItem;
		newItem->prev=NULL;
		newItem->next=NULL;
	}

	else if (position==0)
	{
		newItem->prev=NULL;
		newItem->next=head;
		head->prev=newItem;
		head=newItem;
	}

	else
	{
		int i;
		Item<T> *temp;
		temp=head;

		for (i=1; i<position; i++)
		{
			temp=temp->next;
		}
		
		if (position==s)
		{
			newItem->prev=temp;
			newItem->next=NULL;
			temp->next=newItem;
		}

		else
		{
			newItem->prev=temp;
			newItem->next=temp->next;
			temp->next=newItem;
			temp=newItem->next;
			temp->prev=newItem;
		}
	}
}

template <class T>
void List<T>::remove(int position)
{
	int s=size();
	if (position<0 || position>s)
	{
		//throw exception
		cout << "Out of bounds\n";
		return;
	}

	if (head->next==NULL)
	{
		head=NULL;
	}

	else if (position==0)
	{
		head=head->next;
		head->prev=NULL;
	}

	else 
	{
		Item<T> *temp;
		int i;
		temp=head;
		for (i=1; i<position; i++)
		{
			temp=temp->next;
		}

		if (position=(s-1))
		{
			temp->next=NULL;
		}
		else
		{
			temp->next=temp->next->next;
			temp=temp->next->next;
			temp->prev=temp->prev->prev;
		}
	}
}

template <class T>
void List<T>::set(int position, const T& val)
{
	if (position<0 || position>=size())
	{
		//throw exception
		cout << "Out of bounds\n";
		return;
	}

	Item<T> *temp;
	int i;
	temp=head;
	for (i=0; i<position; i++)
	{
		temp=temp->next;
	}
	temp->value=val;
}

template <class T>
Item<T>* List<T>::get(int position) const
{
	if (position<0 || position>=size())
	{
		//throw exception
		cout << "Out of bounds\n";
		return 0;
	}

	Item<T> *temp;
	int i;
	temp=head;
	for (i=0; i<position; i++)
	{
		temp=temp->next;
	}
	
	return temp;	
}









