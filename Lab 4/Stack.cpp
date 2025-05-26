#include <iostream>
#include <string>
#include "Stack.hpp"
using namespace std;

template <typename T>
Stack<T>::Stack(){

	topLevel = -1;
}

template<typename T>
Stack<T>::~Stack(){}

template<typename T>
int Stack<T>::isEmpty() {

	return (topLevel < 0);
}

template<typename T>
int Stack<T>::isFull() {

	return (topLevel == NMAX - 1);
}

template<typename T>
void Stack<T>::display() {

	if (isEmpty()) {

		cout << "\n\nStack is empty.\n";
		return;
	}

	cout << "\n\nThe elements of the stack: ";

	for (int i = 0; i <= topLevel; i++) {

		cout << stackArray[i] << " ";
	}
}

template<typename T>
void Stack<T>::push(T x) {

	if (isFull()) {

		cout << "\n\nStack is already at full capacity. \n";
		return;
	}
	stackArray[++topLevel] = x;
}

template<typename T>
T Stack<T>::pop() {

	if (isEmpty()) {
		cout << "\n\nStack is already empty. \n";
		
		return stackArray[0];
	}
	return stackArray[topLevel--];
}

template<typename T>
T Stack<T>::peek() {

	if (isEmpty()){

		cout << "\n\n Stack is empty.\n";

		return stackArray[0];
	}
	return stackArray[topLevel];

}

template<typename T>
int Stack<T>::getTopLevel() {

	return topLevel;
}