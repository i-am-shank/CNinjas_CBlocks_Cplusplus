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

class Solution {
public:
    Node* lca(Node* root, int n1, int n2) {
    	if(root == NULL) {
    		return NULL;
    	}
    	if(root->data==n1 || root->data==n2) {
    		return root;
    	}
    	else {
    		Node* lans = lca(root->left, n1, n2);
    		Node* rans = lca(root->right, n1, n2);
    		if(lans!=NULL && rans!=NULL) {
    			return root;
    		}
    		else if(lans!=NULL) {
    			return lans;
    		}
    		else {
    			return rans;
    		}
    	}
    }
};

int main() {
	Solution solve;
	Node* root = takeInput();
	int n1, n2;
	cin >> n1 >> n2;
	Node* ans = solve.lca(root, n1, n2);
	if(ans == NULL) {
		cout << -1 << "\n";
	}
	else {
		cout << ans->data << "\n";
	}
	return 0;
}