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
	bool check(Node* root, int target, set<int>& values) {
		if(root == NULL) {
			return false;
		}
		if(check(root->left,target,values) == true) {
			return true;
		}
		values.insert(root->data);
		if(values.find(target-root->data) != values.end()) {
			return true;
		}
		if(check(root->right,target,values) == true) {
			return true;
		}
		return false;
	}

public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(Node *root, int target) {
    	if(root == NULL) {
    		return 0;
    	}
    	set<int> values;
    	bool ans = check(root, target, values);
    	if(ans == true) {
    		return 1;
    	}
    	else {
    		return 0;
    	}
    }
};

int main() {
	Solution solve;
	Node* root = takeInput();
	int target;
	cin >> target;
	int ans = solve.isPairPresent(root, target);
	cout << ans << "\n";
	return 0;
}