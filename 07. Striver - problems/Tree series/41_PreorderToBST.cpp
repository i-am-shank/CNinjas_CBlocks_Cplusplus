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

Node* newNode(int data) {
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

class Solution{
	Node* preorder(vector<int>& pre, int ps, int pe) {
		if(ps > pe) {
			return NULL;
		}
		Node* root = newNode(pre[ps]);
		int rootData = pre[ps];
		int idx;
		for(idx=ps; idx<=pe; idx++) {
			if(pre[idx] > rootData) {
				break;
			}
		}
		Node* leftChild = preorder(pre, ps+1, idx-1);
		Node* rightChild = preorder(pre, idx, pe);
		root->left = leftChild;
		root->right = rightChild;
		return root;
	}

public:
    Node* post_order(vector<int> pre, int size) {
        Node* ans = preorder(pre, 0, size-1);
        return ans;
    }
};

void printTree(Node* root) {
	if(root == NULL) {
		return;
	}
	printTree(root->left);
	printTree(root->right);
	cout << root->data << " ";
	return;
}

int main() {
	int size;
	cin >> size;
	vector<int> pre(size);
	for(int i=0; i<size; i++) {
		cin >> pre[i];
	}
	Solution solve;
	Node* root = solve.post_order(pre, size);
	printTree(root);
	return 0;
}