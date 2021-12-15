// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode <T>* left;
    BinaryTreeNode <T>* right;

    BinaryTreeNode (T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTreeNode() {
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

void zigZagOrder(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return;
    }
    stack<BinaryTreeNode <int>*> s1;
    stack<BinaryTreeNode <int>*> s2;
    s1.push(root);
    int currLevel=1, nextLevel=0;
    bool flag = true;
    while(!s1.empty() || !s2.empty()) {
        if(flag == true) {
            BinaryTreeNode <int>* front = s1.top();
            s1.pop();
            currLevel--;
            cout << front->data << " ";
            if(front->left != NULL) {
                s2.push(front->left);
                nextLevel++;
            }
            if(front->right != NULL) {
                s2.push(front->right);
                nextLevel++;
            }
            if(currLevel == 0) {
                cout << endl;
                currLevel = nextLevel;
                nextLevel = 0;
                flag = false;
            }
        }
        else {
            BinaryTreeNode<int>* front = s2.top();
            s2.pop();
            currLevel--;
            cout << front->data << " ";
            if(front->right != NULL) {
                s1.push(front->right);
                nextLevel++;
            }
            if(front->left != NULL) {
                s1.push(front->left);
                nextLevel++;
            }
            if(currLevel == 0) {
                currLevel = nextLevel;
                nextLevel = 0;
                cout << endl;
                flag = true;
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