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

class Solution {
public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        if(root == NULL) {
        	return ans;
        }
        stack<Node*> stk;
        stk.push(root);
        root = root->left;
        while(!stk.empty() || root!=NULL) {
        	if(root != NULL) {
        		stk.push(root);
        		root = root->left;
        	}
        	else {
        		Node* top = stk.top();
        		stk.pop();
        		ans.push_back(top->data);
        		root = top->right;
        	}
        }
        return ans;
    }
};

int main() {
	Solution solve;
	Node* root = takeInput();
	vector<int> ans = solve.inOrder(root);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}