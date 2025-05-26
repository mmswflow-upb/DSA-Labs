#include <iostream>
using namespace std;

template<typename T> struct clist_elem {
	T info;
	struct clist_elem<T>* next, * prev;
};

template<typename T> 
class CircularLinkedList {

private: 
	 
	int size;
	struct clist_elem<T>* head;

public:

	CircularLinkedList() {
		head = nullptr;
		size = 0;
	}

	~CircularLinkedList() {
		
		while (!isEmpty()) {
			removeFirst();
		}
	}

	bool isEmpty() {

		return (head == nullptr);
	}

	void addFirst(T x) {

		size++;

		struct clist_elem<T>* elemX = new struct clist_elem<T>;
		elemX->info = x;
		
		if (!isEmpty()) {

			elemX->prev = head->prev;
			elemX->next = head;
			head->prev = elemX;
			head = elemX;
			head->prev->next = head;
			return;
		}

		head = elemX;
		head->prev = head;
		head->next = head;
	}

	void addLast(T x) {
		
		
	
		if (isEmpty()) {
			
			addFirst(x);
			return;
		}

		size++;

		struct clist_elem<T>* elemX = new struct clist_elem<T>;

		elemX->info = x;
		elemX->next = head;

		struct clist_elem<T>* tail = head->prev;

		elemX->prev = tail;
		head->prev = elemX;
		tail->next = elemX;
	}

	void removeFirst() {

		if (!isEmpty()) {

			size--;

			if (head->next == head) {

				cout << "\nRemoving Last Element in Circular Linked List.\n";

				delete head;
				head = nullptr;
				return;
			}

			cout << "\nRemoving Head From Circular Linked List.\n";

			struct clist_elem<T>* tail = head->prev;
			struct clist_elem<T>* newHead = head->next;
			struct clist_elem<T>* oldHead = head;
			
			head = newHead;
			tail->next = head;
			head->prev = tail;
			

			delete oldHead;
			return;
		}

		cout << "\nCircular Linked List is Empty.\n";

	}

	void removeLast() {

		if (!isEmpty()) {

			size--;

			if (head->next == head) {
				
				cout << "\nRemoving Last Element in Circular Linked List.\n";

				delete head;
				head = nullptr;
				return;
			}

			
			cout << "\nRemoving Tail From Circular Linked List.\n";

			struct clist_elem<T>* tail = head->prev;
			struct clist_elem<T>* newTail = tail->prev;

			head->prev = newTail;
			newTail->next = head;
			delete tail;

			return;
		}

		cout << "\nCircular Linked List is Empty.\n";

	}

	struct clist_elem<T>* findFirstOccurence(T x) {

		if (!isEmpty()) {

			struct clist_elem<T>* aux = head;
			struct clist_elem<T>* fOcc = nullptr;

			do {

				if (aux->info == x) {
					fOcc = aux;
					break;
				}

				aux = aux->next;

			} while (aux != head);
				
			

			if (fOcc == nullptr) {

				cout << "\nNo Occurence Found.\n";
				return nullptr;
			}

			return fOcc;
		}

		cout << "\nCircular Linked List is Empty.\n";
		return nullptr;

	}

	struct clist_elem<T>* findLastOccurence(T x) {
		
		if (!isEmpty()) {

			struct clist_elem<T>* aux = head;
			struct clist_elem<T>* lastOcc = nullptr;

			do {

				if (aux->info == x) {

					lastOcc = aux;
				}

				aux = aux->next;

			} while (aux != head);

			if (lastOcc == nullptr){

				cout << "\nNo Occurence Found.\n";
				return nullptr;
			}

			return lastOcc;
		}

		cout << "\nCircular Linked List is Empty.\n";
		return NULL;

	}

	void removeFirstOccurence(T x) {

		struct clist_elem<T>* elm = findFirstOccurence(x);

		if (elm != nullptr) {

			if (elm == head) {

				removeFirst();
				return;
			}

			size--;

			cout << "\nRemoving First Occurence of [" << x << "] from Circular Linked List\n";

			struct clist_elem<T>* p = elm->prev;
			struct clist_elem<T>* n = elm->next;

			delete elm;
			p->next = n;
			n->prev = p;

		}
		else {
			cout << "\nNo Occurence Found to Be Removed.\n";
		}

	}

	void removeLastOccurence(T x) {

		struct clist_elem<T>* elm = findLastOccurence(x);

		if (elm != nullptr) {

			if (elm == head) {
				removeFirst();
				return;
			}

			size--;
			cout << "\nRemoving Last Occurence of [" << x << "] from Circular Linked List\n";
			struct clist_elem<T>* p = elm->prev;
			struct clist_elem<T>* n = elm->next;

			delete elm;
			p->next = n;
			n->prev = p;

		}
		else {
			cout << "\nNo Occurence Found to Be Removed.\n";
		}

	}

	void printList() {

		if (!isEmpty()) {

			cout << "\nPrinting the Circular Linked List: ";

			struct clist_elem<T>* aux = head;

			do {

				cout << aux->info << " ";
				aux = aux->next;
			}while (aux != head);
			cout << "\n";
			return;
		}

		cout << "\nCircular Linked List is Empty.\n";
	}

	CircularLinkedList<T> frontHalf() {

		CircularLinkedList<T> fhCLL;

		if (isEmpty()) {

			cout << "\nCircular Linked List Is Empty.\n";
			return fhCLL;
		}

		struct clist_elem<T>* aux = head;

		for (int i = 0; i < ceil(size%2) + (size / 2); i++) {

			fhCLL.addLast(aux->info);
			aux = aux->next;
		}
		return fhCLL;
	}

	CircularLinkedList<T> backHalf() {

		CircularLinkedList<T> bhCLL;

		if (isEmpty()) {

			cout << "\nCircular Linked List Is Empty.\n";
			return bhCLL;
		}
		else if (size == 1) {

			bhCLL.addFirst(head->info);
			return bhCLL;
		}

		struct clist_elem<T>* aux = head->prev;
		
		for (int i = size; i > ( (size / 2) + ceil(size%2)); i--) {

			bhCLL.addFirst(aux->info);
			aux = aux->prev;
		}
		return bhCLL;
	}
};