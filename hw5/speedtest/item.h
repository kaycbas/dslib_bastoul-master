using namespace std;

template <class T>
struct Item
{
  T value;
  Item<T> *prev, *next;
};


