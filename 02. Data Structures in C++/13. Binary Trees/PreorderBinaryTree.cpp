// Time Complexity = O(N)
// Space Complexity = O(1)


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

void preOrder(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    preOrder(root);
    delete root;
    return 0;
}