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
            front->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode <int>* rightNode = new BinaryTreeNode <int> (rightData);
            front->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int> *root) {
    if(root==NULL) {
        return;
    }
    queue <BinaryTreeNode <int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode <int>* front = q.front();
        q.pop();
        cout << front->data << ":";
        cout << "L:";
        if(front->left == NULL) {
            cout << -1 << ",";
        }
        else {
            cout << front->left->data << ",";
            q.push(front->left);
        }
        cout << "R:";
        if(front->right == NULL) {
            cout << -1 << endl;
        }
        else {
            cout << front->right->data << endl;
            q.push(front->right);
        }
    }
    return;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    printLevelWise(root);
    return 0;
}