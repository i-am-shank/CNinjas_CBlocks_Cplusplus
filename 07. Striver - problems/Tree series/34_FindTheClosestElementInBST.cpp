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

class Solution {
	void findDiff(Node* root, int& k, int& diff) {
		if(root == NULL) {
			return;
		}
		if(root->data == k) {
			diff = 0;
			return;
		}
		else if(root->data > k) {
			diff = min(diff, root->data-k);
			findDiff(root->left, k, diff);
		}
		else {
			diff = min(diff, k-root->data);
			findDiff(root->right, k, diff);
		}
	}

public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int k) {
        int diff = INT_MAX;
        findDiff(root, k, diff);
        if(diff == INT_MAX) {
        	return -1;
        }
        return diff;
    }
};

int main() {
	Node* root = takeInput();
	int k;
	cin >> k;
	Solution solve;
	int ans = solve.minDiff(root, k);
	cout << ans << "\n";
	return 0;
}