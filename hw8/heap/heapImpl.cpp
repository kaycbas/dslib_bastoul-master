
template <class T, class Comparator>
MaxHeap<T,Comparator>::MaxHeap (int d, Comparator comp){
	_d = d;
	_comp = comp;
	_size = 0;
}

template <class T, class Comparator>
MaxHeap<T,Comparator>::~MaxHeap(){
}

template <class T, class Comparator>
void MaxHeap<T,Comparator>::heapify(){
	if (_size==1)
		return;
	int id = _size-1;
	int parent = floor((id-1)/_d);
	while (_comp(theDeq[parent], theDeq[id])){
		T temp = theDeq[parent];
		theDeq[parent] = theDeq[id];
		theDeq[id] = temp;
		id = parent;
		if (id!=0)
			parent = floor((id-1)/_d);
	}
}

template <class T, class Comparator>
void MaxHeap<T,Comparator>::add (const T & item){
	theDeq.push_back(item);
	_size++;
	heapify();
}

template <class T, class Comparator>
void MaxHeap<T,Comparator>::sink(){
	if (_size<=1)
		return;
	int id = 0;
	int child = _d*id+1;
	while (_comp(theDeq[id], theDeq[child])){
		T temp = theDeq[id];
		theDeq[id] = theDeq[child];
		theDeq[child] = temp;
		cout << "check" << endl;
		if ((_d*id+1)<_size)
			child = _d*id+1;
	}
}

template <class T, class Comparator>
void MaxHeap<T,Comparator>::remove (){
	theDeq[0] = theDeq[_size-1];
	theDeq.pop_back();
	_size--;
	sink();
}

template <class T, class Comparator>
bool MaxHeap<T,Comparator>::isEmpty(){
	return _size<=0;
}

template <class T, class Comparator>
const T& MaxHeap<T,Comparator>::peek() const {
	return theDeq[0];
}













