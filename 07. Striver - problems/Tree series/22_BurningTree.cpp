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

class Solution {
	void buildGraph(Node* root, vector<vector<int>>& adj) {
		if(root == NULL) {
			return;
		}
		if(root->left != NULL) {
			adj[root->data].push_back(root->left->data);
			adj[root->left->data].push_back(root->data);
			buildGraph(root->left, adj);
		}
		if(root->right != NULL) {
			adj[root->data].push_back(root->left->data);
			adj[root->right->data].push_back(root->data);
			buildGraph(root->right, adj);
		}
		return;
	}

	Node* find(Node* root, int target) {
		if(root == NULL) {
			return NULL;
		}
		if(root->data == target) {
			return root;
		}
		Node* lans = find(root->left, target);
		Node* rans = find(root->right, target);
		if(lans != NULL) {
			return lans;
		}
		return rans;
	}

public:
    int minTime(Node* root, int target) {
    	if(root == NULL) {
    		return 0;
    	}
    	unordered_map<Node*,Node*> parent;
    	unordered_map<Node*,bool> visited;
    	// Set parent
    	queue<Node*> q;
    	q.push(root);
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
        if(tNode == NULL) {
        	return -1; // Never possible, just in-case..
        }
        int time=0;
        q.push(tNode);
        while(!q.empty()) {
        	time++;
        	int s = q.size();
        	for(int i=0; i<s; i++) {
        		Node* front = q.front();
        		q.pop();
        		if(front->left!=NULL && !visited[front->left]) {
        			visited[front->left] = true;
        			q.push(front->left);
        		}
        		if(front->right!=NULL && !visited[front->right]) {
        			visited[front->right] = true;
        			q.push(front->right);
        		}
        		if(parent[front]!=NULL && !visited[parent[front]]) {
        			visited[parent[front]] = true;
        			q.push(parent[front]);
        		}
        	}
        }
        if(time > 0) {
        	time--;
        }
        return time;
    }
};

int main() {
	Solution solve;
	Node* root = takeInput();
	int target;
	cin >> target;
	int ans = solve.minTime(root, target);
	cout << ans << "\n";
	return 0;
}