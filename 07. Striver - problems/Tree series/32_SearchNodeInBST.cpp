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

bool search(Node* root, int x) {
    if(root == NULL) {
    	return false;
    }
    if(x == root->data) {
    	return true;
    }
    else if(x > root->data) {
    	return search(root->right, x);
    }
    else {
    	return search(root->left, x);
    }
}

int main() {
	Node* root = takeInput();
	int x;
	cin >> x;
	bool ans = search(root, x);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}