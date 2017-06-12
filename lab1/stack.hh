#ifndef MSTACK_HH
#define MSTACK_HH

class StackUnderflow {};

template <class T>
class Stack {
	int top = 0;
	int capacity = 0;
	T *data = nullptr;

	void resize();

public:
	Stack();
	void push(T d);
	T pop();
	bool isEmpty();
	int getCapacity();
};

#endif
