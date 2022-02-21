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

// Time Complexity = O(logN)
// Space Complexity = O(logN)

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data == data) {
        vector<int>* ans = new vector <int>;
        ans->push_back(root->data);
        return ans;
    }
    if(root->data > data) {
        vector<int>* leftAns = getPath(root->left, data);
        if(leftAns != NULL) {
            leftAns->push_back(root->data);
        }
        return leftAns;
    }
    else {
        vector<int>* rightAns = getPath(root->right, data);
        if(rightAns != NULL) {
            rightAns->push_back(root->data);
        }
        return rightAns;
    }
}

void printPath(vector<int>* path) {
    for(int i=0; i<path->size(); i++) {
        cout << path->at(i) << " ";
    }
    cout << endl;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int data;
    cin >> data;
    vector<int>* path = getPath(root, data);
    printPath(path);
    delete root;
    delete path;
    return 0;
}