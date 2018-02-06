using namespace std;

template <class T>
class PlusOneArrayList : public ArrayList<T>
{
	private:
		T* temp;
	public:
		PlusOneArrayList();
		bool resize ();
};

template <class T>
PlusOneArrayList<T>::PlusOneArrayList()
{
}


template <class T>
bool PlusOneArrayList<T>::resize()
{
	int size = this->getSIZE();
	
	T* temp = new T [size+1];
	
	for (int i=0; i<(size); i++)
	{
		temp[i] = this->get(i);
	}
	size++;
	this->setArray(temp, size);
}

