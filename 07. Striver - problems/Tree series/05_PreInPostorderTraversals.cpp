#include <bits/stdc++.h>
using namespace std;

class Node{
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

#define pp pair<Node*,int>
#define fi first
#define se second
#define mp make_pair

void traversals(Node* root, vector<int>& preorder, vector<int>& inorder, vector<int>& postorder) {
	if(root == NULL) {
		return;
	}
	stack<pp> stk;
	stk.push(mp(root,1));
	while(!stk.empty()) {
		pp top = stk.top();
		stk.pop();
		int d1=top.fi->data, n1=top.se;
		Node* node = top.fi;
		if(n1 == 1) {
			preorder.push_back(d1);
			stk.push(mp(node, n1+1));
			if(node->left != NULL) {
				stk.push(mp(node->left,1));
			}
		}
		else if(n1 == 2) {
			inorder.push_back(d1);
			stk.push(mp(node, n1+1));
			if(node->right != NULL) {
				stk.push(mp(node->right,1));
			}
		}
		else if(n1 == 3) {
			postorder.push_back(d1);
			// No need to push back further
		}
	}
	return;
}

int main() {
	Node* root = takeInput();
	vector<int> preorder, inorder, postorder;
	traversals(root, preorder, inorder, postorder);
	for(int i=0; i<preorder.size(); i++) {
		cout << preorder[i] << " ";
	}
	cout << "\n";
	for(int i=0; i<inorder.size(); i++) {
		cout << inorder[i] << " ";
	}
	cout << "\n";
	for(int i=0; i<postorder.size(); i++) {
		cout << postorder[i] << " ";
	}
	cout << "\n";
	return 0;
}