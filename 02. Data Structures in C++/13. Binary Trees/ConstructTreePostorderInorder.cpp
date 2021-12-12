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

BinaryTreeNode<int>* buildTreeHelper(int *postorder,int ps,int pe,int *inorder,int is, int ie) {
    if(ps>pe || is>ie) {
        return NULL;
    }
    int rootData = postorder[pe];
    int r;
    for(int i=is; i<=ie; i++) {
        if(rootData == inorder[i]) {
            r = i;
            break;
        }
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int> (rootData);
    BinaryTreeNode<int>* lT = buildTreeHelper(postorder,ps,ps+r-is-1, inorder,is,r-1);
    BinaryTreeNode<int>* rT = buildTreeHelper(postorder,ps+r-is,pe-1, inorder,r+1,ie);
    root->left = lT;
    root->right = rT;
    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder,int postLength,int *inorder,int inLength) {
    return buildTreeHelper(postorder, 0, postLength-1, inorder, 0, inLength-1);
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
    BinaryTreeNode <int>* root = buildTree(postorder, n, inorder, n);
    printTree(root);
    return 0;
}