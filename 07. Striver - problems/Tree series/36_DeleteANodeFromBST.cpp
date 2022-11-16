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

void printTree(Node* root) {
	if(root == NULL) {
		return;
	}
	printTree(root->left);
	cout << root->data << " ";
	printTree(root->right);
	return;
}

Node *deleteNode(Node *root, int x) {
    if(root == NULL) {
    	return NULL;
    }
    if(root->data == x) {
    	if(root->left==NULL && root->right==NULL) {
    		return NULL;
    	}
    	else if(root->left!=NULL && root->right==NULL) {
    		return root->left;
    	}
    	else if(root->right!=NULL && root->left==NULL) {
    		return root->right;
    	}
    	else {
    		// Both child non-NULL of deleted node
    		Node* temp = root->left;
    		while(temp->right != NULL) {
    			temp = temp->right;
    		}
    		// temp  -->  right-most node of left-child
    		// All root->right - nodes are greater than this node
    		temp->right = root->right; // Joining them to right
    		return root->left;
    	}
    }
    else if(x < root->data) {
    	root->left = deleteNode(root->left, x);
    }
    else {
    	root->right = deleteNode(root->right, x);
    }
    return root;
}

int main() {
	Node* root = takeInput();
	int x;
	cin >> x;
	Node* root2 = deleteNode(root, x);
	printTree(root2);
	return 0;
}