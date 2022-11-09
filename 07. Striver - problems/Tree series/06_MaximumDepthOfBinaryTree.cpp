#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
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

class Solution{
public:
    int maxDepth(Node *root) {
        if(root == NULL) {
        	return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
	Node* root = takeInput();
	Solution solve;
	int ans = solve.maxDepth(root);
	cout << ans << "\n";
	return 0;
}