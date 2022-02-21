#include <iostream>
#include <queue>
#include <climits>
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

pair <int, int> minMaxTree(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        pair<int, int> ans (INT_MAX, INT_MIN);
        return ans;
    }
    pair<int, int> ans;
    pair<int, int> leftAns = minMaxTree(root->left);
    pair<int, int> rightAns = minMaxTree(root->right);
    ans.first = min(root->data , leftAns.first);
    ans.second = max(root->data , rightAns.second);
    return ans;
}

// Time Complexity = O(N * logN)
// Space Complexity = O(N)

bool isBST1(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        return true;
    }
    int leftMax = minMaxTree(root->left).second;
    int rightMin = minMaxTree(root->right).first;
    if((leftMax < root->data)  &&  (root->data <= rightMin)) {
        return (isBST1(root->left) && isBST1(root->right));
    }
    return false;
}

// Time Complexity = O(N)
// Space Complexity = O(N)

class isBSTReturn {
    public:
    int min;
    int max;
    bool isBST;
};

isBSTReturn isBST2Helper(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        isBSTReturn ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.isBST = true;
        return ans;
    }
    isBSTReturn ans;
    isBSTReturn leftAns = isBST2Helper(root->left);
    isBSTReturn rightAns = isBST2Helper(root->right);
    ans.min = min (root->data  ,  min(leftAns.min , rightAns.min));
    ans.max = max (root->data  ,  max(leftAns.max , rightAns.max));
    if((root->data > leftAns.max) && (root->data <= rightAns.min)) {
        if(leftAns.isBST && rightAns.isBST) {
            ans.isBST = true;
        }
        else {
            ans.isBST = false;
        }
    }
    else {
        ans.isBST = false;
    }
    return ans;
}

bool isBST2(BinaryTreeNode <int>* root) {
    return isBST2Helper(root).isBST;
}

// Time Complexity = O(N)
// Space Complexity = O(N)

bool isBST3Helper(BinaryTreeNode <int>* root, int min, int max) {
    if(root == NULL) {
        return true;
    }
    bool leftAns = isBST3Helper(root->left, min, root->data);
    bool rightAns = isBST3Helper(root->right, root->data, max);
    if(root->data>=min && root->data<max) {
        if(leftAns && rightAns) {
            return true;
        }
    }
    return false;
}

bool isBST3(BinaryTreeNode <int>* root) {
    return isBST3Helper(root, INT_MIN, INT_MAX);
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    bool ans1 = isBST1(root);
    bool ans2 = isBST2(root);
    bool ans3 = isBST3(root);
    cout << (ans1 == true ? "true" : "false") << endl;
    cout << (ans2 == true ? "true" : "false") << endl;
    cout << (ans3 == true ? "true" : "false") << endl;
    delete root;
    return 0;
}