// Time Complexity = O(logN)
// Space Complexity = O(logN)


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode <T>* left;
    BinaryTreeNode <T>* right;

    BinaryTreeNode (int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTreeNode () {
        delete left;
        delete right;
    }
};

BinaryTreeNode <int>* takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode <int>* root = new BinaryTreeNode <int> (rootData);
    queue <BinaryTreeNode <int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode <int>* front = q.front();
        q.pop();
        int leftData, rightData;
        cin >> leftData;
        if(leftData != -1) {
            BinaryTreeNode <int>* leftNode = new BinaryTreeNode <int> (leftData);
            q.push(leftNode);
            front->left = leftNode;
        }
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode <int>* rightNode = new BinaryTreeNode <int> (rightData);
            q.push(rightNode);
            front->right = rightNode;
        }
    }
    return root;
}

void printPath(vector<int>* v) {
    for(int i=0; i<v->size(); i++) {
        cout << v->at(i) << " ";
    }
    cout << endl;
    return;
}

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data == data) {
        vector<int>* ans = new vector <int>;
        ans->push_back(root->data);
        return ans;
    }
    else if(root->data < data) {
        vector<int>* ans = getPath(root->right, data);
        if(ans != NULL) {   // if == NULL , element not found in tree.
            ans->push_back(root->data);
        }
        return ans;
    }
    else {
        vector<int>* ans = getPath(root->left, data);
        if(ans != NULL) {
            ans->push_back(root->data);
        }
        return ans;
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int data;
    cin >> data;
    vector<int>* path = getPath(root, data);
    printPath(path);
    delete root;
    return 0;
}