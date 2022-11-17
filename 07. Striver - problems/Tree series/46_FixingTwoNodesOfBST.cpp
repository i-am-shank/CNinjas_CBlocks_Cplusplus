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

#define ppp pair<pair<int,int>, bool>
// max, min, bool
#define fi first
#define se second
#define mp make_pair

class Solution {
	Node *first, *prev, *middle, *last;

	void inorderTraversal(Node* root) {
		if(root == NULL) {
			return;
		}
		inorderTraversal(root->left);
		if(prev!=NULL && (root->data<prev->data)) {
			// Violation found
			if(first == NULL) { // If 1st violation :-
				first = prev;
				middle = root;
			}
			else { // Else .. 2nd violation :-
				last = root;
			}
		}
		// Update previous node
		prev = root;
		inorderTraversal(root->right);
		return;
	}

public:
    void correctBST(Node* root) {
        first = middle = last = NULL;
        prev = new Node(INT_MIN);
        inorderTraversal(root);
        if(first!=NULL && last!=NULL) { // 2 violations happened
        	swap(first->data, last->data);
        }
        else if(first!=NULL && middle!=NULL) { // only 1 violation
        	swap(first->data, middle->data);
        }
        return;
    }
};

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
	Solution solve;
	Node* root = takeInput();
	solve.correctBST(root);
	printTree(root);
	return 0;
}