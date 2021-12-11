// Time Complexity = O(N^2)
// Space Complexity = O(N)


#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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

template <typename T>
class TreeNodePair {
    public:
    TreeNode <T>* node;
    int sum;
};

TreeNode <int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode <int>* root = new TreeNode <int> (rootData);
    queue <TreeNode <int>*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode <int>* front = q.front();
        q.pop();
        int numChild;
        cin >> numChild;
        for (int i=0; i<numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode <int>* child = new TreeNode <int> (childData);
            q.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

TreeNodePair <int>* maxSumNodeHelper(TreeNode <int>* root) {
    if(root == NULL) {
        TreeNodePair <int>* ans = new TreeNodePair <int> ();
        ans->node = NULL;
        ans->sum = INT_MIN;
        return ans;
    }
    TreeNodePair <int>* ans = new TreeNodePair <int> ();
    ans->node = root;
    ans->sum = 0;
    for (int i=0; i<root->children.size(); i++) {
        ans->sum += root->children[i]->data;
    }
    for (int i=0; i<root->children.size(); i++) {
        TreeNodePair <int>* childMax = maxSumNodeHelper(root->children[i]);
        if(childMax->sum > ans->sum) {
            ans = childMax;
        }
    }
    return ans;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    return maxSumNodeHelper(root)->node;
}

int main() {
    TreeNode <int>* root = takeInputLevelWise();
    TreeNode <int>* ans = maxSumNode(root);
    cout << ans->data << endl;
    return 0;
}