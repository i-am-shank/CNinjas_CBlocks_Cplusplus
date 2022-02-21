#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode <T>* left;
    BinaryTreeNode <T>* right;
    BinaryTreeNode (T data) {
        this->data = data;
        left = NULL;
        right = NULL;
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
            front->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode <int>* rightNode = new BinaryTreeNode <int> (rightData);
            front->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

// Time Complexity = O(N)
// Space Complexity = O(2 ^ logN)

void zigZagOrder(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return;
    }
    stack <BinaryTreeNode <int>*> s1, s2;  //  s1 - oddLevel  ,  s2 - evenLevel
    s1.push(root);
    while(!s1.empty()  ||  !s2.empty()) {
        while(!s1.empty()) {
            BinaryTreeNode <int>* front = s1.top();
            s1.pop();
            cout << front->data << " ";
            if(s1.empty()) {
                cout << endl;
            }
            //  Entry in s2   :   L -> R
            if(front->left != NULL) {
                s2.push(front->left);
            }
            if(front->right != NULL) {
                s2.push(front->right);
            }
        }
        while(!s2.empty()) {
            BinaryTreeNode <int>* front = s2.top();
            s2.pop();
            cout << front->data << " ";
            if(s2.empty()) {
                cout << endl;
            }
            //  Entry in s1   :   R -> L
            if(front->right != NULL) {
                s1.push(front->right);
            }
            if(front->left != NULL) {
                s1.push(front->left);
            }
        }
    }
    return;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    zigZagOrder(root);
    delete root;
    return 0;
}