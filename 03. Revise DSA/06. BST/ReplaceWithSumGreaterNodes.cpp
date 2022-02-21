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
// Space Complexity = O(1)

int replaceLargerNodesSum(BinaryTreeNode<int>* root, int sum) {
    if(root == NULL) {
        return sum;
    }
    sum = replaceLargerNodesSum(root->right, sum);
    sum += root->data;
    root->data = sum;
    sum = replaceLargerNodesSum(root->left, sum);
    return sum;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    int sum = 0;
    int temp = replaceLargerNodesSum(root, sum);
    return;
}

void printLevelWise(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        return;
    }
    queue<BinaryTreeNode <int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        BinaryTreeNode <int>* front = q.front();
        q.pop();
        if(front == NULL) {
            if(q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << front->data << " ";
        if(front->left != NULL) {
            q.push(front->left);
        }
        if(front->right != NULL) {
            q.push(front->right);
        }
    }
    return;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    replaceWithLargerNodesSum(root);
    printLevelWise(root);
    delete root;
    return 0;
}