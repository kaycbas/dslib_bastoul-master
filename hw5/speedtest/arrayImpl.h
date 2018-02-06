
template <class T>
ArrayList<T>::ArrayList()
{
	SIZE = 5;
	itemCount = 0;
	items = new T [SIZE];
}

template <class T>
int ArrayList<T>::size () const
{
	return itemCount;
}

template <class T>
void ArrayList<T>::insert (int position, const T & val)
{
	if (itemCount>=SIZE)
	{
	//cout << "ic: " << itemCount << endl;
	//cout << "Size: " << SIZE << endl; 
	resize();
	//cout << "ic: " << itemCount << endl;
	//cout << "new size: " << SIZE << endl; 
	}
		
	bool ableToInsert = (position>=0) && (position<=itemCount) && (itemCount<SIZE);


	if (ableToInsert)
	{
		for (int pos=itemCount; pos>position; pos--)
		{
			items[pos]=items[pos-1];
		}
		items[position]=val;
		itemCount++;
	}
}

template <class T>
void ArrayList<T>::remove (int position)
{
	bool ableToRemove = (position>=0) && (position<itemCount);
	if (ableToRemove)
	{
		for (int fromIndex=position+1, toIndex=position; fromIndex<=itemCount; fromIndex++, toIndex++)
		{
			items[toIndex] = items[fromIndex];
		}
		itemCount--;
	}
}

template <class T>
void ArrayList<T>::set (int position, const T & val)
{
	bool ableToSet = (position>=0) && (position<=itemCount);

	if (ableToSet)
		items[position] = val;
	else 
		cout << "Error\n";
		//throw exception
}

template <class T>
T& ArrayList<T>::get (int position)
{
	bool ableToGet = (position>=0) && (position<itemCount);

	if (ableToGet)
		return items[position];
	else
		cout << "Error\n";
		//throw exception 
}

template <class T>
int ArrayList<T>::getSIZE ()
{
	return SIZE;
}
	

template <class T>
void ArrayList<T>::setArray (T* temp, int newSize)
{
	SIZE = newSize;
	delete [] items;
	items = new T [SIZE];
	for (int i=0; i<SIZE; i++)
	{
		items[i] = temp[i];
	}
}

template <class T>
bool ArrayList<T>::resize ()
{
	T* temp = new T [SIZE*2];
	
	for (int i=0; i<SIZE; i++)
	{
		temp[i] = items[i];
	}
	SIZE*=2;

	delete [] items;
	items = new T [SIZE];

	for (int i=0; i<SIZE; i++)
	{
		items[i] = temp[i];
	}
	delete temp;
}







