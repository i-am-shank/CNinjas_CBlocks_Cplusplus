// Time Complexity = O(N)
// Space Complexity = O(1)


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
};

BinaryTreeNode <int>* takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode <int>* root = new BinaryTreeNode<int> (rootData);
    queue <BinaryTreeNode <int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode <int>* front = q.front();
        q.pop();
        int leftData, rightData;
        cin >> leftData;
        if(leftData != -1) {
            BinaryTreeNode <int>* leftNode = new BinaryTreeNode <int>(leftData);
            front->left = leftNode;
            q.push(front->left);
        }
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode <int>* rightNode = new BinaryTreeNode <int>(rightData);
            front->right = rightNode;
            q.push(front->right);
        }
    }
    return root;
}

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    if(root == NULL) {
        return;
    }
    if(root->data < k1) {
        elementsInRangeK1K2(root->right, k1, k2);
    }
    else if(root->data >= k1 && root->data <= k2) {
        elementsInRangeK1K2(root->left, k1, k2);
        cout << root->data << " ";
        elementsInRangeK1K2(root->right, k1, k2);
    }
    else {
        elementsInRangeK1K2(root->left, k1, k2);
    }
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int k1, k2;
    cin >> k1 >> k2;
    elementsInRangeK1K2(root, k1, k2);
    return 0;
}