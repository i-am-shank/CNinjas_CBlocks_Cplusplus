#include <iostream>
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

int height(BinaryTreeNode<int>* root) {  // O(N) time complexity
    if(root == NULL) {
        return 0;
    }
    return max(height(root->left) , height(root->right)) + 1;
}

// Time Complexity = O(N^2)  ..  Calculating height (O(N)) at each (N) nodes

int diameter1(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        return 0;
    }
    int choice1 = diameter1(root->left);
    int choice2 = diameter1(root->right);
    int choice3 = height(root->left) + height(root->right) + 1;
    return max(choice1,  max(choice2, choice3));
}

// Time Complexity = O(N) .. going to each node only once.
// Space Complexity = O(N)
//     .. O(1) space waiting at each recursion call.

class heightDiameter {
    public:
    int height;
    int diameter;
    heightDiameter(int h, int d) {
        height = h;
        diameter = d;
    }
};

heightDiameter* diameterHelp(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        heightDiameter* ans = new heightDiameter (0, 0);
        return ans;
    }
    heightDiameter* leftAns = diameterHelp(root->left);
    heightDiameter* rightAns = diameterHelp(root->right);
    int h = max(leftAns->height, rightAns->height) + 1;
    int choice1 = leftAns->diameter;
    int choice2 = rightAns->diameter;
    int choice3 = leftAns->height + rightAns->height + 1;
    int d = max(choice1  ,  max(choice2, choice3));
    heightDiameter* ans = new heightDiameter (h, d);
    return ans;
}

int diameter2(BinaryTreeNode <int>* root) {
    return diameterHelp(root)->diameter;
}

int main() {
    BinaryTreeNode <int>* root = takeInput();
    int dia1 = diameter1(root);
    int dia2 = diameter2(root);
    cout << dia1 << " " << dia2 << endl;
    delete root;
    return 0;
}