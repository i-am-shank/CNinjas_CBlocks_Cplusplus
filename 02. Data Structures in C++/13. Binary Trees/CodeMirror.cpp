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

void printTree(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        return;
    }
    queue <BinaryTreeNode <int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        BinaryTreeNode <int>* front = q.front();
        q.pop();
        if(front == NULL) {
            if(q.empty()) {
                break;
            }
            q.push(NULL);
            cout << endl;
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

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL || (root->left==NULL && root->right==NULL)) {
        return;
    }
    BinaryTreeNode <int>* temp = root->right;
    root->right = root->left;
    root->left = temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    return;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    mirrorBinaryTree(root);
    printTree(root);
    delete root;
    return 0;
}