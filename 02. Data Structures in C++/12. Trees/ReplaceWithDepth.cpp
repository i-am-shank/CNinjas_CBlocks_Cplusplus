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

void printTree(TreeNode <int>* root) {
    if(root == NULL) {
        return;
    }
    queue <TreeNode <int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        TreeNode <int>* front = q.front();
        q.pop();
        if(front == NULL) {
            if(q.empty()) {
                cout << endl;
                break;
            }
            q.push(NULL);
            cout << endl;
            continue;
        }
        cout << front->data << " ";
        for (int i=0; i<front->children.size(); i++) {
            q.push(front->children[i]);
        }
    }
    return;
}

void replaceWithDepthValue(TreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    queue <TreeNode <int>*> q;
    root->data = 0;
    q.push(root);
    while(!q.empty()) {
        TreeNode <int>* front = q.front();
        q.pop();
        for (int i=0; i<front->children.size(); i++) {
            front->children[i]->data = front->data + 1;
            q.push(front->children[i]);
        }
    }
    return;
}

int main() {
    TreeNode <int>* root = takeInputLevelWise();
    replaceWithDepthValue(root);
    printTree(root);
}