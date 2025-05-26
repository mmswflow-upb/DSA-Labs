#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> class BinaryTree {
public:
    T* pinfo;
    BinaryTree<T>* left_son, * right_son, * parent, * root;

    BinaryTree()
    {
        pinfo = NULL;
        left_son = right_son = parent = NULL;
        root = this;
    }

    void setInfo(T info)
    {
        pinfo = new T;
        *pinfo = info;
    }

    void setRoot(BinaryTree<T>* r)
    {
        root = r;
    }

    /// insert a new node
    void insert(T x)
    {
        ///if the tree is empty, this will be the first node
        if (pinfo == NULL)
            setInfo(x);
        ///if not, we insert it recursively
        else
            insert_rec(x);
    }

    void insert_rec(T x)
    {
        ///choose randomly if it's left or right son (0 or 1)
        int next_son = rand() % 2; /// %100 -> 0..99
        if (next_son == 0) /// left son
        {
            ///if we don't have a left son yet
            if (left_son == NULL)
            {
                left_son = new BinaryTree<T>;
                left_son->pinfo = new T;
                *(left_son->pinfo) = x;

                left_son->left_son = left_son->right_son = NULL;
                left_son->parent = this;
                left_son->root = root;
            }
            else
                left_son->insert_rec(x);
        }
        else /// right son
        {
            if (right_son == NULL) {
                right_son = new BinaryTree<T>;
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

    ///find a certain node which contains the info x
    BinaryTree<T>* find(T x)
    {
        BinaryTree<T>* rez;

        if (pinfo == NULL)//current subtree is empty
            return NULL;

        if ((*pinfo) == x)
            return this;

        ///search in the left subtree
        if (left_son != NULL)
            rez = left_son->find(x);
        else
            rez = NULL;

        if (rez != NULL)
            return rez;
        else ///if not found, search in the right subtree
            if (right_son != NULL)
                return right_son->find(x);
            else
                return NULL;
    }

    ///search for a leaf
    BinaryTree<T>* findLeaf()
    {
        if (left_son == NULL && right_son == NULL)
            return this;
        else
            if (left_son != NULL)
                return left_son->findLeaf();
            else
                return right_son->findLeaf();
    }

    ///call remove with the node that we want to delete (this)
    void remove()
    {
        BinaryTree<T>* leaf;

        /// find a leaf in this node's subtree
        /// we use it to put it in the place of the node that we delete
        leaf = findLeaf();

        ///if the current node is a leaf
        if (this == leaf)
        {
            ///we will remove the leaf
            if (parent == NULL) /// because this == root == leaf
            {
                if (this->pinfo != NULL)
                    delete this->pinfo;

                root->pinfo = NULL;
            }
            else
            {
                ///if what we remove is left son
                if (parent->left_son == this)
                    parent->left_son = NULL;
                else
                    ///if what we remove is right son
                    parent->right_son = NULL;

                delete this->pinfo;
                delete this;
            }
        }

        ///if the current node is not a leaf
        else
        {
            ///if the leaf is a left son
            if (leaf->parent->left_son == leaf)
                leaf->parent->left_son = NULL;
            else
                ///if the leaf is a right son
                leaf->parent->right_son = NULL;

            ///replace the links for the leaf
            leaf->parent = parent;
            leaf->left_son = left_son;
            leaf->right_son = right_son;

            delete this->pinfo;

            ///the info of the current node becomes the info of the leaf
            this->pinfo = leaf->pinfo;
            delete leaf;
        }
    }

    void removeInfo(T x)
    {
        BinaryTree<T>* t = find(x);
        if (t != NULL)
            t->remove();
    }

    void preOrderTraversal()
    {
        ///display, left, right
        cout << *pinfo << " ";
        if (left_son != NULL)
            left_son->preOrderTraversal();
        if (right_son != NULL)
            right_son->preOrderTraversal();
    }

    void postOrderTraversal()
    {
        ///left, right, display
        if (left_son != NULL)
            left_son->postOrderTraversal();
        if (right_son != NULL)
            right_son->postOrderTraversal();
        cout << *pinfo << " ";
    }

    void inOrderTraversal()
    {
        ///left, display, right
        if (left_son != NULL)
            left_son->inOrderTraversal();
        cout << *pinfo << " ";
        if (right_son != NULL)
            right_son->inOrderTraversal();
    }

    void preOrderTraversalLevels(int level)
    {
        int i;
        for (i = 0; i < level; i++)
            cout << "-";

        cout << *pinfo << endl;

        if (left_son != NULL)
            left_son->preOrderTraversalLevels(level + 1);
        if (right_son != NULL)
            right_son->preOrderTraversalLevels(level + 1);
    }
};

template <typename T>
vector<int> findMaxHeight(BinaryTree<T>* bt, int h) {

    vector<int> res = { h, h };

    if (bt == NULL) {
        return res;
    }

    if (bt->left_son == NULL && bt->right_son == NULL) {
        return res;
    }

    if (bt->left_son != NULL) {

        vector<int> temp = findMaxHeight(bt->left_son, h + 1);
        res[0] = max(temp[0], temp[1]);
    }

    if (bt->right_son != NULL) {

        vector<int> temp = findMaxHeight(bt->right_son, h + 1);
        res[1] = max(temp[0], temp[1]);
    }

    return res;
}

void exerciseOne_Two() {

    BinaryTree<int>* bt = new BinaryTree<int>;
    bt->setInfo(2);
    BinaryTree<int>* bt7 = new BinaryTree<int>;
    bt7->setInfo(7);
    BinaryTree<int>* bt5 = new BinaryTree<int>;
    bt5->setInfo(5);
    BinaryTree<int>* bt6 = new BinaryTree<int>;
    bt6->setInfo(6);
    BinaryTree<int>* bt2 = new BinaryTree<int>;
    bt2->setInfo(2);
    BinaryTree<int>* bt5_2 = new BinaryTree<int>;
    bt5_2->setInfo(5);
    BinaryTree<int>* bt11 = new BinaryTree<int>;
    bt11->setInfo(11);
    BinaryTree<int>* bt9 = new BinaryTree<int>;
    bt9->setInfo(9);
    BinaryTree<int>* bt4 = new BinaryTree<int>;
    bt4->setInfo(4);

    bt->left_son = bt7;
    bt->right_son = bt5;
    bt7->left_son = bt2;
    bt7->right_son = bt6;
    bt6->left_son = bt5_2;
    bt6->right_son = bt11;
    bt5->right_son = bt9;
    bt9->left_son = bt4;

    bt->preOrderTraversal();
    cout << "\n\n";
    bt->preOrderTraversalLevels(0);
    cout << "\n\n";
    vector<int> l_r = findMaxHeight(bt, 0);

    cout << "Maximum Height of our BT: " << max(l_r[0], l_r[1]) << "\n\n";

    cout << "Difference between height of left subtree and right subtree: " << abs(l_r[0] - l_r[1]) << "\n\n";
}

template <typename T>
void displayLevel(BinaryTree<typename T>* bt, int level) {

    if (level == 0) {

        cout << *bt->pinfo << " ";
        return;
    }
    if (bt->left_son != NULL) {

        displayLevel(bt->left_son, level - 1);
    }
    if (bt->right_son != NULL) {

        displayLevel(bt->right_son, level - 1);
    }
}

void  exerciseThree() {

    BinaryTree<int>* bt = new BinaryTree<int>;
    bt->setInfo(2);
    BinaryTree<int>* bt7 = new BinaryTree<int>;
    bt7->setInfo(7);
    BinaryTree<int>* bt5 = new BinaryTree<int>;
    bt5->setInfo(5);
    BinaryTree<int>* bt6 = new BinaryTree<int>;
    bt6->setInfo(6);
    BinaryTree<int>* bt2 = new BinaryTree<int>;
    bt2->setInfo(2);
    BinaryTree<int>* bt5_2 = new BinaryTree<int>;
    bt5_2->setInfo(5);
    BinaryTree<int>* bt11 = new BinaryTree<int>;
    bt11->setInfo(11);
    BinaryTree<int>* bt9 = new BinaryTree<int>;
    bt9->setInfo(9);
    BinaryTree<int>* bt4 = new BinaryTree<int>;
    bt4->setInfo(4);

    bt->left_son = bt7;
    bt->right_son = bt5;
    bt7->left_son = bt2;
    bt7->right_son = bt6;
    bt6->left_son = bt5_2;
    bt6->right_son = bt11;
    bt5->right_son = bt9;
    bt9->left_son = bt4;

    cout << "Displaying Nodes at Level 2: ";
    displayLevel(bt, 2);
    cout << "\n\n";
}

template <typename T>
void displayAllLevels(BinaryTree<T>* bt) {

    int h = max(findMaxHeight(bt, 0)[0], findMaxHeight(bt, 0)[1]);
    for (int i = 0; i <= h; i++) {

        cout << "Level " << i << ": ";
        displayLevel(bt, i);
        cout << "\n\n";
    }
}

void exerciseFour() {

    BinaryTree<int>* bt = new BinaryTree<int>;
    bt->setInfo(2);
    BinaryTree<int>* bt7 = new BinaryTree<int>;
    bt7->setInfo(7);
    BinaryTree<int>* bt5 = new BinaryTree<int>;
    bt5->setInfo(5);
    BinaryTree<int>* bt6 = new BinaryTree<int>;
    bt6->setInfo(6);
    BinaryTree<int>* bt2 = new BinaryTree<int>;
    bt2->setInfo(2);
    BinaryTree<int>* bt5_2 = new BinaryTree<int>;
    bt5_2->setInfo(5);
    BinaryTree<int>* bt11 = new BinaryTree<int>;
    bt11->setInfo(11);
    BinaryTree<int>* bt9 = new BinaryTree<int>;
    bt9->setInfo(9);
    BinaryTree<int>* bt4 = new BinaryTree<int>;
    bt4->setInfo(4);

    bt->left_son = bt7;
    bt->right_son = bt5;
    bt7->left_son = bt2;
    bt7->right_son = bt6;
    bt6->left_son = bt5_2;
    bt6->right_son = bt11;
    bt5->right_son = bt9;
    bt9->left_son = bt4;

    bt->preOrderTraversalLevels(0);


    displayAllLevels(bt);
}


template <typename T>
BinaryTree<T>* find_LCA(BinaryTree<T>* bt, BinaryTree<T>* x, BinaryTree<T>* y) {

    if (bt == NULL || bt == x || bt == y) {
        return bt;
    }

    BinaryTree<T>* left = find_LCA(bt->left_son, x, y);
    BinaryTree<T>* right = find_LCA(bt->right_son, x, y);

    if (left == NULL) {
        return right;
    }
    else if (right == NULL) {
        return left;
    }
    else {
        return bt;
    }

}

void bonusExercise() {

    BinaryTree<int>* bt = new BinaryTree<int>;
    bt->setInfo(44);
    BinaryTree<int>* bt7 = new BinaryTree<int>;
    bt7->setInfo(7);
    BinaryTree<int>* bt5 = new BinaryTree<int>;
    bt5->setInfo(5);
    BinaryTree<int>* bt6 = new BinaryTree<int>;
    bt6->setInfo(6);
    BinaryTree<int>* bt2 = new BinaryTree<int>;
    bt2->setInfo(2);
    BinaryTree<int>* bt22 = new BinaryTree<int>;
    bt22->setInfo(22);
    BinaryTree<int>* bt11 = new BinaryTree<int>;
    bt11->setInfo(11);
    BinaryTree<int>* bt9 = new BinaryTree<int>;
    bt9->setInfo(9);
    BinaryTree<int>* bt4 = new BinaryTree<int>;
    bt4->setInfo(4);

    bt->left_son = bt7;
    bt->right_son = bt5;
    bt7->left_son = bt2;
    bt7->right_son = bt6;
    bt6->left_son = bt22;
    bt6->right_son = bt11;
    bt5->right_son = bt9;
    bt9->left_son = bt4;

    BinaryTree<int>* lca = find_LCA(bt, bt->find(2), bt->find(22));

    if (lca) {
        cout << "Lowest Common Ancestor of 2 & 22: " << *lca->pinfo << "\n\n";
    }

    BinaryTree<int>* lca2 = find_LCA(bt, bt->find(11), bt->find(4));
    if (lca2) {
        cout << "Lowest Common Ancestor of 11 & 4: " << *lca2->pinfo << "\n\n";
    }
}

int main() {

    //cout << "EXERCISE ONE & EXERCISE TWO: \n\n";
    //exerciseOne_Two();

    //cout << "EXERCISE THREE: \n\n";
    //exerciseThree();

    //cout << "EXERCISE FOUR: \n\n";
    //exerciseFour();

    cout << "BONUS EXERCISE: \n\n";
    bonusExercise();
}