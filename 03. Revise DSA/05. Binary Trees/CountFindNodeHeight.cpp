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

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if(root == NULL) {
        return false;
    }
    if(root->data == x) {
        return true;
    }
    bool leftAns = isNodePresent(root->left, x);
    bool rightAns = isNodePresent(root->right, x);
    if(leftAns==true || rightAns==true) {
        return true;
    }
    return false;
}

int height(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        return 0;
    }
    return 1 + max(height(root->left) , height(root->right));
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int x;
    cin >> x;
    bool ans = isNodePresent(root, x);
    int heightTree = height(root);
    cout << (ans == true ? "true" : "false") << endl;
    cout << heightTree << endl;
    delete root;
    return 0;
}