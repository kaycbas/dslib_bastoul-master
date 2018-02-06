#include <string>

template <class keyType, class valueType>		//map function implementations
Map<keyType, valueType>::Map()
{
	itemCount=0;
}

template <class keyType, class valueType>
Map<keyType, valueType>::~Map()
{
}

template <class keyType, class valueType>
int Map<keyType, valueType>::size() const
{
	return internalStorage.size();
}

template <class keyType, class valueType>
void Map<keyType, valueType>::add (const keyType &key, const valueType &value)
{
	int i;
	bool found=false;
	for (i=0; i<itemCount && found==false; i++)
	{
		Item <keyType, valueType> *tempItem;
		tempItem=internalStorage.get(i);
		if (key<*tempItem->get_key())
		{
			found=true;
			i--;
		}
	}
		internalStorage.insert(i, key, value);
		itemCount++;
}


template <class keyType, class valueType>
void Map<keyType, valueType>::remove (const keyType &key)
{
	bool found = false;
	int i;
	for (i=0; i<itemCount && found==false; i++)
	{
		Item<keyType, valueType>* tempItem;
		tempItem=internalStorage.get(i);
		keyType* tempKey = tempItem->get_key();
		if (key == *tempKey)
		{
			found=true;
			i--;
		}
	}
	if (found==true)
	{
		internalStorage.remove(i);
		itemCount--;
		cout << key << " removed.\n";
	}
	else
	{
		cout << "No such key.\n";
	}
}


template <class keyType, class valueType>
valueType Map<keyType, valueType>::get (const keyType &key) const
{
	bool found = false;
	Item<keyType, valueType>* tempItem;
	int i;
		
	for (i=0; i<itemCount && found==false; i++)
	{
		tempItem=internalStorage.get(i);
		keyType* tempKey = tempItem->get_key();
		if (key == *tempKey)
		{
			found=true;
		}
	}
	if (found==true)
	{
		valueType *temp = tempItem->get_value();
		return *temp;
	}
	else
	{
		cout << "No such key.\n";
		return "0";
	}
}









