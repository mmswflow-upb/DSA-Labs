#include <iostream>
#include <string>
#include "Queue.hpp"

using namespace std;

template<typename T>
Queue<T>::Queue() {

	head = tail = size = 0;
}

template<typename T>
Queue<T>::~Queue() {}

template<typename T>
void Queue<T>::enqueue(T x) {

	if (isFull()) {

		cout << "\n Queue is Already Full.\n";
	}

	queueArray[tail] = x;
	tail = (tail + 1) % NMAX;
	size++;
}

template <typename T>
int Queue<T>::isEmpty() {

	return (size == 0);

}

template<typename T>
T Queue<T>::dequeue() {

	if (isEmpty()) {

		cout << "Queue is empty.";
		return queueArray[0];
	}

	T x = queueArray[head];
	head = (head + 1) % NMAX;
	size--;
	return x;
}
template <typename T>
T Queue<T>::peek() {

	return queueArray[head];
}

template <typename T>
int Queue<T>::isFull() {

	return (size == NMAX);
}

template<typename T>
int Queue<T>::getSize() {
	return size;
}