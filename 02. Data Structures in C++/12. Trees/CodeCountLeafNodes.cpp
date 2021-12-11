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
    vector <TreeNode <T>*> children;

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

int getLeafNodeCount(TreeNode<int>* root) {
    if(root->children.size() == 0) {
        return 1;
    }
    int count = 0;
    for (int i=0; i<root->children.size(); i++) {
        count += getLeafNodeCount(root->children[i]);
    }
    return count;
}

int main() {
    TreeNode <int> *root = takeInputLevelWise();
    int ans = getLeafNodeCount(root);
    cout << ans << endl;
    return 0;
}