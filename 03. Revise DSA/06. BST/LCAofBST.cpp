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

// Time Complexity = O(N)  ..  slightly better time complexity than LCA of Binary tree
// Space Complexity = O(logN)

int getLCA(BinaryTreeNode<int>* root , int val1 , int val2) {
    if(root == NULL) {
        return -1;
    }
    if(root->data == val1  ||  root->data == val2) {
        return root->data;
    }
    if(root->data > val1  &&  root->data > val2) {
        return getLCA(root->left, val1, val2);
    }
    else if(root->data < val1  &&  root->data < val2) {
        return getLCA(root->right, val1, val2);
    }
    else {
        int leftLCA = getLCA(root->left, val1, val2);
        int rightLCA = getLCA(root->right, val1, val2);
        if(leftLCA != -1  &&  rightLCA == -1) {  // none on right sub-tree.
            return leftLCA;
        }
        else if(leftLCA == -1  &&  rightLCA != -1) {  // none on left sub-tree.
            return rightLCA;
        }
        else if(leftLCA == -1  &&  rightLCA == -1) {  // none on both sub-trees.
            return -1;
        }
        else {  // both sub-trees have something.
            return root->data;
        }
    }
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    int ans = getLCA(root, a, b);
    cout << ans << endl;
    delete root;
    return 0;
}