#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
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

class Solution{
	int height(Node* root) {
		if(root == NULL) {
			return 0;
		}
		return 1 + max(height(root->left), height(root->right));
	}

public:    
    bool isCompleteBT(Node* root){
    	if(root == NULL) {
    		return true;
    	}
        int h = height(root);
        queue<Node*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
        	level++;
        	if(level == h-1) {
        		int s = q.size();
        		if(s != (1<<(level-1))) {
        			return false; // Incomplete level
        		}
        		else {
        			// Check if below-level filled from left
        			bool nullFound = false;
        			for(int i=0; i<s; i++) {
        				Node* front = q.front();
        				q.pop();
        				if(front->left != NULL) {
        					if(nullFound == true) {
        						// Non-null node after null
        						return false;
        					}
        					// Not push last-level (not needed)
        				}
        				else {
        					nullFound = true;
        				}
        				if(front->right != NULL) {
        					if(nullFound == true) {
        						return false;
        					}
        					// Not push last-level (not needed)
        				}
        				else {
        					nullFound = true;
        				}
        			}
        		}
        	}
        	else {
        		int s = q.size();
        		if(s != (1<<(level-1))) {
        			return false; // Incomplete level
        		}
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
        }
        return true; // If all tests passed
    }
};

int main() {
	Solution solve;
	Node* root = takeInput();
	bool ans = solve.isCompleteBT(root);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}