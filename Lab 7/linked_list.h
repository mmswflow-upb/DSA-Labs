#include <iostream>
using namespace std;

template<typename T> struct list_elem {
    T info;
    struct list_elem<T>* next, * prev;

    list_elem<T>() {

    }
};

template <typename T> class LinkedList {
public:
    struct list_elem<T>* pfirst, * plast;

    void addFirst(T x) {

        struct list_elem<T>* paux;

        paux = new struct list_elem<T>;
        paux->info = x;
        paux->prev = NULL;
        paux->next = pfirst;

        if (pfirst != NULL) pfirst->prev = paux;
        pfirst = paux;

        if (plast == NULL) plast = pfirst;
    }

    void addLast(T x) {
        struct list_elem<T>* paux;

        paux = new struct list_elem<T>;
        paux->info = x;
        paux->prev = plast;
        paux->next = NULL;

        if (plast != NULL) plast->next = paux;
        plast = paux;
        if (pfirst == NULL) pfirst = plast;
    }

    void removeFirst() {
        struct list_elem<T>* paux;

        if (pfirst != NULL) {
            paux = pfirst->next;
            if (pfirst == plast) plast = NULL;
            delete pfirst;
            pfirst = paux;
            if (pfirst != NULL) pfirst->prev = NULL;
        }
        else cout << "The list is empty" << endl;
    }

    void removeLast() {
        struct list_elem<T>* paux;

        if (plast != NULL) {
            paux = plast->prev;
            if (pfirst == plast) pfirst = NULL;
            delete plast;
            plast = paux;
            if (plast != NULL) plast->next = NULL;
        }
        else cout << "The list is empty" << endl;
    }

    struct list_elem<T>* findFirstOccurrence(T x) {
        struct list_elem<T>* paux;

        paux = pfirst;
        while (paux != NULL) {
            if (paux->info == x)
                return paux;
            paux = paux->next;
        }
        return NULL;
    }

    struct list_elem<T>* findLastOccurrence(T x) {
        struct list_elem<T>* paux;

        paux = plast;
        while (paux != NULL) {
            if (paux->info == x)
                return paux;
            paux = paux->prev;
        }

        return NULL;
    }

    void removeFirstOccurrence(T x) {
        struct list_elem<T>* px;

        px = findFirstOccurrence(x);

        if (px != NULL) {
            if (px->prev != NULL)
                px->prev->next = px->next;
            if (px->next != NULL)
                px->next->prev = px->prev;

            if (px->prev == NULL) // px == pfirst
                pfirst = px->next;

            if (px->next == NULL) // px == plast
                plast = px->prev;

            delete px;
        }
    }

    void removeLastOccurrence(T x) {
        struct list_elem<T>* px;

        px = findLastOccurrence(x);

        if (px != NULL) {
            if (px->prev != NULL)
                px->prev->next = px->next;
            if (px->next != NULL)
                px->next->prev = px->prev;

            if (px->prev == NULL) // px == pfirst
                pfirst = px->next;

            if (px->next == NULL) // px == plast
                plast = px->prev;

            delete px;
        }
    }

    int isEmpty() {
        return (pfirst == NULL);
    }

    LinkedList() {
        pfirst = plast = NULL;
    }

    void reversePrintList() {

        cout << "\nPrinting Linked List in Reverse Order\n";

        struct list_elem<T>* p;

        p = plast;

        while (p != NULL) {

            cout << p->info << " ";
            p = p->prev;
        }
        cout << "\n";

    }

    void printList()
    {
        cout << "\n\nPrinting Linked List: ";

        struct list_elem<T>* p;

        p = pfirst;
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
        cout << "\n";
    }

    LinkedList<T> getOddList() {
        LinkedList<T> oddList;
        struct list_elem<T>* p = pfirst;

        while (p != NULL) {
            if (p->info % 2 == 1) {
                oddList.addLast(p->info);
            }
            p = p->next;
        }

        return oddList;
    }

    LinkedList<T> getEvenList() {
        LinkedList<T> evenList;
        struct list_elem<T>* p = pfirst;

        while (p != NULL) {
            if (p->info % 2 == 0) {
                evenList.addLast(p->info);
            }
            p = p->next;
        }

        return evenList;
    }
};