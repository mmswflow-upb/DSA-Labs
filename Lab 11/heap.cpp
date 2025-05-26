#include <iostream>
#include <queue>

using namespace std;

template<typename T> class Heap
{
public:

    T *H;
    int currentDim, maxDim;

    Heap(int maxDim)
    {
        this->maxDim = maxDim;
        H = new T[this->maxDim];
        currentDim = -1;
    }

    Heap(int maxD, T* arr) {

        this->maxDim = maxD;
        H = new T[this->maxDim];
        currentDim = -1;
        for (int i = 0; i < maxDim; i++) {

            this->insertElement(arr[i]); 
        }
    }

    void insertElement(T x)
    {
        if (currentDim == maxDim-1)
        {
            cout<< "Error!"<<endl;
            return;
        }
        currentDim++;
        H[currentDim] = x;
        filterUp(currentDim);
    }

    T peek()
    {
        if (currentDim == -1)
        {
            cout<< "Error!"<<endl;
            T *x = new T;
            return *x;
        }

        return H[0];
    }

    T deleteElement()
    {
        if (currentDim == -1)
        {
            cout<< "Error!"<<endl;
            T *x = new T;
            return *x;
        }

        T minValue = H[0];
        H[0] = H[currentDim];
        currentDim--;

        if (currentDim > 0)
            filterDown();

        return minValue;
    }

    void filterUp(int i)
    {
        int parent;
        T vaux;

        parent = (i-1) / 2;

        while (i > 0 && H[parent] > H[i])
        {
            vaux = H[parent];
            H[parent] = H[i];
            H[i] = vaux;

            i = parent;
            parent = (i-1) / 2;
        }
    }

    void filterDown()
    {
        int i = 0;
        T vaux;

        while (1) 
        {
            if (2 * (i + 1) > currentDim)//Check if right child exists in array
            {
                if (2 * i + 1 > currentDim)//Check if left child exists in array
                    break;//Both don't exist
                else if (H[2 * i + 1] < H[i])//left child exists, we check if its smaller than the root
                {//left child is smaller, so we switch root with left child.
                    vaux = H[2 * i + 1];
                    H[2 * i + 1] = H[i];
                    H[i] = vaux;
                    i = 2 * i + 1;//new left child is old root
                }
                else
                    break;//right child doesn't exist and left child is not smaller than root
            }   
            else//Right child exists in array(automatically assume left one exists too)
            {
                if (H[2 * (i+1) ] <= H[2 * i + 1] && H[2 * (i+1) ] < H[i])
                {//Right child is smaller than root and left child is bigger or equal to right child
                    vaux = H[2 * (i+1)];
                    H[2 * (i+1)] = H[i];
                    H[i] = vaux;
                    i = 2 * (i+1);
                }
                else if (H[2 * i + 1] <= H[2 * (i+1)] && H[2 * i + 1] < H[i])
                {//Left child is smaller than root and right child is bigger or equal to left child
                    vaux = H[2 * i + 1];
                    H[2 * i + 1] = H[i];
                    H[i] = vaux;
                    i = 2 * i + 1;
                }
                else
                    break;//Left child and right child are bigger than root
            }
        }
    }

    void printHeap() {

        for (int i = 0; i <= currentDim; i++) {

            cout << H[i] << " ";
        }
    }

    void printByLevels() {
        
      
        int level = 0;

        for (int i = 0; i <= currentDim; i = i * 2 + 1) {

            cout << "\n\nLevel " << level << ": ";

            for (int v = i; v <= currentDim && v <= 2*i; v++) {
                cout << H[v] << " ";
            }
        }
    }

    T maxElem() {

        T maxElem = H[(currentDim+1)/ 2];
        
        for (int i = 1 + (currentDim/ 2); i <= currentDim; ++i){

            if (maxElem < H[i]) {

                maxElem = H[i];
            }
        }
        return maxElem;
    }
    
};

void exerciseTwo_Three() {

    //EXERCISE TWO: 
    Heap<int> h(10);

    h.insertElement(1);
    h.insertElement(2);
    h.insertElement(3);
    h.insertElement(17);
    h.insertElement(17);
    h.insertElement(19);
    h.insertElement(25);
    h.insertElement(36);
    h.insertElement(100);
   

    cout << "The first element in the heap is: " << h.peek() << "\n\n";

    //EXERCISE TWO QUESTION SOLUTION: 
    //The formulas will change to: parent(CI) = CI/2
    //RightChild(CI) = 2* (CI) + 1
    //Left Child (CI) 2 * (CI)


    //EXERCISE THREE:
    cout << "\n\nDisplaying heap by levels: ";
    h.printByLevels();

    h.deleteElement();
    h.deleteElement();
    h.deleteElement();

    cout << "\n\nDisplaying heap by levels after deleting 3 elements: ";
    h.printByLevels();
}

template <typename T>
void heapSort(int size, T* arr) {

    Heap<T> h(size, arr);

    int min;

    for (int i = size - 1; i >= 0; i--) {

        min = h.deleteElement();
        arr[i] = min;
    }

}

void exerciseFour() {

    //Testing the heap sort method.

    int s = 0;

    cout << "Insert a size: ";
    cin >> s;

    int *a = new int[s];
   
    cout << "\n\nInsert the numbers separated by space: ";

    for (int i = 0; i < s; i++) {
        cin >> a[i];
    }

    heapSort(9, a);

    cout << "\n\nDisplaying sorted array: ";

    for (int i = 0; i < 9; i++) {

        cout << a[i] << " ";
    }

}

void extraExercise() {

    //Testing the implementation of maxElem method in heap class 
    //for finding the largest value in a min heap

    Heap<char> h(9);
    h.insertElement('a');
    h.insertElement('e');
    h.insertElement('c');
    h.insertElement('x');
    h.insertElement('k');
    h.insertElement('m');
    h.insertElement('l');
    h.insertElement('p');
    
    h.insertElement('s');
    
    
    cout << "\n\nMax Element in Heap: " << h.maxElem() << "\n\n";
}

int main() {

   cout << "\n\nEXERCISE ONE & TWO & THREE: \n\n";
   exerciseTwo_Three();

    //cout << "\n\nEXERCISE FOUR: \n\n";
    //exerciseFour();


   //cout << "\n\nEXTRA EXERCISE: \n\n";
   //extraExercise();

}