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

class Solution{
	Node* find(Node* root, Node* x, int&)

public:
    Node *inOrderSuccessor(Node *root, Node *x) {
        if(root == NULL) {
        	return NULL;
        }
        if(x->data == root->data) {
        	Node* ans = root->right;
        	if(ans == NULL) {
        		return ans;
        	}
        	else {
        		while(ans->left != NULL) {
        			ans = ans->left;
        		}
        		return ans;
        	}
        }
        else if(x->data > root->data) {
        	return inOrderSuccessor(root->right, x);
        }
        else {
        	return inOrderSuccessor(root->left, x);
        }
    }
};

int main() {
	Node* root = takeInput();
	Node* x = takeInput();
	Solution solve;
	Node* ans = solve.inOrderSuccessor(root, x);
	if(ans == NULL) {
		cout << -1 << "\n";
	}
	else {
		cout << ans->data << "\n";
	}
	return 0;
}