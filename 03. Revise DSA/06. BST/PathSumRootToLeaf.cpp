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

// Time Complexity = O(logN * logN)
//     .. O(logN) is finding path, & in each, printing it is also O(logN).
// Space Complexity = O(logN)

void printVector(vector<int>* v) {
    for(int i=0; i<v->size(); i++) {
        cout << v->at(i) << " ";
    }
    cout << endl;
    return;
}

void rootToLeafPathHelp(BinaryTreeNode<int>* root, int k, vector<int>* v, int sum) {
    if(root == NULL) {
        return;
    }
    v->push_back(root->data);
    sum += root->data;
    if(root->left==NULL && root->right==NULL) {
        if(sum == k) {
            printVector(v);
        }
        v->pop_back();
        return;
    }
    rootToLeafPathHelp(root->left, k, v, sum);
    rootToLeafPathHelp(root->right, k, v, sum);
    v->pop_back();
    return;
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    vector<int>* v = new vector<int>;
    rootToLeafPathHelp(root, k, v, 0);
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
    return 0;
}