class StackUnderflow {};

template <class T>
class Stack {
	int top = 0;
	int capacity = 0;
	T *data = nullptr;

	void resize(){
		if(top >= capacity) {
			capacity *= 2;
			T *ndata = new T[capacity];
			for(int i = 0 ; i < top ; i++){
				*(ndata +i) = *(data + i);
			}
			delete[] data;
			data = ndata;
		}
	}

public:
	Stack(){
		capacity = 10;
		data = new T[capacity];
	}
	void push(T d){
		resize();
		*(data + top++) = d;
	}
	T pop(){
		if(top < 0)
			throw StackUnderflow();
		return *(data + --top );
	}

	bool isEmpty(){
		return top == 0;
	}

	int getCapacity(){
		return capacity;
	}
};
