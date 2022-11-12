#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
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
			q.push(leftChild);
			front->left = leftChild;
		}
		if(rightData != -1) {
			Node* rightChild = new Node(rightData);
			q.push(rightChild);
			front->right = rightChild;
		}
	}
	return root;
}

class Solution {
	#define pp pair<Node*, int>
	#define fi first
	#define se second
	#define mp make_pair

	void traverse(Node* root, map<int,vector<int>>& lines, int line) {
		if(root == NULL) {
			return;
		}
		queue<pp> q;
		q.push(mp(root,0));
		while(!q.empty()) {
			pp front = q.front();
			q.pop();
			Node* n=front.fi;
			int line=front.se;
			lines[line].push_back(n->data);
			if(n->left != NULL) {
				q.push(mp(n->left,line-1));
			}
			if(n->right != NULL) {
				q.push(mp(n->right,line+1));
			}
		}
		return;
	}

public:
	vector<int> verticalOrder(Node *root) {
        vector<int> ans;
        map<int,vector<int>> lines;
        traverse(root, lines, 0);
        for(auto it: lines) {
        	vector<int> v = it.second;
        	for(int i=0; i<v.size(); i++) {
        		ans.push_back(v[i]);
        	}
        }
        return ans;
    }
};

int main() {
	Solution solve;
	Node* root = takeInput();
	vector<int> ans = solve.verticalOrder(root);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}