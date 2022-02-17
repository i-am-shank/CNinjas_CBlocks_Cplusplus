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
    ~TreeNode (){
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
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

// Time Complexity = O(N)
// Space Complexity = O(1)

int sumOfNodes(TreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    int sum = root->data;
    for(int i=0; i<root->children.size(); i++) {
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}

int main() {
    TreeNode <int>* root = takeInput();
    int sum = sumOfNodes(root);
    cout << sum << endl;
    delete root;
    return 0;
}