#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

Node* takeInput() {
	int rootData;
	cin >> rootData;
	if(rootData == -1) {
		return NULL;
	}
	Node* root = new Node(rootData);
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* front = q.front();
		q.pop();
		int leftData, rightData;
		cin >> leftData >> rightData;
		if(leftData != -1) {
			Node* leftChild = new Node(leftData);
			front->left = leftChild;
			q.push(leftChild);
		}
		if(rightData != -1) {
			Node* rightChild = new Node(rightData);
			front->right = rightChild;
			q.push(rightChild);
		}
	}
	return root;
}

Node* buildBT(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe) {
	if(is>ie || ps>pe) {
		return NULL; // NULL tree possible with no data
	}
	int rootData = postorder[pe];
	Node* root = new Node(rootData);
	int idx;
	for(idx=is; idx<=ie; idx++) {
		if(inorder[idx] == rootData) {
			break;
		}
	}
	int leftLen = (idx-is);
	// Left sub-tree :-
	// [is, idx-1]     [ps, ps+leftLen-1]
	Node* leftChild = buildBT(inorder, is, idx-1, postorder, ps, ps+leftLen-1);
	// Right sub-tree :-
	// [idx+1, ie]     [ps+leftLen, pe-1]
	Node* rightChild = buildBT(inorder, idx+1, ie, postorder, ps+leftLen, pe-1);
	root->left = leftChild;
	root->right = rightChild;
	return root;
}

Node *buildTree(vector<int>& inorder, vector<int>& postorder, int n) {
	// vector<int> inorder(n), postorder(n);
    // for(int i=0; i<n; i++) {
    // 	inorder[i] = in[i];
    // 	postorder[i] = post[i];
    // }
    return buildBT(inorder, 0, n-1, postorder, 0, n-1);
}

void preorder(Node* root) {
	if(root == NULL) {
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
	return;
}

int main() {
	int n;
	cin >> n;
	vector<int> inorder(n), postorder(n);
	for(int i=0; i<n; i++) {
		cin >> inorder[i];
	}
	for(int i=0; i<n; i++) {
		cin >> postorder[i];
	}
	Node* root = buildTree(inorder, postorder, n);
	preorder(root);
	return 0;
}