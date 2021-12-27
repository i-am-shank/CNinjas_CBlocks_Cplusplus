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

// Time Complexity = O(N^2)
// Space Complexity = O(1)

int minimum(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return INT_MAX;
    }
    return min(root->data , min(minimum(root->left), minimum(root->right)) );
}

int maximum(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return INT_MIN;
    }
    return max(root->data , max(maximum(root->left), maximum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return true;
    }
    if((root->data<=minimum(root->right)) && (root->data>maximum(root->left)) && isBST(root->left) && isBST(root->right)) {
        return true;
    }
    else {
        return false;
    }
}

// Time Complexity = O(N)
// Space Complexity = O(N)

template <typename T>
class isBSTreturn {
    public:
    bool isBst;
    T min;
    T max;
};

isBSTreturn<int> isBST2Helper(BinaryTreeNode<int> * root) {
    if(root == NULL) {
        isBSTreturn<int> ans;
        ans.isBst = true;
        ans.max = INT_MIN;
        ans.min = INT_MAX;
        return ans;
    }
    isBSTreturn<int> leftAns = isBST2Helper(root->left);
    isBSTreturn<int> rightAns = isBST2Helper(root->right);
    isBSTreturn<int> ans;
    ans.max = min(root->data , min(leftAns.min, rightAns.min));
    ans.min = max(root->data , max(leftAns.max, rightAns.max));
    if((root->data<=rightAns.min) && (root->data>leftAns.max) && leftAns.isBst==true && rightAns.isBst==true) {
        ans.isBst = true;
        return ans;
    }
    else {
        ans.isBst = false;
        return ans;
    }
}

bool isBST2(BinaryTreeNode<int> *root) {
    return isBST2Helper(root).isBst;
}

// Time Complexity = O(N)
// Space Complexity = O(N)

bool isBST3Helper(BinaryTreeNode<int>* root, int min, int max) {
    if(root == NULL) {
        return true;
    }
    if(root->data > min && root->data <= max) {
        bool leftAns = isBST3Helper(root->left, min, root->data-1);
        bool rightAns = isBST3Helper(root->right, root->data, max);
        if(leftAns==true && rightAns==true) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

bool isBST3(BinaryTreeNode<int> *root) {
    return isBST3Helper(root, INT_MIN, INT_MAX);
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    bool ans = isBST(root);
    if(ans == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    cout << "isBST2 : " << isBST2(root) << endl;
    cout << "isBST3 : " << isBST3(root) << endl;
    return 0;
}