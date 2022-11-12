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
    int getMaxWidth(Node* root) {
    	int maxAns = 0;
    	if(root == NULL) {
    		return maxAns;
    	}
    	queue<Node*> q;
    	q.push(root);
    	while(!q.empty()) {
    		int curr = q.size();
    		maxAns = max(maxAns, curr);
    		for(int i=0; i<curr; i++) {
    			Node* front = q.front();
    			q.pop();
    			if(front->left != NULL) {
    				q.push(front->left);
    			}
    			if(front->right != NULL) {
    				q.push(front->right);
    			}
    		}
    	}
    	return maxAns;
    }
};

int main() {
	Solution solve;
	Node* root = takeInput();
	int ans = solve.getMaxWidth(root);
	cout << ans << "\n";
	return 0;
}