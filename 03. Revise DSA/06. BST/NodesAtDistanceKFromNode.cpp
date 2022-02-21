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

template <typename T>
class Node {
    public:
    T data;
    Node <T>* next;
    Node (T data) {
        this->data = data;
        next = NULL;
    }
    ~Node () {
        delete next;
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

// TIme Complexity = O(logN)
// Space Complexity = O(logN)

void printAtDepthK(BinaryTreeNode <int>* root, int k) {
    if(root == NULL) {
        return;
    }
    if(k == 0) {
        cout << root->data << endl;
        return;
    }
    printAtDepthK(root->left, k-1);
    printAtDepthK(root->right, k-1);
    return;
}

int nodesDistanceKhelp(BinaryTreeNode<int>* root, int node, int k) {
    if(root == NULL) {
        return -1;  // node not found
    }
    if(root->data == node) {  // most simple situation.
        printAtDepthK(root, k);
        return 0;
    }
    int lD = nodesDistanceKhelp(root->left, node, k);
    if(lD != -1) {  // node found.. now conditions over its depth
        if(lD + 1 == k) {
            cout << root->data << endl;
        }
        else {
            printAtDepthK(root->right, k-1-(lD+1));
        }
        return (lD + 1);
    }
    int rD = nodesDistanceKhelp(root->right, node, k);
    if(rD != -1) {
        if(rD + 1 == k) {  // Depth from root is exactly (k-1) .. so print root.
            cout << root->data << endl;
        }
        else {  // Depth is something else, also search on left sub-tree.
            printAtDepthK(root->left, k-1-(rD+1));
        }
        return (rD + 1);
    }
    return -1;  // Node not found
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    int depth = nodesDistanceKhelp(root, node, k);
    return;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int node, k;
    cin >> node >> k;
    nodesAtDistanceK(root, node, k);
    delete root;
    return 0;
}