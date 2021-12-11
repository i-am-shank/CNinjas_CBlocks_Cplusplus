#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    vector <TreeNode<T>*> children;

    TreeNode(int data) {
        this->data = data;
    }
};

TreeNode <int>* takeInput() {
    int data;
    cin >> data;
    TreeNode <int>* root = new TreeNode <int> (data);
    cout << "Enter no. of children of " << root->data << endl;
    int c;
    cin >> c;
    for(int i=0; i<c; i++) {
        TreeNode <int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode <int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " : ";
    for(int i=0; i<root->children.size(); i++) {
        cout << root->children[i]->data << " , ";
    }
    cout << endl;
    for(int i=0; i<root->children.size(); i++) {
        printTree(root->children[i]);
    }
    return;
}

int main() {
    TreeNode <int>* input = takeInput();
    printTree(input);
    return 0;
}