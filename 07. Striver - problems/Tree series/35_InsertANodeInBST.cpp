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

Node* insert(Node* root, int key) {
    if(root == NULL) {
    	Node* n1 = new Node(key);
    	return n1;
    }
    if(root->data == key) {
    	return root; // No change required
    }
    else if(key < root->data) {
    	root->left = insert(root->left, key);
    }
    else {
    	root->right = insert(root->right, key);
    }
    return root;
}

void printTree(Node* root) {
	if(root == NULL) {
		return;
	}
	printTree(root->left);
	cout << root->data << " ";
	printTree(root->right);
	return;
}

int main() {
	Node* root = takeInput();
	int key;
	cin >> key;
	Node* root2 = insert(root, key);
	printTree(root2);
	return 0;
}