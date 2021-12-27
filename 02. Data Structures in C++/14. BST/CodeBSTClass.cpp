#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTreeNode () {
        delete left;
        delete right;
    }
};

class BST {
    BinaryTreeNode<int>* root;

    public:
    BST() {
        this->root = NULL;
    }
    ~BST() {
        delete root;
    }

    // Time Complexity = O(logN)
    // Space Complexity = O(1)

    private:

    BinaryTreeNode<int>* removePrivate(int data, BinaryTreeNode<int>* node) {
        if(node == NULL) {
            return root;
        }
        if(node->data == data) {
            if(node->left==NULL && node->right==NULL) {
                delete node;
                return NULL;
            }
            else if(node->left==NULL && node->right!=NULL) {
                BinaryTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if(node->left!=NULL && node->right==NULL) {
                BinaryTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else {
                BinaryTreeNode <int>* minNode = node->right;
                while(minNode->left != NULL) {
                    minNode = minNode->left;
                }
                int minData = minNode->data;
                node->data = minData;
                node->right = removePrivate(minData, node->right);
                return node;
            }
        }
        else if(node->data < data) {
            node->right = removePrivate(data, node->right);
            return node;
        }
        else {
            node->left = removePrivate(data, node->left);
            return node;
        }
    }

    public:
    void remove(int data) {
        root = removePrivate(data, root);
        return;
    }

    // Time Complexity = O(N)
    // Space Complexity = O(1)

    private:
    void printPrivate(BinaryTreeNode<int>* node) {
        if(node == NULL) {
            return;
        }
        cout << node->data << ":";
        if(node->left != NULL) {
            cout << "L:" << node->left->data << ",";
        }
        if(node->right != NULL) {
            cout << "R:" << node->right->data;
        }
        cout << endl;
        printPrivate(node->left);
        printPrivate(node->right);
    }

    public:
    void print() {
        printPrivate(root);
    }

    // Time Complexity = O(logN)
    // Space Complexity = O(1)

    private:
    BinaryTreeNode<int>* insertPrivate(int data, BinaryTreeNode<int>* node) {
        if(node == NULL) {
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int> (data);
            return newNode;
        }
        if(node->data >= data) {
            node->left = insertPrivate(data, node->left);
        }
        else {
            node->right = insertPrivate(data, node->right);
        }
        return node;
    }

    public:
    void insert(int data) {
        this->root = insertPrivate(data, root);
        return;
    }

    // Time Complexity = O(logN)
    // Space Complexity = O(1)

    private:
    bool searchPrivate(int data, BinaryTreeNode<int>* node) {
        if(node == NULL) {
            return false;
        }
        if(node->data == data) {
            return true;
        }
        else if(node->data > data) {
            return searchPrivate(data, node->left);
        }
        else {
            return searchPrivate(data, node->right);
        }
    }

    public:
    bool search(int data) {
        return searchPrivate(data, root);
    }
};


int main() {
    BST* b = new BST();
    b->insert(80);
    b->insert(40);
    b->insert(120);
    b->insert(20);
    b->insert(60);
    b->insert(100);
    b->insert(140);
    b->insert(90);
    b->insert(115);

    b->print();
    cout << b->search(60) << endl;
    b->insert(110);
    b->insert(120);
    b->print();
    return 0;
}