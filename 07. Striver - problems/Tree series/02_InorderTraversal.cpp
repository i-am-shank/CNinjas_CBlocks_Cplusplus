#include <bits/stdc++.h>
using namespace std;

struct Node {
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
	void inorderBT(Node* root, vector<int>& ans) {
		if(root == NULL) {
			return;
		}
		inorderBT(root->left, ans);
		ans.push_back(root->data);
		inorderBT(root->right, ans);
		return;
	}

public:
	vector<int> inorderStack(Node* root) {
		vector<int> ans;
		if(root == NULL) {
			return ans;
		}
		stack<Node*> stk;
		stk.push(root);
		root = root->left;
		while(!stk.empty()) {
			if(root != NULL) {
				// Keep going left
				stk.push(root);
				root = root->left;
			}
			else {
				Node* top = stk.top();
				ans.push_back(top->data);
				stk.pop();
				// Gone to a NULL node
				// Go to right of left-most node non-NULL
				root = top->right;
			}
		}
		return ans;
	}

    vector<int> inOrder(Node* root) {
        vector<int> ans;
        inorderBT(root, ans);
        return ans;
    }
};

int main() {
	Node* root = takeInput();
	Solution solve;
	vector<int> ans = solve.inOrder(root);
	vector<int> ans2 = solve.inorderStack(root);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	for(int i=0; i<ans2.size(); i++) {
		cout << ans2[i] << " ";
	}
	cout << "\n";
	return 0;
}