#include <ostream>
#include "list.h"
using namespace std

template <typename T>
class ListArray : public List<T> {
	private:
		T* arr;
		int max;
		int n;
		static coonst int MINSIZE;
		void resize(int new_size);
	public:
		ListArray();
		~ListArray();
		T operator[](int pos);
		friend ostream& operator<<(ostream &out, const ListArray<T> &list);
};
