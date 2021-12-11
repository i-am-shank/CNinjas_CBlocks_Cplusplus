// Time Complexity = O(N)
// Space Complexity = O(N)


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

int getLargeNodeCount(TreeNode<int>* root, int x) {
    if(root == NULL) {
        return 0;
    }
    int count = 0;
    if(root->data > x) {
        count ++;
    }
    for (int i=0; i<root->children.size(); i++) {
        count += getLargeNodeCount(root->children[i], x);
    }
    return count;
}

int main() {
    TreeNode <int>* root = takeInputLevelWise();
    int x;
    cin >> x;
    int ans = getLargeNodeCount(root, x);
    cout << ans << endl;
    return 0;
}