// Time Complexity = O(N)
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
    queue <BinaryTreeNode <int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        BinaryTreeNode <int>* front = pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        cin >> leftData;
        if(leftData != -1) {
            BinaryTreeNode <int>* left = new BinaryTreeNode <int> (leftData);
            front->left = left;
            pendingNodes.push(left);
        }
        int rightData;
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode <int>* right = new BinaryTreeNode <int> (rightData);
            front->right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        return;
    }
    queue <BinaryTreeNode <int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if(front->left != NULL) {
            cout << "L:" << front->left->data;
            pendingNodes.push(front->left);
        }
        else {
            cout << "L:-1";
        }
        cout << ",";
        if(front->right != NULL) {
            cout << "R:" << front->right->data;
            pendingNodes.push(front->right);
        }
        else {
            cout << "R:-1";
        }
        cout << endl;
    }
    return;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    printLevelWise(root);
    delete root;
    return 0;
}