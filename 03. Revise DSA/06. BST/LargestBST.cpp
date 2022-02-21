#include <iostream>
#include <climits>
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

class largestBST {
    public:
    int min;
    int max;
    bool isBST;
    int height;
};

largestBST largestBSTHelper(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        largestBST ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.isBST = true;
        ans.height = 0;
        return ans;
    }
    largestBST leftAns = largestBSTHelper(root->left);
    largestBST rightAns = largestBSTHelper(root->right);
    largestBST ans;
    if(leftAns.isBST==false  ||  root->data < leftAns.max) {
        leftAns.isBST = false;  // left Sub-tree is not a BST.
    }
    if(rightAns.isBST==false  ||  root->data > rightAns.min) {
        rightAns.isBST = false;  // right sub-tree is not a BST.
    }
    if(leftAns.isBST==false || rightAns.isBST==false || 
        root->data < leftAns.max  ||  root->data > rightAns.min) {  
            // tree not fulfills anyone of BST rule  -->  not a BST.
        if(leftAns.height > rightAns.height) {
            leftAns.isBST = false;  // as leftAns is symbolising whole tree output
            return leftAns;
        }
        else {
            rightAns.isBST = false;
            return rightAns;
        }
    }
    ans.min = min(root->data, min(leftAns.min, rightAns.min));
    ans.max = max(root->data, max(leftAns.max, rightAns.max));
    ans.isBST = true;
    ans.height = max(leftAns.height, rightAns.height) + 1;
    return ans;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    return largestBSTHelper(root).height;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int ans = largestBSTSubtree(root);
    cout << ans << endl;
    delete root;
    return 0;
}