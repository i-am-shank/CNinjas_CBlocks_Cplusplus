// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode <int>* left;
    BinaryTreeNode <int>* right;

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
    BinaryTreeNode <int>* root = new BinaryTreeNode <int> (rootData);
    queue <BinaryTreeNode <int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode <int>* front = q.front();
        q.pop();
        int leftData, rightData;
        cin >> leftData;
        if(leftData != -1) {
            BinaryTreeNode <int>* leftNode = new BinaryTreeNode <int> (leftData);
            q.push(leftNode);
            front->left = leftNode;
        }
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode <int>* rightNode = new BinaryTreeNode <int> (rightData);
            q.push(rightNode);
            front->right = rightNode;
        }
    }
    return root;
}

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if(root == NULL) {
        return false;
    }
    if(root->data == x) {
        return true;
    }
    bool leftAns = isNodePresent(root->left, x);
    bool rightAns = isNodePresent(root->right, x);
    if(leftAns==true || rightAns==true) {
        return true;
    }
    return false;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int x;
    cin >> x;
    bool ans = isNodePresent(root, x);
    if(ans) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}