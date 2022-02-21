#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode <int>* left;
    BinaryTreeNode <int>* right;
    BinaryTreeNode (T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode () {
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
    BinaryTreeNode <int>* left = takeInput();
    root->left = left;
    BinaryTreeNode <int>* right = takeInput();
    root->right = right;
    return root;
}

void printTree(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << ":";
    if(root->left != NULL) {
        cout << "L:" << root->left->data;
    }
    else {
        cout << "L:-1";
    }
    cout << ",";
    if(root->right != NULL) {
        cout << "R:" << root->right->data;
    }
    else {
        cout << "R:-1";
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    printTree(root);
    delete root;
    return 0;
}