
template <class keyType, class valueType>		//list function implementations
List<keyType, valueType>::List()
{
	head=NULL;
}

template <class keyType, class valueType>
List<keyType, valueType>::~List()
{
}

template <class keyType, class valueType>
int List<keyType, valueType>::size() const
{
	Item<keyType, valueType> *temp;
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

template <class keyType, class valueType>
void List<keyType, valueType>::insert(int position, const keyType &key, const valueType &value)
{
	int s=size();
	if (position<0 || position>s)
	{
		cout << "Out of bounds\n";
		return;
	}

	Item<keyType, valueType> *newItem = new Item<keyType, valueType>;
	newItem->value=value;
	newItem->key=key;

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
		Item<keyType, valueType> *temp;
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

template <class keyType, class valueType>
void List<keyType, valueType>::remove(int position)
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
		Item<keyType, valueType> *temp;
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

template <class keyType, class valueType>
void List<keyType, valueType>::set(int position, const keyType &key, const valueType &value)
{
	if (position<0 || position>=size())
	{
		//throw exception
		cout << "Out of bounds\n";
		return;
	}

	Item<keyType, valueType> *temp;
	int i;
	temp=head;
	for (i=0; i<position; i++)
	{
		temp=temp->next;
	}
	temp->value=value;
	temp->key=key;
}

template <class keyType, class valueType>
Item<keyType, valueType>* List<keyType, valueType>::get(int position) const
{
	int s = size();
	if (position<0 || position>=s)
	{
		//throw exception
		cout << "Out of bounds\n";
		return NULL;
	}

	Item<keyType, valueType> *temp;
	int i;
	temp=head;
	for (i=0; i<position; i++)
	{
		temp=temp->next;
	}
	
	return temp;	
}









