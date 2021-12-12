// Time Complexity = O(N^2)
// Space Complexity = O(N)


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
};

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
            q.push(NULL);
            cout << endl;
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

BinaryTreeNode<int>* buildTreeHelper(int *preorder,int ps,int pe,int* inorder,int is,int ie) {
    if(ps>pe || is>ie) {
        return NULL;
    }
    int rootData = preorder[ps];
    int r;
    for (int i=is; i<=ie; i++) {
        if(inorder[i] == rootData) {
            r = i;
            break;
        }
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode <int> (rootData);
    BinaryTreeNode<int>* lTree = buildTreeHelper(preorder,ps+1,ps+r-is, inorder,is,r-1);
    BinaryTreeNode<int>* rTree = buildTreeHelper(preorder,ps+r-is+1,pe, inorder,r+1,ie);
    root->left = lTree;
    root->right = rTree;
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder,int preLength,int *inorder,int inLength){
    return buildTreeHelper(preorder, 0, preLength-1, inorder, 0, inLength-1);
}

int main() {
    int n;
    cin >> n;
    int *preorder = new int[n];
    for (int i=0; i<n; i++) {
        cin >> preorder[i];
    }
    int *inorder = new int[n];
    for (int i=0; i<n; i++) {
        cin >> inorder[i];
    }
    BinaryTreeNode <int>* root = buildTree(preorder, n, inorder, n);
    printTree(root);
    return 0;
}