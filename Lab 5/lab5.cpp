#include <iostream>
#include <string>
using namespace std;

template <typename T>
void display(T a[], int size) {

	cout << "\nDisplaying Array: ";

	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

void exercise1() {

	//Adding elements into an array using a pointer

	int a[6];

	int* pa = a;

	for (int i = 0; i < 6; i++ ){

		int x;
		cout << "Insert integer " << (i+1)<< " : ";
		cin >> x;

		*(pa + i) = x;
	}

	display(a, 6);
}

void exercise2() {

	//Displaying in reverse order an array using pointers.

	int a[9] = { 9,8,7,6,5,4,3,2,1 };

	int* pa = a;

	for (int i = 8; i >= 0; i--) {

		cout << *(pa+i) <<" ";
	}

}

template <typename T>
void reverseArr(T* a, int size ) {

	//We store the pointer a to the array in a separate variable, 
	//because we want to increment the original one inside the for loop, so that we can access the elements before the middle element in the array
	//and use the alternatively saved one to access the elements after the middle element in the array

	T temp;
	T* constA = a;

	for (int i = size - 1; i >= size/2 ; i--) {

		temp = *a;
		
		*a = *(constA  + i);
		*(constA + i) = temp;
		a++;
	}
}

void exercise3() {

	//Testing the implementation of the reverse function using only pointers.

	int a[] = { 1,2,3,4,5,6,7,8,9 };
	reverseArr(a,9);
	display(a, 9);

	string s[] = { "Hey", "There", " I'm ", "Mike"};
	reverseArr(s, 4);
	display(s, 4);

}

char* getDep(char* p) {

	while (*p != NULL) {

		if (*p == ',') {
			p = p + 2;
			break;
		}
		p++;
	}
	return p;
}

void exercise4() {

	//Getting the department from a character sequence using pointers.

	char x[] = "Un Loc , LOC";

	cout << getDep(x) << "\n";
}


char* commaReplacer(char* p) {

	char* t = p;

	while (*t != NULL) {

		if (*t == ',') {
			*t = ' ';
		}
		t++;
	}
	return p;
}

void exercise5() {

	char s[] = "Hi,There,My,Name,Is,,Joe,,,,!";
	commaReplacer(s);
	cout << s << "\n";

}

int main() {

	cout << "EXERCISE ONE: \n\n";
	exercise1();

	cout << "\n\nEXERCISE TWO: \n\n";
	exercise2();

	cout << "\n\nEXERCISE THREE: \n\n";
	exercise3();
	

	cout << "\n\nEXERCISE FOUR: \n\n";
	exercise4();

	cout << "\n\nEXERCISE FIVE: \n\n";
	exercise5();
}