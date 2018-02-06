template <typename T>
class Stack : public DoublingArrayList<T>
{
 public:
  Stack();
  ~Stack();

  bool isEmpty() const;

  void push(const T& val);

  void pop();

  T const & top() const;

};

template <typename T>
Stack<T>::Stack()
{
}

template <typename T>
Stack<T>::~Stack()
{
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	int size = this->size();
	if (size==0)
		return true;
	else
		return false;
}

template <typename T>
void Stack<T>::push(const T& val)
{
	int size = this->size();
	this->insert(size, val);
}

template <typename T>
void Stack<T>::pop()
{
	int size = this->size();
	this->remove(size-1);
}
	
template <typename T>
T const & Stack<T>::top() const
{
	T* temp;
	int size = this->size();
	temp = this->get(size-1);
	return *temp;
}







