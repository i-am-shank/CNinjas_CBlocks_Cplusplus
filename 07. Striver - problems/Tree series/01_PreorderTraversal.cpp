#include <bits/stdc++.h>
using namespace std;

struct Node
{
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

// Time : O(n) .. Traversed all nodes
// Space : O(n) .. At most all nodes are in recursion stack
void preorderBT(Node* root, vector<int> &ans) {
	if(root == NULL) {
		return;
	}
	ans.push_back(root->data);
	preorderBT(root->left, ans);
	preorderBT(root->right, ans);
	return;
}

vector<int> preorderStack(Node* root) {
	vector<int> ans;
	if(root == NULL) {
		return ans;
	}
	stack<Node*> stk;
	stk.push(root);
	while(!stk.empty()) {
		Node* top = stk.top();
		stk.pop();
		ans.push_back(top->data);
		// As in stack.. elements are taken out in reverse order
		// We need left-subtree first, so push it at last
		if(top->right != NULL) {
			stk.push(top->right);
		}
		if(top->left != NULL) {
			stk.push(top->left);
		}
	}
	return ans;
}

vector<int> preorder(Node* root) {
	vector<int> ans;
	preorderBT(root, ans);
	return ans;
}

int main() {
	Node* root = takeInput();
	vector<int> ans = preorder(root);
	vector<int> ans2 = preorderStack(root);
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