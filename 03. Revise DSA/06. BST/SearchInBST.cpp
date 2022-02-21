#include <iostream>
#include <queue>
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

BinaryTreeNode <int>* takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode <int>* root = new BinaryTreeNode <int> (rootData);
    queue <BinaryTreeNode <int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode <int>* front= q.front();
        q.pop();
        int leftData, rightData;
        cin >> leftData;
        if(leftData != -1) {
            BinaryTreeNode <int>* leftNode = new BinaryTreeNode <int> (leftData);
            front->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightData;
        if(rightData != -1){
            BinaryTreeNode <int>* rightNode = new BinaryTreeNode <int> (rightData);
            front->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

// Time Complexity = O(logN)
// Space Complexity = O(1)

bool searchInBST(BinaryTreeNode<int> *root , int k) {
    if(root == NULL) {
        return false;
    }
    if(root->data == k) {
        return true;
    }
    else if(root->data > k) {
        return searchInBST(root->left, k);
    }
    else {
        return searchInBST(root->right, k);
    }
}

int main () {
    BinaryTreeNode <int>* root = takeInput();
    int k;
    cin >> k;
    bool ans = searchInBST(root, k);
    cout << (ans == true ? "true" : "false") << endl;
    delete root;
    return 0;
}