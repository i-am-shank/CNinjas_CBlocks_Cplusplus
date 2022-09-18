#include <bits/stdc++.h>
using namespace std;

// Structure of node
struct Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
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
	bool isComplete(struct Node* tree) {
		if(tree == NULL) {
			return true;
		}
		queue<Node*> q;
		q.push(tree);
		bool nullFound = false;
		while(!q.empty()) {
			Node* front = q.front();
			q.pop();
			if(front == NULL) {
				nullFound = true;
			}
			else {
				if(nullFound == true) {
					// A non-null node found after getting NULL in level-order traversal
					return false;
				}
				q.push(front->left); // Push all child of non-null front
				q.push(front->right); // Whether NULL or non-NULL
			}
		}
		return true; // incompleteness not found till end
	}

	bool isMaxHeap(struct Node* tree) {
		if(tree == NULL) {
			return true;
		}
		bool leftAns=true, rightAns=true;
		if(tree->left != NULL) {
			if(tree->left->data > tree->data) {
				return false;
			}
			leftAns = isMaxHeap(tree->left);
		}
		if(tree->right != NULL) {
			if(tree->right->data > tree->data) {
				return false;
			}
			rightAns = isMaxHeap(tree->right);
		}
		return (leftAns && rightAns);
	}

  public:
    bool isHeap(struct Node* tree) {
        // code here
    	bool check1 = isComplete(tree);
    	bool check2 = isMaxHeap(tree);
    	return (check1 && check2);
    }
};

int main() {
	Solution solve;
	Node* tree = takeInput();
	bool ans = solve.isHeap(tree);
	cout << ans << endl;
	return 0;
}