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
    int isSumProperty(Node* root) {
    	if(root == NULL) {
    		return 1;
    	}
    	int lans = isSumProperty(root->left);
    	int rans = isSumProperty(root->right);
    	if(lans==1 && rans==1) {
    		int sum=0;
    		if(root->left!=NULL) {
    			sum += root->left->data;
    		}
    		if(root->right!=NULL) {
    			sum += root->right->data;
    		}
    		if(sum==root->data || (root->left==NULL && root->right==NULL)) {
    			return 1;
    		}
    		else {
    			return 0;
    		}
    	}
    	else {
    		return 0;
    	}
    }
};

int main() {
	Solution solve;
	Node* root = takeInput();
	int ans = solve.isSumProperty(root);
	cout << ans << "\n";
	return 0;
}