#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
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
			q.push(leftChild);
			front->left = leftChild;
		}
		if(rightData != -1) {
			Node* rightChild = new Node(rightData);
			q.push(rightChild);
			front->right = rightChild;
		}
	}
	return root;
}

vector<int> leftView(Node *root) {
	vector<int> ans;
	queue<Node*> q;
	if(root == NULL) {
		return ans;
	}
	q.push(root);
	while(!q.empty()) {
		int s = q.size();
		ans.push_back(q.front()->data);
		for(int i=0; i<s; i++) {
			Node* front = q.front();
			q.pop();
			if(front->left != NULL) {
				q.push(front->left);
			}
			if(front->right != NULL) {
				q.push(front->right);
			}
		}
	}
	return ans;
}

int main() {
	Node* root = takeInput();
	vector<int> ans = leftView(root);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}