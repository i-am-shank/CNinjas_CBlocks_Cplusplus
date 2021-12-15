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

    BinaryTreeNode (T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

template <typename X, typename Y>
class Pair {
    public:
    X balanced;
    Y height;
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
            front->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode <int>* rightNode = new BinaryTreeNode <int> (rightData);
            front->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

Pair <bool, int> isBalancedHelper(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        Pair<bool, int> ans;
        ans.balanced = true;
        ans.height = 0;
        return ans;
    }
    Pair<bool, int> leftAns = isBalancedHelper(root->left);
    Pair<bool, int> rightAns = isBalancedHelper(root->right);
    int smallHeight;
    bool smallBalanced;
    if(leftAns.balanced==true && rightAns.balanced==true) {
        if(leftAns.height-rightAns.height<=1 && leftAns.height-rightAns.height>=-1) {
            smallHeight = max(leftAns.height , rightAns.height) + 1;
            smallBalanced = true;
            Pair<bool, int> ans;
            ans.height = smallHeight;
            ans.balanced = smallBalanced;
            return ans;
        }
    }
    Pair<bool, int> ans;
    ans.balanced = false;
    ans.height = smallHeight;
    return ans;
}

bool isBalanced(BinaryTreeNode<int> *root) {
    return isBalancedHelper(root).balanced;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    bool ans = isBalanced(root);
    if(ans == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}