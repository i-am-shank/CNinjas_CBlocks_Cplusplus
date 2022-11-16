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

Node* postorder(vector<int>& post, int ps, int pe) {
	if(ps > pe) {
		return NULL;
	}
	int rootData = post[pe];
	Node* root = new Node(rootData);
	int idx;
	for(idx=ps; idx<pe; idx++) {
		if(post[idx] > rootData) {
			// Right sub-tree started from idx
			break;
		}
	}
	Node* leftChild = postorder(post, ps, idx-1);
	Node* rightChild = postorder(post, idx, pe-1);
	root->left = leftChild;
	root->right = rightChild;
	return root;
}

Node *constructTree(vector<int> post, int size) {
	// vector<int> p(size);
	// for(int i=0; i<size; i++) {
	// 	p[i] = post[i];
	// }
	Node* ans = postorder(post, 0, size-1);
	return ans;
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
	int size;
	cin >> size;
	vector<int> post(size);
	for(int i=0; i<size; i++) {
		cin >> post[i];
	}
	Node* root = constructTree(post, size);
	printTree(root);
	return 0;
}