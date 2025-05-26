#include <iostream>
#include <string>
#include "Point.cpp"
#include "Stack.cpp"
#include <cmath>

using namespace std;

template <typename T>
void swapVal(T &x, T &y) {

	T temp = x;
	x = y;
	y = temp;

}

template <typename T>
void sort(T arr[], int size) {

	for (int i = 0; i < size - 1; i++) {

		for (int v = i + 1; v < 5; v++) {

			if (arr[i] > arr[v]) {

				swapVal(arr[i] , arr[v]);
			}
		}
	}

}

template<typename T>
void display(T arr[], int size) {

	
	for (int i = 0; i < size; i++) {

		cout << arr[i] << " ";
	}
	
}

void exerciseOne() {

	//Testing implementation of Template Point Class:

	Point<int> p0;
	p0.display("Point 0");

	Point<int> p1(1,2);
	p1.display("Point 1");
	p1.moveXY(3,4);
	p1.display("New Point 1");

	Point<double> p2(4.3, 5.4);
	p2.display("Point 2");
	p2.moveX(8.4);
	p2.display("New Point 2");

	Point<string> p3("4", "5");
	p3.display("Point 3");
	p3.moveY("9");
	p3.display("New Point 3");
}

void exerciseTwo() {

	//Testing template function for sorting arrays.

	const int size = 5;
	double arr[size];

	for (int i = 0; i < 5; i++) {

		cout << "\nType element " << (i + 1) << " :";
		cin >> arr[i];
	}
	sort(arr, size); 

	display(arr, size);
}

void exerciseThree() {

	//Testing the implementation of Template Stack Class

	Stack<int> st;

	int k = 0;

	while (!st.isFull()) {


		st.push(++k);
	}
	
	st.display();


	for (int i = 0; i < 10; i++) {

		st.pop();
	}

	st.display();

	cout << "The top element in the stack is: " << st.peek() << "\n";

}

void exerciseFour() {

	//Function that gets as input a sequence of numbers and displays them in
	//reversed order using Stacks

	Stack<double> stN;

	int z;
	cout << "How many numbers will you insert: ";
	cin >> z;

	for (int i = 0; i < z; i++) {

		double v;
		cout << "Insert number " << (i+1) << " :";
		cin >> v;
		stN.push(v);
	}

	cout << "\n\nNumbers in reversed order: ";

	while (!stN.isEmpty()) {

		cout << stN.peek() << " ";
		stN.pop();
	}

	stN.display();
	
}

double dfo(Point<double> p) {

	//dfo short for Distance From Origin

	return sqrt(pow(p.getX(), 2) + pow(p.getY(), 2));
}

int partition(Point<double> arr[], int l, int r) {

	double pivotDist = dfo(arr[r]);
	int i = l-1;//Keep track of the last index of the elements smaller than pivot.
	Point<double> temp;//used for swapping elements.

	for (int j = l; j < r; j++) {

		if (dfo(arr[r]) < pivotDist ) {

			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = temp;

	return i + 1;

}

void quicksort(Point<double> arr[], int l, int r) {

	//recursive function for sorting arrays.

	if (l >= r){
		return;
	}

	int p = partition(arr, l, r);
	 
	quicksort(arr, l , p - 1);
	quicksort(arr, p+1, r);

}

void extraExercise1() {

	//Testing alternative algorithm for sorting an array of points

	//Algorithm used: Quicksort.

	Point<double> points[5];

	points[4] = Point<double>(1.0, 1.0);
	points[3] = Point<double>(2.0,2.0);
	points[2] = Point<double>(0.0, 0.0);
	points[1] = Point<double>(3.0, 3.0);
	points[0] = Point<double>(4.0,4.0);

	quicksort(points, 0, 4);

	for (auto p : points) {//auto keyword detects data type from initialized variables only

		p.display("Point X");
	}
}

void extraExercise2() {

	//Palindrome Identifier

	Stack<char> st;

	string inp;

	cout << "Type a sentence or phrase to check if it's a palindrome:";
	getline(cin, inp);//a method to read strings containing whitespace (cin alone can't), so we can also read phrases
	
	string newInp;//create a string with no whitespace, our palindrome identifier ignores spaces

	for (int i = 0; i < inp.length(); i++) {

		if (inp.at(i) != ' ') {
			newInp += tolower(inp.at(i));
			st.push(tolower(inp.at(i)));
		}
	}
	
	string reverseInp;//We pop every element from the stack, inserting in reverse order the characters of our candidate

	while (!st.isEmpty()) {

		reverseInp += st.pop();
	}
	
	if (reverseInp == newInp) {

		cout << "It is a palindrome.\n";
		return;
	}

	cout << "It is not a palindrome.\n";
}


template<typename T>
class LargeStack {
	
private: 

	Stack<T> Smain;
	Stack<T> Saux;

public: 

	LargeStack() {}
	~LargeStack(){}

	void push(T x) {

		Smain.push(x);
	}
	T pop() {

		return Smain.pop();
	}
	T peek() {

		return Smain.peek();
	}
	int isFull() {

		return Smain.isFull();
	}
	int isEmpty() {

		return Smain.isEmpty();
	}
	void display() {
		Smain.display();
	}
	void swap(int i, int j) {

		if (i >= 50 || j >= 50 || i == j) {
			
			cout << "\n\nInvalid Indexes.\n\n";
			return;
		}

		T e1, e2;
		
		for (int z = 49; z >= min(i, j); z--) {

			if (z == i) {

				e1 = Smain.pop();

			}else if (z == j) {

				e2 = Smain.pop();
			}
			else {
				Saux.push(Smain.pop());
			}
		}

		for (int v = min(i, j); v <= 49; v++) {

			if (v == j) {
				Smain.push(e1);
			}
			else if (v == i) {
				Smain.push(e2);
			}
			else {

				Smain.push(Saux.pop());
			}
		}
	}
};

void extraExercise3() {

	LargeStack<double> ls;

	for (int i = 0; i < 50; i++) {

		ls.push(i);
	}
	ls.display();

	ls.swap(44,43);
	ls.display();

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

	cout << "\n\nEXTRA EXERCISE 1: \n\n";
	extraExercise1();

	cout << "\n\nEXTRA EXERCISE 2: \n\n";
	extraExercise2();

	cout << "\n\nEXTRA EXERCISE 3: \n\n";
	extraExercise3();
}