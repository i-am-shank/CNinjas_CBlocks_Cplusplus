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

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
	Node* temp = root;
	while(temp != NULL) {
		if(temp->data > key) {
			suc = temp;
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	temp = root;
	while(temp != NULL) {
		if(temp->data < key) {
			pre = temp;
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
	return;
}

int main() {
	Node* root = takeInput();
	Node* pre = NULL;
	Node* suc = NULL;
	int key;
	cin >> key;
	findPreSuc(root, pre, suc, key);
	if(pre == NULL) {
		cout << -1 << " ";
	}
	else {
		cout << pre->data << " ";
	}
	if(suc == NULL) {
		cout << -1 << "\n";
	}
	else {
		cout << suc->data << "\n";
	}
	return 0;
}