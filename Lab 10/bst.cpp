#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

//recursive definition
template<typename T> class BinarySearchTree {
    public:
        //current node has references to: root, left child, right child, parent
        BinarySearchTree<T> *root, *left_son, *right_son, *parent;
        //current node info
        T *pinfo;

        //constructor
        BinarySearchTree() {
            left_son = right_son = NULL;
            root = this;
            pinfo = NULL;
        }

        void setInfo(T info) {
            pinfo = new T;
            *pinfo = info;
        }

        void insert(T x) {
            if (pinfo == NULL)
                setInfo(x);
            else
                insert_rec(x);
        }

        ///insert function depends on the value that we want to insert
        ///if it should be on the left / right subtree
        void insert_rec(T x) {

            int next_son;
			if (x <= (*pinfo))
                next_son = 0;
            else
                next_son = 1;

            if (next_son == 0)
            {
                if (left_son == NULL) 
                { ///left son
                    left_son = new BinarySearchTree<T>;
                    left_son->pinfo = new T;
                    *(left_son->pinfo) = x;
                    left_son->left_son = left_son->right_son = NULL;
                    left_son->parent = this;
                    left_son->root = root;
                }
                else
                    left_son->insert_rec(x);

            }
            else
            { /// right son
                if (right_son == NULL)
                {
                    right_son = new BinarySearchTree<T>;
                    right_son->pinfo = new T;
                    *(right_son->pinfo) = x;
                    right_son->left_son = right_son->right_son = NULL;
                    right_son->parent = this;
                    right_son->root = root;
                }
                else
                    right_son->insert_rec(x);
            }
        }

		BinarySearchTree<T>* find(T x) {
            BinarySearchTree<T> *rez;

            if (pinfo == NULL)
                return NULL;

            if ((*pinfo) == x)
                return this;

            if (x <= (*pinfo))
            {
                if (left_son != NULL)
                    return left_son->find(x);
                else
                    return NULL;
            }
            else
            {
                if (right_son != NULL)
                    return right_son->find(x);
                else
                    return NULL;
            }
        }

        void removeInfo(T x) {
            BinarySearchTree<T> *t = find(x);
            if (t != NULL)
                t->remove();
        }


		void remove() {
            BinarySearchTree<T> *p;
            T *paux;

            if (left_son == NULL && right_son == NULL)
            {
                if (parent == NULL)
                { /// this == root
                    delete this->pinfo;
                    root->pinfo = NULL;
                }
                else ///leaf
                {
                    if (parent->left_son == this)
                        parent->left_son = NULL;
                    else
                        parent->right_son = NULL;

                    delete this->pinfo;
                    delete this;
                }
            }
            else
            {
                if (left_son != NULL)
                {
                    p = left_son;
                    while (p->right_son != NULL)
                        p = p->right_son;
                }
                else
                { /// right_son != NULL
                    p = right_son;
                    while (p->left_son != NULL)
                        p = p->left_son;
                }
                 
                paux = p->pinfo;
                p->pinfo = this->pinfo;
                this->pinfo = paux;
                p->remove();
            }
        }

        void inOrderTraversal() {
            if (left_son != NULL)
                left_son->inOrderTraversal();

            cout<<*pinfo<<" ";

            if (right_son != NULL)
                right_son->inOrderTraversal();
        }

        void preOrderTraversal(){
            cout<<*pinfo<<" ";
            if (left_son != NULL)
                left_son->preOrderTraversal();

            if (right_son != NULL)
                right_son->preOrderTraversal();
        }

        void postOrderTraversal(){
            if (left_son != NULL){
                left_son->postOrderTraversal();}

            if (right_son != NULL){
                right_son->postOrderTraversal();}

            cout<<*pinfo<<" ";
        }

        T biggestValue() {

            if (right_son != NULL) {

                return right_son->biggestValue();
            }
            
           if (pinfo != NULL) {
               return *pinfo;
           }
            return 0;
            
        }

        
        vector<int> findMaxHeight(int h) {

            vector<int> res = { h, h };

            if (pinfo == NULL) {
                return res;
            }

            if (left_son == NULL && right_son == NULL) {
                return res;
            }

            if (left_son != NULL) {

                vector<int> temp = left_son->findMaxHeight(h + 1);
                res[0] = max(temp[0], temp[1]);
            }

            if (right_son != NULL) {

                vector<int> temp = right_son->findMaxHeight(h + 1);
                res[1] = max(temp[0], temp[1]);
            }

            return res;
        }

        void displayInBounds(int x, int y) {

            if (pinfo == NULL) {
                return;
            }
            if (*pinfo < x) {

                if (right_son != NULL) {

                    right_son->displayInBounds(x, y);
                }
            }
            else if (*pinfo > y) {
                
                if (left_son != NULL) {
                    left_son->displayInBounds(x, y);
                }
            }
            else {

                if (left_son != NULL) {

                    left_son->displayInBounds(x, y);
                }
                cout << *pinfo << " ";
                if (right_son != NULL) {
                    right_son->displayInBounds(x, y);
                }
            }
        }

        void displayByLevel(int level) {

            if (pinfo == NULL) {
                return;
            }

            if (level == 0) {

                cout << *pinfo << " ";
            }
            else {

                if (left_son != NULL) {

                    left_son->displayByLevel(level - 1);
                }

                if (right_son != NULL) {

                    right_son->displayByLevel(level - 1);
                }
            }
        }

        void displayAllLevels() {

            cout << "DISPLAYING ALL LEVELS: \n";

            int h = max(findMaxHeight(0)[0], findMaxHeight(0)[1]);
            for (int i = 0; i <= h; i++) {

                cout << "Level " << i << ": ";
                displayByLevel(i);
                cout << "\n\n";
            }
        }
};

void exerciseOne() {

    BinarySearchTree<int>* r = new BinarySearchTree<int>();

    r->insert(4);
    r->insert(2);
    r->insert(1);
    r->insert(3);
    r->insert(11);
    r->insert(7);
    r->insert(9);

    cout << "The Biggest value in our BST: " << r->biggestValue() << "\n\n";
}

void exerciseTwo() {

    BinarySearchTree<int>* r = new BinarySearchTree<int>();
    r->insert(10);
    r->insert(8);
    r->insert(12);
    r->insert(7);
    r->insert(9);
    r->insert(13);
    r->insert(11);
    r->insert(5);
    r->insert(4);
    r->insert(6);

    
    r->displayAllLevels();
    

    cout << "\n\nThe values in the range [6,8]: ";
    r->displayInBounds(6, 8);
}


template <typename T>
BinarySearchTree<T>* rotateBST(BinarySearchTree<T>* tr) {

    vector<int> v = tr->findMaxHeight(0);

    if (v[0] > v[1]) {//right rotation

        //We automatically assume left_son isn't null since
        //the height of the left subtree is bigger

        tr->root = tr->left_son;
        tr->left_son = tr->root->right_son;
        tr->root->right_son = tr;
        tr->root->root = NULL;
        return rotateBST(tr->root);
    }
    else if (v[0] < v[1]) {//left rotation

        tr->root = tr->right_son;
        tr->right_son = tr->root->left_son;
        tr->root->left_son = tr;
        tr->root->root = NULL;
        return rotateBST(tr->root);
    }

    if (tr->root == NULL) {
        return tr;
    }
    return tr->root;
}
//the goat
void exerciseThree() {

    BinarySearchTree<int>* r = new BinarySearchTree<int>();
    r->insert(10);
    r->insert(12);
    r->insert(8);
    r->insert(11);
    r->insert(13);
    r->insert(7);
    r->insert(9);
    r->insert(5);
    r->insert(4);

    r->displayAllLevels();
    cout << "\n\n";

    r = rotateBST(r);

    r->displayAllLevels();
    r->preOrderTraversal();
}

template <typename T>
T findMirrorRec(BinarySearchTree<T>* left, BinarySearchTree<T>* right, T target) {

    if (left == NULL || right == NULL) {
        return 0;
    }

    if (*(right->pinfo) == target) {
        return *(left->pinfo);
    }
    else if (*(left->pinfo) == target) {
        return *(right->pinfo);
    }

    T result_1 = findMirrorRec(left->left_son, right->right_son, target);

    if (result_1) {
        return result_1;
    }

    return findMirrorRec(left->right_son, right->left_son, target);

}

template <typename T>
T findMirror(BinarySearchTree<T>* r, T target) {

    if (r == NULL) {

        return 0;
    }

    if (*(r->pinfo) == target) {

        return target;
    }

    return findMirrorRec(r->left_son, r->right_son, target);
    
}

void bonusExercise() {

    BinarySearchTree<int>* r = new BinarySearchTree<int>();
    r->insert(10);
    r->insert(8);
    r->insert(12);
    r->insert(7);
    r->insert(9);
    r->insert(13);
    r->insert(11);

    r->displayAllLevels();


    cout << "\n\nThe mirror node of 9 is: " << findMirror(r, 9) << "\n\n";
    cout << "\n\nThe mirror node of 7 is: " << findMirror(r, 7) << "\n\n";
}


int main(){

    //cout << "EXERCISE ONE: \n\n";
    //exerciseOne();

    //cout << "EXERCISE TWO: \n\n";
    //exerciseTwo();

    //cout << "EXERCISE THREE: \n\n";
    //exerciseThree(); 

    //cout << "BONUS EXERCISE: \n\n";
    //bonusExercise(); 
}