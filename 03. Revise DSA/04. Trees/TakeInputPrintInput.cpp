#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    vector <TreeNode<T>*> children;
    TreeNode (T data) {
        this->data = data;
    }
    ~ TreeNode() {
        for(int i=0; i<children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode <int>* takeInput(){
    int rootData;
    cout << "Enter data :" << endl;
    cin >> rootData;
    TreeNode <int>* root = new TreeNode<int> (rootData);
    int numChild;
    cout << "Enter no of children :" << endl;
    cin >> numChild;
    for(int i=0; i<numChild; i++) {
        TreeNode <int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " : ";
    for(int i=0; i<root->children.size(); i++) {
        cout << root->children[i]->data << ", ";
    }
    cout << endl;
    for(int i=0; i<root->children.size(); i++) {
        printTree(root->children[i]);
    }
}

void deleteTree(TreeNode<int>* root) {
    for(int i=0; i<root->children.size(); i++) {
        deleteTree(root->children[i]);
    }
    delete root;
}

int main() {
    TreeNode <int>* root = takeInput();
    printTree(root);
    // deleteTree(root);  Don't write destructor, & call deleteTree function
    delete root;
    return 0;
}