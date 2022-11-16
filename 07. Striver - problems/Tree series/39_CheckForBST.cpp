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

#define ppp pair<pair<int,int>, bool>
// maxVal, minVal, bool
#define fi first
#define se second
#define mp make_pair

class Solution {
	ppp checkBST(Node* root) {
		if(root == NULL) {
			ppp ans;
			ans.fi = mp(INT_MIN, INT_MAX);
			ans.se = true;
			return ans;
		}
		ppp lans = checkBST(root->left);
		ppp rans = checkBST(root->right);
		ppp ans;
		int lmax=lans.fi.fi, rmax=rans.fi.fi;
		int lmin=lans.fi.se, rmin=rans.fi.se;
		bool lcheck=lans.se, rcheck=rans.se;
		int maxVal = max(root->data, max(lmax,rmax));
		int minVal = min(root->data, min(lmin,rmin));
		bool check = (lcheck && rcheck);
		check = (check && (root->data>lmax) && (root->data<rmin));
		ans.fi.fi=maxVal, ans.fi.se=minVal, ans.se=check;
		return ans;
	}

public:
	bool isBST(Node* root) {
        ppp ans = checkBST(root);
        return ans.se;
    }
};

int main() {
	Node* root = takeInput();
	Solution solve;
	bool ans = solve.isBST(root);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}