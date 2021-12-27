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

int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    if(root == NULL) {
        return -1;
    }
    if(root->data==a || root->data==b) {
        return root->data;
    }
    int leftLCA = getLCA(root->left, a, b);
    int rightLCA = getLCA(root->right, a, b);
    if(leftLCA==-1 && rightLCA==-1) {
        return -1;
    }
    else if(leftLCA==-1 && rightLCA!=-1) {
        return rightLCA;
    }
    else if(leftLCA!=-1 && rightLCA==-1) {
        return leftLCA;
    }
    else {
        return root->data;
    }
}

int main() {
    BinaryTreeNode<int> * root = takeInput();
    int a, b;
    cin >> a >> b;
    int ans = getLCA(root, a, b);
    cout << ans << endl;
    return 0;
}