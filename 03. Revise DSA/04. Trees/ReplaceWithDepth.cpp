// Time Complexity = O(N)
// Space Complexity = O(1)


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

void replaceWithDepthHelper(TreeNode<int>* root, int depth) {
    if(root == NULL) {
        return;
    }
    root->data = depth;
    for(int i=0; i<root->children.size(); i++) {
        replaceWithDepthHelper(root->children[i], depth+1);
    }
    return;
}

void replaceWithDepthValue(TreeNode<int>* root) {
    replaceWithDepthHelper(root, 0);
    return;
}

void printLevelWise (TreeNode <int>* root) {
    if(root == NULL) {
        return;
    }
    queue <TreeNode <int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        if(front == NULL) {
            cout << endl;
            if(pendingNodes.empty()) {
                break;
            }
            else {
                continue;
            }
        }
        else {
            cout << front->data << " ";
        }
        for(int i=0; i<front->children.size(); i++) {
            pendingNodes.push(front->children[i]);
        }
        if(front->children.size() > 0) {
            pendingNodes.push(NULL);
        }
    }
}

int main() {
    TreeNode <int>* root = takeInput();
    replaceWithDepthValue(root);
    printLevelWise(root);
    delete root;
    return 0;
}