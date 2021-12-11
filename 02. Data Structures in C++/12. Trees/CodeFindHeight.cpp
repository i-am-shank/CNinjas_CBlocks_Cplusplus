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
        int numChild;
        cin >> numChild;
        for (int i=0; i<numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode <int>* child = new TreeNode <int> (childData);
            q.push(child);
            front->children.push_back(child);
        }
        q.pop();
    }
    return root;
}

int getHeight(TreeNode<int>* root) {
    if(root == NULL) {
        return INT_MIN;
    }
    if(root->children.size() == 0) {
        return 1;
    }
    int max = 0;
    for (int i=0; i<root->children.size(); i++) {
        int maxChildHeight = getHeight(root->children[i]);
        if(maxChildHeight > max) {
            max = maxChildHeight;
        }
    }
    return max+1;
}

int main() {
    TreeNode <int>* root = takeInputLevelWise();
    int height = getHeight(root);
    cout << height << endl;
    return 0;
}