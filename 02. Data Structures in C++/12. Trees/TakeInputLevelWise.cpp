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
    vector <TreeNode <T>*> children;

    TreeNode(int data) {
        this->data = data;
    }
};

TreeNode <int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    queue <TreeNode <int>*> q;
    TreeNode <int>* root = new TreeNode <int> (rootData);
    q.push(root);
    while(q.empty() != true) {
        TreeNode <int>* thisRoot = q.front();
        q.pop();
        cout << "Enter no. of children of " << thisRoot->data << endl;
        int count;
        cin >> count;
        for (int i=0; i<count; i++) {
            int childData;
            cout << "Enter " << i << "th child of " << thisRoot->data << endl;
            cin >> childData;
            TreeNode <int> *child = new TreeNode <int> (childData);
            thisRoot->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

void printTree(TreeNode <int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " : ";
    for (int i=0; i<root->children.size(); i++) {
        cout << root->children[i]->data << ", ";
    }
    cout << endl;
    for (int i=0; i<root->children.size(); i++) {
        printTree(root->children[i]);
    }
    return;
}

int main() {
    TreeNode <int>* input = takeInputLevelWise();
    printTree(input);
    return 0;
}