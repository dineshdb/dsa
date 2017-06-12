#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class ArrayList {

size_t length = 0;
size_t capacity = 0;
T* data = nullptr;

void resize(){
	if(capacity <= length || capacity == 0){
		capacity += 10;
		T *n = new T[capacity];
		memcpy(n, data, length * sizeof(T) );
		if(data)
			delete []data;
		data = n;
	}
}
public:
	ArrayList(){
		resize();
	}

	ArrayList(int cap) : capacity(cap) {
		data = new T[capacity];
	}

	void insertAtBegin(T data){
		insertAtPos(0, data);
	}

	void insert(T data){
		insertAtPos(length, data);
	}
	void insertAtEnd(T data){
		insertAtPos(length, data);
	}

	void insertAtPos(int pos, T d){
		resize();
		int posIndex = pos * sizeof(T);
		memmove(data + posIndex, data, length * sizeof(T) - posIndex);
		data[pos] = d;
		length ++ ;
	}

	void remove(int pos){
		int posIndex = (pos + 1) * sizeof(T);
		memmove(data + posIndex, data, length * sizeof(T) - posIndex);
		length--;
	}

	T get(size_t pos){
		if(pos >= length)
			throw out_of_range("Please specify index within range");
		return data[pos];
	}
	size_t size(){
		return length;
	}
};

int main(){
	ArrayList<int> l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(4);
	cout << l.get(3) << endl;
	l.remove(2);
	cout << l.get(2) << endl;
	return 0;
}
