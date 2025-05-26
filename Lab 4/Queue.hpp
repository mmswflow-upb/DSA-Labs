#define NMAX 50

template <typename T>
class Queue {

private:

	T queueArray[NMAX];
	int head, tail, size;

public:

	Queue();
	~Queue();
	void enqueue(T x);
	T dequeue();
	T peek();
	int isEmpty();
	int isFull();
	int getSize();
	
};