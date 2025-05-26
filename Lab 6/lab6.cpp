#include <iostream>
#include <string>
#include "LinkedList.hpp"
#include "CircularLinkedList.hpp"

using namespace std;



void exercise1() {

	//Testing the implementation of the Doubly-Linked Linear List
	//and testing the REVERSE printList method
	LinkedList<int> t;

	for (int i = 0; i < 50; i++) {

		t.addLast((i+1));
	}

	t.reversePrintList();

	t.removeFirstOccurrence(33);
	t.reversePrintList();

	t.addLast(0);
	t.reversePrintList();

	while (!t.isEmpty()) {
		t.removeFirst();
	}

	t.printList();

}

void exercise2() {

	LinkedList<int> t;

	for (int i = 1; i < 11; i++) {

		t.addLast(i);
	}

	LinkedList<int> tEven = t.getEvenList();

	tEven.printList();

	LinkedList<int> tOdd = t.getOddList();
	tOdd.printList();

}


template <typename T>
class Queue {

private:

	int size;
	LinkedList<T> ll;

public:
	Queue() { size = 0; }

	~Queue(){}

	void enqueue(T x) {

		size++;
		ll.addLast(x);
	}

	T peek() {

		return ll.pfirst->info;
	}

	T dequeue() {

		if (!isEmpty()) {
			
			T res = peek();
			ll.removeFirst();
			size--;
			return res;
		}
		cout << "\nQueue is empty.\n";
		return peek();
	}

	bool isEmpty() {

		return ll.isEmpty();
	}

	int getSize() {
		return size;
	}

	void display() {

		if (!isEmpty()) {
			ll.printList();
			return;
		}
		cout << "\nQueue is empty.\n";
		return;

	}
};

void exercise3() {

	//Testing implementation of the queue using Linked Lists.

	Queue<int> q1;

	for (int i = 1; i < 31; i++) {
		q1.enqueue(i);
	}

	q1.display();

	q1.dequeue();
	q1.display();


	while (!q1.isEmpty()) {

		q1.dequeue();
	}

	q1.display();
}


void exercise4() {

	//Testing the implementation of Circular Linked Lists

	CircularLinkedList<int> cll;

	for (int i = 1; i < 21; i++) {

		cll.addLast(i);
	}
	cll.addFirst(20);
	cll.addLast(21);
	cll.addFirst(21);
	cll.printList();

	cll.removeFirst();
	cll.printList();

	cll.removeLastOccurence(20);
	cll.printList();

	cll.addLast(301);
	struct clist_elem<int>* a = cll.findFirstOccurence(301);

	cll.printList();

	if (a != nullptr) {

		cout << "\nThe element next to the first occurence of 301 is: " << a->next->info << "\n";
	}

}

void exercise5() {

	//Testing the implementation of front-Half and back-Half methods of Circular Linked List Class

	CircularLinkedList<int> cll;

	cll.addLast(1);
	cll.addFirst(2);
	cll.printList();

	CircularLinkedList<int> cllFront = cll.frontHalf();
	cllFront.printList();
	 
	CircularLinkedList<int> cllBack = cll.backHalf();
	cllBack.printList();

}

int main() {

	//cout << "EXERCISE ONE: \n\n";
	//exercise1();

	//cout << "\n\nEXERCISE TWO: \n\n";
	//exercise2();

	//cout << "\n\nEXERCISE THREE: \n\n";
	//exercise3();
	

	///cout << "\n\nEXERCISE FOUR: \n\n";
	//exercise4();

	//cout << "\n\nEXERCISE FIVE: \n\n";
	//exercise5();
}