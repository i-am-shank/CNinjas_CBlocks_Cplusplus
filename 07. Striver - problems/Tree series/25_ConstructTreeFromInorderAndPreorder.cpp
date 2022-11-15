#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
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

class Solution{
	Node* buildBT(vector<int>& inorder, int is, int ie, vector<int>& preorder, int ps, int pe) {
		if(is>ie || ps>pe) {
			return NULL; // A NULL node can be formed with no data
		}
		int rootData = preorder[ps];
		int idx;
		for(idx=is; idx<=ie; idx++) {
			if(inorder[idx] == rootData) {
				break;
			}
		}
		int leftLen = (idx-is);
		Node* root = new Node(rootData);
		// Left-subtree :-
		// [is, idx-1]    [ps+1, ps+leftLen]
		Node* leftChild = buildBT(inorder, is, idx-1, preorder, ps+1, ps+leftLen);
		// Right-subtree :-
		// [idx+1, ie]    [ps+leftLen+1, pe]
		Node* rightChild = buildBT(inorder, idx+1, ie, preorder, ps+leftLen+1, pe);
		root->left = leftChild;
		root->right = rightChild;
		return root;
	}

public:
    Node* buildTree(vector<int>& inorder, vector<int>& preorder, int n) {
        // vector<int> inorder(n), preorder(n);
        // for(int i=0; i<n; i++) {
        // 	inorder[i] = in[i];
        // 	preorder[i] = pre[i];
        // }
        return buildBT(inorder, 0, n-1, preorder, 0, n-1);
    }
};

void postorder(Node* root) {
	if(root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
	return;
}

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<int> inorder(n), preorder(n);
    for(int i=0; i<n; i++) {
    	cin >> inorder[i];
    }
    for(int i=0; i<n; i++) {
    	cin >> preorder[i];
    }
    Node* root = solve.buildTree(inorder, preorder, n);
    postorder(root);
    cout << "\n";
    return 0;
}