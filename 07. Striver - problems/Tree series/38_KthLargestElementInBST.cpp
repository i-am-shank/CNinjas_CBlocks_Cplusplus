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
	int kthLargestEle(Node* root, int k, int &c) {
		if(root == NULL) {
			return -1;
		}
		int rans = kthLargestEle(root->right, k, c);
		if(rans != -1) {
			return rans;
		}
		c++;
		if(c == k) {
			return root->data;
		}
		int lans = kthLargestEle(root->left, k, c);
		if(lans != -1) {
			return lans;
		}
		else {
			return -1;
		}
	}

public:
    int kthLargest(Node *root, int k) {
    	int c = 0;
        int ans = kthLargestEle(root, k, c);
        return ans;
    }
};

int main() {
	Node* root = takeInput();
	int k;
	cin >> k;
	Solution solve;
	int ans = solve.kthLargest(root, k);
	cout << ans << "\n";
	return 0;
}