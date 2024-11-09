#include <bits/stdc++.h>
using namespace std;

template<typename T>
class AVLTreeNode {
public:
    T data;
    int height;
    AVLTreeNode<T>* left;
    AVLTreeNode<T>* right;

    AVLTreeNode(T value) {
        data = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

template<typename T>
class AVLTree {
private:
    AVLTreeNode<T>* root;

    int height(AVLTreeNode<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int balanceFactor(AVLTreeNode<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    AVLTreeNode<T>* rightRotate(AVLTreeNode<T>* y) {
        AVLTreeNode<T>* x = y->left;
        AVLTreeNode<T>* z = x->right;

        x->right = y;
        y->left = z;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLTreeNode<T>* leftRotate(AVLTreeNode<T>* x) {
        AVLTreeNode<T>* y = x->right;
        AVLTreeNode<T>* z = y->left;

        y->left = x;
        x->right = z;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    AVLTreeNode<T>* insert(AVLTreeNode<T>* node, T value) {
        if (node == nullptr) {
            return new AVLTreeNode<T>(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        node->height = max(height(node->left), height(node->right)) + 1;
        int bf = balanceFactor(node);

        if (bf > 1 && value < node->left->data) {
            cout<<"1"<<endl;
            return rightRotate(node);
        }

        if (bf < -1 && value > node->right->data) {
            cout<<"2"<<endl;
            return leftRotate(node);
        }

        if (bf > 1 && value > node->left->data) {
            cout<<"3"<<endl;
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (bf < -1 && value < node->right->data) {
            cout<<"4"<<endl;
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
    AVLTreeNode<T>* deleteNode(AVLTreeNode<T>* node, T value) {
    if (node == nullptr) {
        return node;
    }

    
    if (value < node->data) {
        node->left = deleteNode(node->left, value);
    } else if (value > node->data) {
        node->right = deleteNode(node->right, value);
    } else {
        //one subtree
        if (node->left == nullptr || node->right == nullptr) {
            cout<<"1"<<endl;
            AVLTreeNode<T>* temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }

            delete temp;
        } else {
            cout<<"2"<<endl;
            //both subtree
            //right subtree smallest
            AVLTreeNode<T>* temp = node->right;

            while (temp->left != nullptr) {
                temp = temp->left;
            }

            node->data = temp->data;

            node->right = deleteNode(node->right, temp->data);
        }
    }

    if (node == nullptr) {
        return node;
    }

    node->height = max(height(node->left), height(node->right)) + 1;

    int bf = balanceFactor(node);

    if (bf > 1 && balanceFactor(node->left) >= 0) {
        cout<<"3"<<endl;
        return rightRotate(node);
    }

    if (bf > 1 && balanceFactor(node->left) < 0) {
        cout<<"4"<<endl;
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (bf < -1 && balanceFactor(node->right) <= 0) {
        cout<<"5"<<endl;
        return leftRotate(node);
    }

    if (bf < -1 && balanceFactor(node->right) > 0) {
        cout<<"6"<<endl;
        node->right = rightRotate(node->right);

        return leftRotate(node);
    }

    return node;
}


    void printInorder(AVLTreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }

        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }

public:
    AVLTree() {
        root = nullptr;
    }

    void insert(T value) {
        root = insert(root, value);
    }
    void del(T value){
        root= deleteNode(root,value);
    }
    void print() {
        printInorder(root);
        cout<<endl;
    }
};

int main() {
    AVLTree<int> tree;
    tree.insert(2);
    tree.print();
    tree.insert(9);
    tree.print();
    tree.insert(10);
    tree.print();
    tree.insert(7);
    tree.print();
    tree.insert(6);
    tree.print();
    tree.insert(11);
    tree.print();
    tree.insert(1);
    tree.print();
    tree.insert(3);
    tree.print();
    tree.insert(4);
    tree.print();
    tree.insert(0);
    tree.print();
    tree.del(9);
    tree.print();
}