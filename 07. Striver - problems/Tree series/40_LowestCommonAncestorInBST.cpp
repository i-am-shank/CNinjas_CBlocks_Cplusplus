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

Node* LCA(Node *root, int n1, int n2) {
	if(n1 > n2) {
		return LCA(root, n2, n1);
	}
	if(root == NULL) {
		return NULL;
	}
	if((n1==root->data) || (n2==root->data) || (n1<root->data&&n2>root->data)) {
		return root;
	}
	else if(n2 < root->data) {
		return LCA(root->left, n1, n2);
	}
	else {
		return LCA(root->right, n1, n2);
	}
}

int main() {
	Node* root = takeInput();
	int n1, n2;
	cin >> n1 >> n2;
	Node* ans = LCA(root, n1, n2);
	cout << ans->data << "\n";
	return 0;
}