// Time Complexity = O(N)
// Space Complexity = O(1)


#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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
            TreeNode <int>* child = new TreeNode <int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

template <typename T>
class TreeNodePair {
    public:
    TreeNode <T>* node;
    int childSum;
};

TreeNodePair <int>* maxSumNodeHelp(TreeNode<int>* root) {
    if(root == NULL) {
        TreeNodePair<int>* ans = new TreeNodePair<int>();
        ans->node = NULL;
        ans->childSum = INT_MIN;
        return ans;
    }
    TreeNodePair<int>* ans = new TreeNodePair<int> ();
    ans->node = root;
    ans->childSum = 0;
    for(int i=0; i<root->children.size(); i++) {
        ans->childSum += root->children[i]->data;
    }
    ans->childSum += root->data;
    for(int i=0; i<root->children.size(); i++) {
        TreeNodePair<int>* childAns = maxSumNodeHelp(root->children[i]);
        if(childAns->childSum > ans->childSum) {
            ans = childAns;
        }
    }
    return ans;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    TreeNode<int>* ans = maxSumNodeHelp(root)->node;
    return ans;
}

int main() {
    TreeNode <int>* root = takeInput();
    TreeNode <int>* ans = maxSumNode(root);
    if(ans != NULL) {
        cout << ans->data << endl;
    }
    delete root;
    return 0;
}