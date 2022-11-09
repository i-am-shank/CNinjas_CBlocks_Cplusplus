#include <bits/stdc++.h>
using namespace std;

class Node {
public:
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

class Solution {
	int findMaxPath(Node* root, int& maxSum) {
		if(root == NULL) {
			return 0;
		}
		int lans = findMaxPath(root->left, maxSum);
		int rans = findMaxPath(root->right, maxSum);
		int currSum = max(root->data, (root->data)+max(lans,rans));
		maxSum = max(maxSum, max(currSum, (root->data)+lans+rans));
		return currSum;
	}

public:
    int findMaxSum(Node* root) {
        int maxSum = INT_MIN;
        int ans = findMaxPath(root, maxSum);
        return maxSum;
    }
};

int main() {
	Solution solve;
	Node* root = takeInput();
	int ans = solve.findMaxSum(root);
	cout << ans << "\n";
	return 0;
}