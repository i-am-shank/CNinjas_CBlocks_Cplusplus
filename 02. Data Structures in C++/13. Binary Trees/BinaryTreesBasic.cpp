#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode <T>* left;
    BinaryTreeNode <T>* right;

    BinaryTreeNode (T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

BinaryTreeNode <int>* takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode <int>* root = new BinaryTreeNode <int> (rootData);
    BinaryTreeNode <int>* leftChild = takeInput();
    BinaryTreeNode <int>* righChild = takeInput();
    root->left = leftChild;
    root->right = righChild;
    return root;
}

void printBinaryTree(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << ":";
    if(root->left != NULL) {
        cout << "L" << root->left->data;
    }
    if(root->right != NULL) {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
    return;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    printBinaryTree(root);
    return 0;
}