#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
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
			q.push(leftChild);
			front->left = leftChild;
		}
		if(rightData != -1) {
			Node* rightChild = new Node(rightData);
			q.push(rightChild);
			front->right = rightChild;
		}
	}
	return root;
}

class Solution{
	bool symmetric(Node* root1, Node* root2) {
		if(root1==NULL && root2==NULL) {
			return true;
		}
		if(root1==NULL || root2==NULL) {
			return false;
		}
		if(root1->data == root2->data) {
			bool ans1 = symmetric(root1->left, root2->right);
			bool ans2 = symmetric(root1->right, root2->left);
			return (ans1 && ans2);
		}
		else {
			return false;
		}
	}

public:
    bool isSymmetric(struct Node* root) {
	    // Code here
	    bool ans = symmetric(root->left, root->right);
	    return ans;
    }
};

int main() {
	Solution solve;
	Node* root = takeInput();
	bool ans = solve.isSymmetric(root);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}