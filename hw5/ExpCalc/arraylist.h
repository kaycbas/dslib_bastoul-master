using namespace std;

template <class T>
class ArrayList : public IList<T>
{
	private:
		int SIZE;

		T* items;

		int itemCount;

	public:
		ArrayList();

		int size () const;

		void insert (int position, const T & val);

		void remove (int position);

		void set (int position, const T & val);

		T& get (int position);

		int getSIZE ();

		void setArray (T* temp, int newSize);


		virtual bool resize() = 0;
};

#include "arrayImpl.h"
