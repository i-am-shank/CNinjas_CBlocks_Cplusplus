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

TreeNode <int>* takeInputLevelWise() {
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
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

// Time Complexity = O(N)
// Space Complexity = O(N)
//       .. O(1) space waiting at each recursion call.
int countNodes(TreeNode <int>* root) {
    if(root == NULL) {
        return 0;
    }
    int count = 1;
    for(int i=0; i<root->children.size(); i++) {
        int smallCount = countNodes(root->children[i]);
        count += smallCount;
    }
    return count;
}

int main() {
    TreeNode <int>* root = takeInputLevelWise();
    int numNodes = countNodes(root);
    cout << numNodes << endl;
    delete root;
    return 0;
}