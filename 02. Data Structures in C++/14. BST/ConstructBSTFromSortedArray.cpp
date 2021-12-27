// Time Complexity = O(logN)
// Space Complexity = O(logN)


#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode <T>* left;
    BinaryTreeNode <T>* right;

    BinaryTreeNode (int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void preOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
    if(n==0) {
        return NULL;
    }
    int mid = (n-1) / 2;
    int rootData = input[mid];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int> (rootData);
    BinaryTreeNode<int>* leftTree = constructTree(input, mid);
    BinaryTreeNode<int>* rightTree = constructTree(input+mid+1, n-mid-1);
    root->left = leftTree;
    root->right = rightTree;
    return root;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    BinaryTreeNode<int>* root = constructTree(arr, n);
    preOrder(root);
    return 0;
}