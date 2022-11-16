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

void printTreeLL(Node* root) {
	if(root == NULL) {
		return;
	}
	Node* temp = root;
	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->right;
	}
	return;
}

class Solution {
public:
    void flatten(Node *root) {
        if(root == NULL) {
        	return;
        }
        if(root->left != NULL) {
        	flatten(root->left);
        	Node* temp = root->right; // saving root->right
        	root->right = root->left;
        	root->left = NULL;
        	Node* t = root->right; // This is flattened root->left
        	// Traverse to it's rightmost node (to attach root->right)
        	while(t->right != NULL) {
        		t = t->right;
        	}
        	t->right = temp; // root->right (of initial root) attached
        	// .. at rightmost node of flattened root->left
        }
        // Either root->left is NULL or not, we have to flatten root->right
        flatten(root->right); // If it's NULL, no process is done
        return;
    }
};

int main() {
	Solution solve;
	Node* root = takeInput();
	solve.flatten(root);
	printTreeLL(root);
	return 0;
}