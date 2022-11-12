#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
};

Node* takeInput() {
	int rootData;
	cin >> rootData;
	if(rootData == -1) {
		return NULL;
	}
	Node* root = new Node();
	root->data = rootData;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* front = q.front();
		q.pop();
		int leftData, rightData;
		cin >> leftData >> rightData;
		if(leftData != -1) {
			Node* leftChild = new Node();
			leftChild->data = leftData;
			q.push(leftChild);
			front->left = leftChild;
		}
		if(rightData != -1) {
			Node* rightChild = new Node();
			rightChild->data = rightData;
			q.push(rightChild);
			front->right = rightChild;
		}
	}
	return root;
}

class Solution {
	Node* find(Node* root, int target) {
		if(root == NULL) {
			return NULL;
		}
		if(root->data == target) {
			return root;
		}
		Node* lans = find(root->left, target);
		Node* rans = find(root->right, target);
		if(lans!=NULL) {
			return lans;
		}
		else {
			return rans;
		}
	}

	void findNodes(Node* root, int k, unordered_map<Node*,Node*>& parent, vector<int>& ans, unordered_map<Node*,bool>& visited) {
		if(root == NULL) {
			return;
		}
		if(k == 0) {
			ans.push_back(root->data);
			return;
		}
		if(root->left!=NULL && (!visited[root->left])) {
			visited[root->left] = true;
			findNodes(root->left, k-1, parent, ans, visited);
		}
		if(root->right!=NULL && (!visited[root->right])) {
			visited[root->right] = true;
			findNodes(root->right, k-1, parent, ans, visited);
		}
		if(parent[root]!=NULL && (!visited[parent[root]])) {
			visited[parent[root]] = true;
			findNodes(parent[root], k-1, parent, ans, visited);
		}
		return;
	}

public:
    vector<int> KDistanceNodes(Node* root, int target , int k) {
    	vector<int> ans;
    	if(root == NULL) {
    		return ans;
    	}
        unordered_map<Node*, Node*> parent;
        queue<Node*> q;
        q.push(root);
        parent[root] = NULL;
        while(!q.empty()) {
        	Node* front = q.front();
        	q.pop();
        	if(front->left != NULL) {
        		parent[front->left] = front;
        		q.push(front->left);
        	}
        	if(front->right != NULL) {
        		parent[front->right] = front;
        		q.push(front->right);
        	}
        }
        Node* tNode = find(root, target);
        unordered_map<Node*, bool> visited;
        visited[tNode] = true;
        findNodes(tNode, k, parent, ans, visited);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
	Node* root = takeInput();
	int target, k;
	cin >> target >> k;
	Solution solve;
	vector<int> ans = solve.KDistanceNodes(root, target, k);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}