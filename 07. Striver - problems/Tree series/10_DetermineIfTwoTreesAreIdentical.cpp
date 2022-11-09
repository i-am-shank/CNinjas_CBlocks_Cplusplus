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

class Solution {
public:
    bool isIdentical(Node *r1, Node *r2) {
        if(r1==NULL && r2==NULL) {
        	return true;
        }
        if(r1==NULL || r2==NULL) {
        	return false;
        }
        if(r1->data == r2->data) {
        	bool lans = isIdentical(r1->left, r2->left);
        	bool rans = isIdentical(r1->right, r2->right);
        	return (lans==true && rans==true);
        }
        else {
        	return false;
        }
    }
};

int main() {
	Node* r1 = takeInput();
	Node* r2 = takeInput();
	Solution solve;
	bool ans = solve.isIdentical(r1, r2);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}