#include <iostream>
#include <string>
#include "Stack.cpp"
#include "Queue.cpp"

using namespace std;

void exerciseOne() {

	Queue<int> q1;

	int k = 0;

	while (!q1.isFull()) {

		q1.enqueue(++k);
	}

	cout << "\nThe first element in the queue: " << q1.peek() << "\n";

	cout << "\nRemoving elements from queue:";

	while (!q1.isEmpty()) {

		cout << q1.dequeue() << " ";
	}

}

template <typename T>
class QueuedStack {

private:

	Queue<T> q1, q2;

public:

	QueuedStack() {}

	~QueuedStack() {}

	int isFull() {

		return q1.isFull();
	}

	int isEmpty() {

		return q1.isEmpty();
	}

	void push(T x) {

		if (isFull()) {
			cout << "\nQueued Stack is full.\n";
		}

		q1.enqueue(x);
	}

	T pop() {

		if (isEmpty()) {
			
			cout << "\nStack is Empty.\n";

			return q1.peek();
		}
 
		int n = q1.getSize();
		T x = q1.peek();
		while (!q1.isEmpty()) {

			x = q1.dequeue();

			q2.enqueue(x);
			
		}

		for (int i = 0; i <= n-2; i++) {
			
			q1.enqueue(q2.dequeue());
		}
		q2.dequeue();

		return x;
	}

	T peek() {

		T x = pop();
		push(x);
		return x;
	}
};

void exerciseTwo() {

	//Testing QueuedStack:

	QueuedStack<int> qs;

	int k = 0;

	while (!qs.isFull()) {

		qs.push(++k);
	}

	cout << "\nThe Queued Stack has at the top: " << qs.peek() << "\n";

	cout << "\nTaking out the top 20 elements from the Queued Stack:\n";

	for (int i = 0; i < 20; i++) {

		cout << qs.pop() << " ";
	}
	cout << "\n";

}

template <typename T>
class StackedQueue {

private:

	Stack<T> s1, s2;

public:

	StackedQueue(){}
	~StackedQueue(){}

	int isEmpty() {

		return s1.isEmpty();
	}

	int isFull() {

		return s1.isFull();
	}

	T dequeue() {

		if (isEmpty()) {

			cout << "\nStacked Queue is Empty.\n";

			return s1.peek();
		}

		int k = s1.getTopLevel();
		T x;

		while (!s1.isEmpty()) {

			x = s1.pop();
			s2.push(x);
		} 
		s2.pop();
		for (int i = 0; i <= k-1; i++) {

			s1.push(s2.pop());
		}
		return x;
	}
	
	void enqueue(T x) {

		if (isFull()) {

			cout << "\nStacked Queue is Full.\n";

			return;
		}

		s1.push(x);
	}

	T peek() {

		T x = dequeue();
		enqueue(x);
		return x;
	}

};

void exerciseThree() {

	//Testing Stacked Queue.

	StackedQueue<int> sq;

	int k = 0;

	while (!sq.isFull()) {

		sq.enqueue(++k);
	}

	cout << "\nRemoving the first 15 elements from stacked queue: ";

	for (int i = 0; i < 15; i++) {

		cout << sq.dequeue() << " ";
	}

	cout << "\nThe first element in the queue: " << sq.peek() << "\n";
	
}

bool isLeap(int y) {

	if (y % 400 == 0) {
		return true;
	}

	else if (y % 100 == 0) {
		return false;
	}

	else if (y % 4 == 0) {
		return true;
	}

	else {
		return false;
	}
}

struct Date {

	int day;
	int month;
	int year;

	void display() {

		cout << day << "/" << month << "/" << year << "\n";
	}

	void isValid() {

		if (year <= 0) {
			cout << "It is not a valid date.\n";
			return;
		}

		if (month == 2) {
			if (isLeap(year) && day <= 29) {
				cout << "It is a valid date\n";
			}
			else if (!isLeap(year) && day >= 29) {
				cout << "It isn't a valid date\n";
			}
			else if (isLeap(year) && day > 29) {
				cout << "It is not a valid date\n";
			}
			else {
				cout << "It is a valid date\n";
			}
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {

			if (day > 31 || day <= 0) {
				cout << "It is not a valid date.\n";

			}
			else {
				cout << "It is a valid date.\n";
			}

		}
		else {

			if (day > 30 || day <= 0) {
				cout << "It is not a valid date.\n";
			}
			else {
				cout << "It is a valid date.\n";
			}
		}
	}

};
class Message {

private:

	Date dt;
	string sender;
	string recipient;
	string content;


public:

	Message(){}
	Message(Date d, string s, string c, string r) {

		dt = d;
		sender = s;
		recipient = r;
		content = c;
	}
	~Message(){}

	string getSender() {
		return sender;
	}

	Date getDate() {
		return dt;
	}

	string getContent() {
		return content;
	}
};

class MessageReceiver {

private:

	string name;
	
public:

	MessageReceiver() {}
	MessageReceiver(string nm) {

		name = nm;
	}
	~MessageReceiver(){}

	void receiveMessage(Queue<Message> q) {

		Message m = q.dequeue();
		string s = m.getSender();
		Date d = m.getDate();
		string c = m.getContent();
		cout << name << " Received a Message from " << s << " At: " << d.day << "/" << d.month << "/" << d.year << " Saying: \n";
		cout << c << "\n";
	}


};

class MessageSender {

private:

	string name;

public:

	Queue<Message> messagesToBeReceived;

	MessageSender() {}
	MessageSender(string nm) {

		name = nm;
	}

	~MessageSender() {}

	void writeMessage(string content, Date d, string recipient) {
		
		messagesToBeReceived.enqueue(Message(d, name, content, recipient));
	}
};

void exerciseFour() {

	//Testing the Message Sender and Receiver classes. (implemented using queues)

	Date d1;
	d1.day = 30;
	d1.month = 10;
	d1.year = 2023;

	MessageSender bob("Bob");
	MessageReceiver neil("Neil");

	bob.writeMessage("Hello Neil!", d1, "Neil");
	neil.receiveMessage(bob.messagesToBeReceived);
}


int main() {

	cout << "EXERCISE ONE: \n\n";
	exerciseOne();
	 
	cout << "\n\n EXERCISE TWO: \n\n";
	exerciseTwo();

	cout << "\n\n EXERCISE THREE: \n\n";
	exerciseThree();

	cout << "\n\nEXERCISE FOUR: \n\n";
	exerciseFour();
}