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

// Time Complexity = O(N^2)
// Space Complexity = O(N)
//     .. O(1) space waiting at each recursion call.

BinaryTreeNode<int>* buildHelper(int *preorder,int ps,int pe,int *inorder,int is,int ie) {
    if(ps > pe  ||  is > ie) {
        return NULL;
    }
    int rootData = preorder[ps] , rI;
    BinaryTreeNode <int>* root = new BinaryTreeNode <int> (rootData);
    for(int i=is; i<=ie; i++) {
        if(rootData == inorder[i]) {
            rI = i;
            break;
        }
    }
    BinaryTreeNode<int>* left = buildHelper(preorder, ps+1, ps+(rI-is), inorder, is, rI-1);
    BinaryTreeNode<int>* right = buildHelper(preorder, ps+(rI-is)+1, pe, inorder, rI+1, ie);
    root->left = left;
    root->right = right;
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    return buildHelper(preorder, 0, preLength-1, inorder, 0, inLength-1);
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
    int *preorder = new int [n];
    for(int i=0; i<n; i++) {
        cin >> preorder[i];
    }
    int *inorder = new int[n];
    for(int i=0; i<n; i++) {
        cin >> inorder[i];
    }
    BinaryTreeNode <int>* root = buildTree(preorder, n, inorder, n);
    printTree(root);
    return 0;
}