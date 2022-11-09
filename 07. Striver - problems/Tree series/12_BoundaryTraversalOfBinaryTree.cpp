#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
};

Node* takeInput() {
	int rootData;
	cin >> rootData;
	if(rootData == -1) {
		return NULL;
	}
	Node* root = new Node();
	root->data = rootData;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* front = q.front();
		q.pop();
		int leftData, rightData;
		cin >> leftData >> rightData;
		if(leftData != -1) {
			Node* leftChild = new Node();
			leftChild->data = leftData;
			front->left = leftChild;
			q.push(leftChild);
		}
		if(rightData != -1) {
			Node* rightChild = new Node();
			rightChild->data = rightData;
			front->right = rightChild;
			q.push(rightChild);
		}
	}
	return root;
}

class Solution {
	bool isLeaf(Node* root) {
		return (root->left==NULL && root->right==NULL);
	}

	void leftBoundary(Node* root, vector<int>& ans) {
		if(root==NULL) {
			return;
		}
		// pre-order addition
		Node* curr = root->left;
		while(curr != NULL) {
			if(!isLeaf(curr)) {
				ans.push_back(curr->data);
			}
			if(curr->left != NULL) {
				curr = curr->left;
			}
			else {
				curr = curr->right;
			}
		}
		return;
	}

	void leafNodes(Node* root, vector<int>& ans) {
		if(root == NULL) {
			return;
		}
		if(isLeaf(root)) {
			ans.push_back(root->data);
			return;
		}
		// If non-leaf  -->  in-order addition
		if(root->left != NULL) {
			leafNodes(root->left, ans);
		}
		if(root->right != NULL) {
			leafNodes(root->right, ans);
		}
		return;
	}

	void rightBoundary(Node* root, vector<int>& ans) {
		if(root == NULL) {
			return;
		}
		// post-order addition (add pre-order .. reverse)
		Node* curr = root->right;
		stack<int> stk;
		while(curr != NULL) {
			if(!isLeaf(curr)) {
				stk.push(curr->data);
			}
			if(curr->right != NULL) {
				curr = curr->right;
			}
			else {
				curr = curr->left;
			}
		}
		while(!stk.empty()) {
			ans.push_back(stk.top());
			stk.pop();
		}
		return;
	}

public:
    vector<int> boundary(Node *root) {
        vector<int> ans;
        if(root == NULL) {
        	return ans;
        }
        ans.push_back(root->data);
        leftBoundary(root, ans);
        if(!isLeaf(root)) {
        	leafNodes(root, ans);
        }
        rightBoundary(root, ans);
        return ans;
    }
};



int main() {
	Solution solve;
	Node* root = takeInput();
	vector<int> ans = solve.boundary(root);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}