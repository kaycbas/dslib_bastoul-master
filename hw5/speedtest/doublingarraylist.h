using namespace std;

template <class T>
class DoublingArrayList : public ArrayList<T>
{
	private:
		T* temp;
	public:
		DoublingArrayList();
		bool resize ();
};

template <class T>
DoublingArrayList<T>::DoublingArrayList()
{
}

template <class T>
bool DoublingArrayList<T>::resize()
{
	int size = this->getSIZE();
	
	T* temp = new T [size*2];
	
	for (int i=0; i<(size); i++)
	{
		temp[i] = this->get(i);
	}
	size*=2;

	this->setArray(temp, size);
}
