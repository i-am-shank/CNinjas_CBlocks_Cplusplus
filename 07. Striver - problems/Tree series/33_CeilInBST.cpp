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

void ceil(Node* root, int& input, int& nextMax) {
	if(root == NULL) {
		return;
	}
	if(root->data == input) {
		nextMax = root->data;
		return;
	}
	else if(root->data > input) {
		// A value greater than input exists
		nextMax = min(nextMax, root->data);
		ceil(root->left, input, nextMax); // search in left
	}
	else {
		ceil(root->right, input, nextMax);
	}
}

int findCeil(Node* root, int input) {
    if(root == NULL) {
    	return -1;
    }
    int nextMax = INT_MAX;
    ceil(root, input, nextMax);
    if(nextMax == INT_MAX) {
    	return -1;
    }
    return nextMax;
}

int main() {
	Node* root = takeInput();
	int input;
	cin >> input;
	int ans = findCeil(root, input);
	cout << ans << "\n";
	return 0;
}