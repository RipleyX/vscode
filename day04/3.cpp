#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct avl {
    int key;
    int height;
    avl* lchild;
    avl* rchild;
};

int getHeight(avl* root)
{
    if (root == nullptr) {
        return 0;
    }
    return root->height;
}

void updateHeight(avl* root)
{
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalanceFactor(avl* root)
{
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void leftRotate(avl*& root)
{
    avl* B = root->rchild;
    avl* A = root;
    A->rchild = B->lchild;
    B->lchild = A;
    updateHeight(A);
    updateHeight(B);
    root = B;
}

void rightRotate(avl*& root)
{
    avl* B = root;
    avl* A = root->lchild;
    B->lchild = A->rchild;
    A->rchild = B;
    updateHeight(A);
    updateHeight(B);
    root = A;
}

void insert(avl*& root, int key)
{
    if (root == nullptr) {
        root = new avl;
        root->key = key;
        root->lchild = nullptr;
        root->rchild = nullptr;
        root->height = 1;
    } else {
        if (root->key > key) {
            insert(root->lchild, key);
            updateHeight(root);
            if (getBalanceFactor(root) == 2) {
                if (getBalanceFactor(root->lchild) == 1) { //LL
                    rightRotate(root);
                } else { //LR
                    leftRotate(root->lchild);
                    rightRotate(root);
                }
            }
        } else {
            insert(root->rchild, key);
            updateHeight(root);
            if (getBalanceFactor(root) == -2) {
                if (getBalanceFactor(root->rchild) == 1) { //RR
                    leftRotate(root);
                } else { //RL
                    rightRotate(root->rchild);
                    leftRotate(root);
                }
            }
        }
    }
}

void find(avl* root, int key)
{
    if (root == nullptr) {
        cout << "Not Found!" << endl;
        return;
    } else {
        if (root->key == key) {
            cout << "Found!" << endl;
        } else if (root->key > key) {
            find(root->lchild, key);
        } else {
            find(root->rchild, key);
        }
    }
}

avl* findPredecessor(avl* root)
{
    if (root == nullptr) {
        return root;
    } else {
        avl* ptr = root->rchild;
        while (ptr) {
            ptr = ptr->rchild;
        }
        return ptr;
    }
}

void erase(avl*& root, int key)
{
    if (root == nullptr) {
        return;
    } else {
        updateHeight(root);
    }

    if (root->key > key) {
        erase(root->lchild, key);
        if (getBalanceFactor(root) == -2) { //RR
            leftRotate(root);
        }
        //updateHeight(root);
    } else if (root->key < key) {
        erase(root->rchild, key);
        if (getBalanceFactor(root) == 2) { //LL
            rightRotate(root);
        }
        //updateHeight(root);
    } else {
        if (root->lchild == nullptr) {
            avl* ptr = root;
            root = root->rchild;
            delete ptr;
        } else if (root->rchild == nullptr) {
            avl* ptr = root;
            root = root->lchild;
            delete ptr;
        } else {
            avl* pre = findPredecessor(root);
            root->key = pre->key;
            erase(root->lchild, pre->key);
        }
        //updateHeight(root);
    }
}

void print(avl* root)
{
    if (root) {
        print(root->lchild);
        cout << root->key << " ";
        print(root->rchild);
    }
}

int main(int argc, char const* argv[])
{
    avl* avlroot = nullptr;
    string s;
    getline(cin, s);
    istringstream line(s);
    int key;
    while (line >> key) {
        insert(avlroot, key);
    }

    print(avlroot);
    cout << endl;
    cin >> key;
    find(avlroot, key);
    cin >> key;
    erase(avlroot, key);
    print(avlroot);
    cout << endl;
    system("pause");
    return 0;
}
