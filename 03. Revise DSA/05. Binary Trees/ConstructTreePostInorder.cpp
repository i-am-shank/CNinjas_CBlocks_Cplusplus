#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode <int>* left;
    BinaryTreeNode <int>* right;
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

// Time Complexity = O(N^2)
// Space Complexity = O(N)
//     .. O(1) space waiting at each recursion call.

BinaryTreeNode<int>* buildHelp(int *postorder,int ps,int pe,int *inorder,int is,int ie) {
    if(ps > pe  ||  is > ie) {
        return NULL;
    }
    int rootData = postorder[pe];
    int rI;
    for(int i=is; i<=ie; i++) {
        if(inorder[i] == rootData) {
            rI = i;
            break;
        }
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode <int> (rootData);
    BinaryTreeNode<int>* left = buildHelp(postorder, ps, ps+(rI-is)-1, inorder, is, (rI)-1);
    BinaryTreeNode<int>* right = buildHelp(postorder, ps+(rI-is), pe-1, inorder, (rI)+1, ie);
    root->left = left;
    root->right = right;
    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    return buildHelp(postorder, 0, postLength-1, inorder, 0, inLength-1);
}

void printTree(BinaryTreeNode <int>* root) {
    if(root == NULL) {
        return;
    }
    queue <BinaryTreeNode <int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        BinaryTreeNode <int>* front = q.front();
        q.pop();
        if(front == NULL) {
            if(q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << front->data << " ";
        if(front->left != NULL) {
            q.push(front->left);
        }
        if(front->right != NULL) {
            q.push(front->right);
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;
    int *postorder = new int[n];
    for(int i=0; i<n; i++) {
        cin >> postorder[i];
    }
    int *inorder = new int[n];
    for(int i=0; i<n; i++) {
        cin >> inorder[i];
    }
    BinaryTreeNode<int>* root = buildTree(postorder, n, inorder, n);
    printTree(root);
    delete root;
    return 0;
}