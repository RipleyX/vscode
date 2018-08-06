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
        if (root->key > key) { //值小于当前节点则在左子树插入
            insert(root->lchild, key);
            updateHeight(root); //插入操作后更新高度
            if (getBalanceFactor(root) == 2) { //平衡调整
                if (getBalanceFactor(root->lchild) == 1) { //LL
                    rightRotate(root);
                } else { //LR
                    leftRotate(root->lchild);
                    rightRotate(root);
                }
            }
        } else { //值大于当前节点则在右子树插入
            insert(root->rchild, key);
            updateHeight(root); //插入操作后更新高度
            if (getBalanceFactor(root) == -2) { //平衡调整
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
        } else if (root->key > key) { //值小于当前节点则在左子树查找
            find(root->lchild, key);
        } else {
            find(root->rchild, key); //值大于当前节点则在右子树查找
        }
    }
}

avl* findPredecessor(avl* root) //查找直接前驱
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
        updateHeight(root); //每次执行删除操作后在父节点处更新高度
    }

    if (root->key > key) { //左右子树执行删除操作后只可能产生RR or LL
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
        if (root->lchild == nullptr) { //有一个子树为空，另一个子树替代当前结点
            avl* ptr = root;
            root = root->rchild;
            delete ptr;
        } else if (root->rchild == nullptr) {
            avl* ptr = root;
            root = root->lchild;
            delete ptr;
        } else { //子树均非空则直接前驱替代当前结点，并循环删除直接前驱
            avl* pre = findPredecessor(root);
            root->key = pre->key;
            erase(root->lchild, pre->key);
        }
        //updateHeight(root);
    }
}

void print(avl* root) //中序遍历
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
