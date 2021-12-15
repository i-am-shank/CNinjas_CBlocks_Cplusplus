// Time Complexity = O(N)
// Space Complexity = O(N)


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

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        pair<int, int> ans;
        ans.first = INT_MAX;
        ans.second = INT_MIN;
        return ans;
    }
    pair<int, int> leftAns = getMinAndMax(root->left);
    pair<int, int> rightAns = getMinAndMax(root->right);
    int minimum = min(root->data , min(leftAns.first, rightAns.first));
    int maximum = max(root->data , max(leftAns.second, rightAns.second));
    pair<int, int> ans;
    ans.first = minimum;
    ans.second = maximum;
    return ans;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int min = getMinAndMax(root).first;
    int max = getMinAndMax(root).second;
    cout << min << " " << max << endl;
    return 0;
}