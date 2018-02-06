using namespace std;

template <class T>
class PlusTenArrayList : public ArrayList<T>
{
	private:
		T* temp;
	public:
		PlusTenArrayList();
		bool resize ();
};

template <class T>
PlusTenArrayList<T>::PlusTenArrayList()
{
}

template <class T>
bool PlusTenArrayList<T>::resize()
{
	int size = this->getSIZE();
	size+=10;
	
	T* temp = new T [size];
	
	for (int i=0; i<(size-10); i++)
	{
		temp[i] = this->get(i);
	}
	this->setArray(temp, size);
}
