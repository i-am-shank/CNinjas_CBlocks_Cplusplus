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

// Time Complexity = O(N)
// Space Complexity = O(N)
void printNodesWithoutLevelSibling(BinaryTreeNode<int> *root) {
    queue <BinaryTreeNode <int>*> q;
    q.push(root);
    q.push(NULL);
    int currLevel = 1, nextLevel = 0;
    while(!q.empty()) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        if(front == NULL) {
            if(q.empty()) {
                break;
            }
            q.push(NULL);
            currLevel = nextLevel;
            nextLevel = 0;
            continue;
        }
        if(currLevel == 1) {
            cout << front->data << endl;
        }
        if(front->left != NULL) {
            q.push(front->left);
            nextLevel++;
        }
        if(front->right != NULL) {
            q.push(front->right);
            nextLevel++;
        }
    }
    return;
}

// Time Complexity = O(N)
// Space Complexity = O(1)
void printNodesWithoutSibling(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    if(root->left!=NULL && root->right==NULL) {
        cout << root->left->data << " ";
    }
    else if(root->left==NULL && root->right!=NULL) {
        cout << root->right->data << " ";
    }
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
    return;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    printNodesWithoutSibling(root);
    delete root;
    return 0;
}