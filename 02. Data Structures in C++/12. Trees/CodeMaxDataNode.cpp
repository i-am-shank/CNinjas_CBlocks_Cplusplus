// Time Complexity = O(N)
// Space Complexity = O(1)


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    vector <TreeNode <int>*> children;

    TreeNode (int data) {
        this->data = data;
    }
};

TreeNode <int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode <int>* root = new TreeNode <int> (rootData);
    queue <TreeNode <int>*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode <int>*front = q.front();
        int numChild;
        cin >> numChild;
        for (int i=0; i<numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode <int>* child = new TreeNode <int> (childData);
            front->children.push_back(child);
            q.push(child);
        }
        q.pop();
    }
    return root;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(root == NULL) {
        return root;
    }
    TreeNode <int>* maxNode = root;
    for (int i=0; i<root->children.size(); i++) {
        TreeNode <int>* maxChild = maxDataNode(root->children[i]);
        if(maxNode->data < maxChild->data) {
            maxNode = maxChild;
        }
    }
    return maxNode;
}

int main() {
    TreeNode <int>* root = takeInputLevelWise();
    TreeNode <int>* max = maxDataNode(root);
    cout << max->data << endl;
    return 0;
}