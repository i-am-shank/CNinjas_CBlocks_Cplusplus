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

bool search(BinaryTreeNode<int> *root, int data) {
    if(root == NULL){
        return false;
    }
    if(root->data == data) {
        root->data = INT_MIN;
        return true;
    }
    bool leftAns = search(root->left, data);
    if(leftAns == true) {
        return true;
    }
    else {
        bool rightAns = search(root->right, data);
        return rightAns;
    }
}

// Time Complexity = O(N ^ 2)
// Space Complexity = O(1)

void pairSumHelper(BinaryTreeNode<int> *node, int sum, BinaryTreeNode<int>* root) {
    if(node == NULL) {
        return;
    }
    if(node->data <= sum) {
        int a = node->data , b = sum - node->data;
        bool flag = search(root, sum-node->data); // search & destroy data.
        if(flag == true  &&  a!=b) {
            node->data = INT_MIN;
            if(a <= sum/2) {
                cout << a << " " << b << endl;
            }
            else {
                cout << b << " " << a << endl;
            }
        }
    }
    pairSumHelper(node->left, sum, root);
    pairSumHelper(node->right, sum, root);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    pairSumHelper(root, sum, root);
    return;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
    return 0;
}