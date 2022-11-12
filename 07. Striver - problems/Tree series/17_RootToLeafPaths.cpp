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

void findPaths(Node* root, vector<vector<int>>& ans, vector<int>& path) {
	path.push_back(root->data);
	if(root->left==NULL && root->right==NULL) {
		ans.push_back(path);
		return;
	}
	findPaths(root->left, ans, path);
	path.pop_back();
	findPaths(root->right, ans, path);
	path.pop_back();
	return;
}

vector<vector<int>> Paths(Node* root) {
    vector<vector<int>> ans;
    vector<int> path;
    findPaths(root, ans, path);
    return ans;
}

int main() {
	Node* root = takeInput();
	vector<vector<int>> ans = Paths(root);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "#";
	}
	return 0;
}