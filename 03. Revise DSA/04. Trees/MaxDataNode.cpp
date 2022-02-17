#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    vector <TreeNode <T>*> children;
    TreeNode (T data) {
        this->data = data;
    }
    ~TreeNode () {
        for(int i=0; i<children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode <int>* takeInput() {
    int rootData;
    cin >> rootData;
    TreeNode <int>* root = new TreeNode <int> (rootData);
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

// Time Complexity = O(N)
// Space Complexity = O(N)
//     .. O(1) space waiting at each recursion call.

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(root == NULL) {
        return NULL;
    }
    TreeNode <int>* maxNode = new TreeNode <int> (root->data);
    for(int i=0; i<root->children.size(); i++) {
        TreeNode <int>* maxNodeChild = maxDataNode(root->children[i]);
        if(maxNode->data < maxNodeChild->data) {
            maxNode = maxNodeChild;
        }
    }
    return maxNode;
}

int main() {
    TreeNode <int>* root = takeInput();
    TreeNode <int>* ans = maxDataNode(root);
    cout << ans->data << endl;
    delete root;
    delete ans;
    return 0;
}