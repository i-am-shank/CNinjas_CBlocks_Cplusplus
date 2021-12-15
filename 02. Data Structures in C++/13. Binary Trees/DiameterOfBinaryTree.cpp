#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode <int>* left;
    BinaryTreeNode <int>* right;

    BinaryTreeNode (int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

template <typename X, typename Y>
class Pair {
    public:
    X first;
    Y second;

    Pair(X data1, Y data2) {
        this->first = data1;
        this->second = data2;
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
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode <int> (leftData);
            q.push(leftNode);
            front->left = leftNode;
        }
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode <int> (rightData);
            q.push(rightNode);
            front->right = rightNode;
        }
    }
    return root;
}

int height(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

// Time Complexity = O(N^2)
// Space Complexity = O(N)
int diameter(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        return 0;
    }
    int option1 = diameter(root->left);
    int option2 = diameter(root->right);
    int option3 = height(root->left) + height(root->right);
    return max(option1 , max(option2, option3));
}

// Time Complexity = O(N)
// Space Complexity = O(N)
Pair <int, int>* heightDiameter(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        Pair <int, int>* ans = new Pair <int, int> (0, 0);
        return ans;
    }
    Pair <int, int>* leftAns = heightDiameter(root->left);
    Pair <int, int>* rightAns = heightDiameter(root->right);
    int lh = leftAns->first , ld = leftAns->second;
    int rh = rightAns->first , rd = rightAns->second;
    int height = max(lh, rh) + 1;
    int diameter = max(lh+rh , max(ld, rd));
    Pair <int, int>* ans = new Pair <int, int> (height, diameter);
    return ans;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int ans1 = diameter(root);
    cout << ans1 << endl;
    int ans2 = heightDiameter(root)->second;
    cout << ans2 << endl;
    return 0;
}