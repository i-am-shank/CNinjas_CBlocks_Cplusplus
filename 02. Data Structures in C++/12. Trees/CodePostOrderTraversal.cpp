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

void printPreOrder(TreeNode <int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    for (int i=0; i<root->children.size(); i++) {
        printPreOrder(root->children[i]);
    }
    return;
}
void printPostOrder(TreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    for(int i=0; i<root->children.size(); i++) {
        printPostOrder(root->children[i]);
    }
    cout << root->data << " ";
    return;
}

int main() {
    TreeNode <int>* root = takeInputLevelWise();
    printPostOrder(root);
    return 0;
}