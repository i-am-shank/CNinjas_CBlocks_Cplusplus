// Time Complexity = O(logN) ..or.. O(h)
// Space Complexity = O(1)


#include <iostream>
#include <queue>
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

BinaryTreeNode <int>* takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode <int>* root = new BinaryTreeNode<int> (rootData);
    queue <BinaryTreeNode <int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode <int>* front = q.front();
        q.pop();
        int leftData, rightData;
        cin >> leftData;
        if(leftData != -1) {
            BinaryTreeNode <int>* leftNode = new BinaryTreeNode <int>(leftData);
            front->left = leftNode;
            q.push(front->left);
        }
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode <int>* rightNode = new BinaryTreeNode <int>(rightData);
            front->right = rightNode;
            q.push(front->right);
        }
    }
    return root;
}

bool searchInBST(BinaryTreeNode<int> *root , int k) {
    if(root == NULL) {
        return false;
    }
    if(root->data == k) {
        return true;
    }
    else if(root->data < k) {
        return searchInBST(root->right, k);
    }
    else {
        return searchInBST(root->left, k);
    }
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int k;
    cin >> k;
    bool ans = searchInBST(root, k);
    if(ans == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}