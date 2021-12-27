// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode <T>* left;
    BinaryTreeNode <T>* right;

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
    BinaryTreeNode <int>* root = new BinaryTreeNode<int> (rootData);
    queue<BinaryTreeNode<int>* > q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        int leftData, rightData;
        cin >> leftData;
        if(leftData != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int> (leftData);
            q.push(leftNode);
            front->left = leftNode;
        }
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int> (rightData);
            q.push(rightNode);
            front->right = rightNode;
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    queue <BinaryTreeNode<int>* > q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        BinaryTreeNode<int>* front = q.front();
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

void insertDuplicateNode(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return;
    }
    BinaryTreeNode <int>* duplicate = new BinaryTreeNode<int> (root->data);
    duplicate->left = root->left;
    root->left = duplicate;
    insertDuplicateNode(root->left->left);
    insertDuplicateNode(root->right);
    return;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    insertDuplicateNode(root);
    printLevelWise(root);
    delete root;
    return 0;
}