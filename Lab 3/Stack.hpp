#pragma once
#define NMAX 50

template <typename T>
class Stack{

private:

	T stackArray[NMAX];
	int topLevel;

public:

	Stack();
	~Stack();
	void push(T x);
	T peek();
	T pop();
	int isEmpty();
	int isFull();
	void display();

};


