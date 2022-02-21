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

int height(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        return 0;
    }
    return max(height(root->left) , height(root->right)) + 1;
}

// Time Complexity = O(N^2)
// Space Complexity = O(N)

bool isBalanced(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return true;
    }
    if(isBalanced(root->left) && isBalanced(root->right)) {
        int maxHeight = max(height(root->left) , height(root->right));
        int minHeight = min(height(root->left) , height(root->right));
        if(maxHeight - minHeight <= 1) {
            return true;
        }
        return false;
    }
    return false;
}

// Time Complexity = O(N)
// Space Complexity = O(N)
//      .. O(1) space waiting at each recursion call.

pair<int, bool> isBalanced2Helper(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        pair<int, bool> ans (0, true);
        return ans;
    }
    pair<int, bool> leftAns = isBalanced2Helper(root->left);
    pair<int, bool> rightAns = isBalanced2Helper(root->right);
    pair<int, bool> ans;
    int maxHeight = max(leftAns.first , rightAns.first);
    int minHeight = min(leftAns.first , rightAns.first);
    if((maxHeight - minHeight <= 1) && (leftAns.second==true && rightAns.second==true)){
        ans.second = true;
    }
    else {
        ans.second = false;
    }
    ans.first = maxHeight + 1;
    return ans;
}

bool isBalanced2(BinaryTreeNode <int>* root) {
    return isBalanced2Helper(root).second;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    bool ans = isBalanced(root);
    bool ans2 = isBalanced2(root);
    cout << (ans == true ? "true" : "false") << endl;
    cout << (ans2 == true ? "true" : "false") << endl;
    delete root;
    return 0;
}