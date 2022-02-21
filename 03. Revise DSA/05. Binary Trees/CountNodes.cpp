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
    queue <BinaryTreeNode <int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        BinaryTreeNode <int>* front = pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        cin >> leftData;
        if(leftData != -1) {
            BinaryTreeNode <int>* left = new BinaryTreeNode <int> (leftData);
            root->left = left;
            pendingNodes.push(left);
        }
        int rightData;
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode <int>* right = new BinaryTreeNode <int> (rightData);
            root->right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}

int numNodes(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        return 0;
    }
    int ans = 1;
    ans += numNodes(root->left);
    ans += numNodes(root->right);
    return ans;
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int ans = numNodes(root);
    cout << ans << endl;
    delete root;
    return 0;
}