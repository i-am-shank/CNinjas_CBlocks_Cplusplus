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
//       .. O(1) space waiting at each recursion call.

int getLargeNodeCount(TreeNode<int>* root, int x) {
    if(root == NULL) {
        return 0;
    }
    int count = 0;
    for(int i=0; i<root->children.size(); i++) {
        int smallCount = getLargeNodeCount(root->children[i], x);
        count += smallCount;
    }
    if(root->data > x) {
        count += 1;
    }
    return count;
}

int main() {
    TreeNode <int>* root = takeInput();
    int x;
    cin >> x;
    int count = getLargeNodeCount(root, x);
    cout << count << endl;
    delete root;
    return 0;
}