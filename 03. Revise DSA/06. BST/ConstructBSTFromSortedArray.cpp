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
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode () {
        delete left;
        delete right;
    }
};

// Time Complexity = O(logN)
// Time Complexity = O(logN)

BinaryTreeNode<int>* constructTree(int *input, int n) {
    if(n == 0) {
        return NULL;
    }
    int rootData = input[(n-1) / 2];
    BinaryTreeNode <int>* root = new BinaryTreeNode <int> (rootData);
    BinaryTreeNode <int>* leftNode = constructTree(input, (n-1)/2);
    BinaryTreeNode <int>* rightNode = constructTree(input+((n+1)/2), n/2);
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

void preOrder(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    BinaryTreeNode <int>* root = constructTree(arr, n);
    preOrder(root);
    delete root;
    delete []arr;
    return 0;
}