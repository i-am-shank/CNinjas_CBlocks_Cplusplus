// Time Complexity = O(N)
// Space Complexity = O(N)
//      .. O(1) space waiting at each recursion call.


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
        for(int i=0; i<children.size(); i++){
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
            TreeNode <int>* child = new TreeNode<int> (childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1 == NULL && root2 == NULL) {  // both NULL
        return true;
    }
    else if(root1 == NULL || root2 == NULL) {  // only one NULL
        return false;
    }
    if(root1->data == root2->data) {
        if(root1->children.size() == root2->children.size()) {
            for(int i=0; i<root1->children.size(); i++) {
                bool smallAns = areIdentical(root1->children[i], root2->children[i]);
                if(smallAns == false) {
                    return false;
                }
            }
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

int main() {
    TreeNode <int>* root1 = takeInput();
    TreeNode <int>* root2 = takeInput();
    bool ans = areIdentical(root1, root2);
    cout << (ans == true ? "true" : "false") << endl;
    delete root1;
    delete root2;
    return 0;
}