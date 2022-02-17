#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    vector <TreeNode <int>*> children;
    TreeNode (T data) {
        this->data = data;
    }
    ~TreeNode () {
        for(int i=0; i<children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode <int>* takeInputLevelOrder() {
    int rootData;
    cin >> rootData;
    TreeNode <int>* root = new TreeNode <int>(rootData);
    queue <TreeNode <int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        TreeNode <int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for(int i=0; i<numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode <int>* child = new TreeNode <int> (childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

void preOrder(TreeNode <int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    for(int i=0; i<root->children.size(); i++) {
        preOrder(root->children[i]);
    }
}

// Time Complexity = O(N)
// Space Complexity = O(1)

void postOrder(TreeNode <int>* root) {
    if(root == NULL) {
        return;
    }
    for(int i=0; i<root->children.size(); i++) {
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}

int main() {
    TreeNode <int>* root = takeInputLevelOrder();
    cout << "preOrder :" << endl;
    preOrder(root);
    cout << endl;
    cout << "postOrder :" << endl;
    postOrder(root);
    cout << endl;
    delete root;
    return 0;
}