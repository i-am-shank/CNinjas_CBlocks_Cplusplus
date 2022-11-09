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

vector<int> findSpiral(Node *root) {
    vector<int> ans;
    if(root == NULL) {
    	return ans;
    }
    queue<Node*> q;
    q.push(root);
    int level=0; // Even -> same  ,  Odd -> reverse
    while(!q.empty()) {
    	vector<int> currLevel;
    	int s = q.size();
    	level++;
    	for(int i=0; i<s; i++) {
    		Node* front = q.front();
    		q.pop();
    		currLevel.push_back(front->data);
    		if(front->left != NULL) {
    			q.push(front->left);
    		}
    		if(front->right != NULL) {
    			q.push(front->right);
    		}
    	}
    	if(level % 2 != 0) {
    		// Have to reverse .. odd-level
    		reverse(currLevel.begin(), currLevel.end());
    	}
    	for(int i=0; i<currLevel.size(); i++) {
    		ans.push_back(currLevel[i]);
    	}
    }
    return ans;
}

int main() {
	Node* root = takeInput();
	vector<int> ans = findSpiral(root);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}