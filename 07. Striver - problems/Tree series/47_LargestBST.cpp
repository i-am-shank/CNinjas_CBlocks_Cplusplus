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

#define ppp pair<pair<int,int>, pair<bool,int>>
// max, min   ..   checkBST, size
#define fi first
#define se second
#define mp make_pair

class Solution{
	ppp maxBST(Node* root, int& maxSize) {
		if(root == NULL) {
			ppp ans;
			ans.fi.fi=INT_MIN, ans.fi.se=INT_MAX;
			ans.se.fi=true, ans.se.se=0;
			return ans;
		}
		ppp lans = maxBST(root->left, maxSize);
		ppp rans = maxBST(root->right, maxSize);
		ppp ans;
		int lmax=lans.fi.fi, lmin=lans.fi.se, lsize=lans.se.se;
		bool lcheck=lans.se.fi;
		int rmax=rans.fi.fi, rmin=rans.fi.se, rsize=rans.se.se;
		bool rcheck=rans.se.fi;
		int maxVal = max(root->data, max(lmax,rmax));
		int minVal = min(root->data, min(lmin,rmin));
		int size = lsize+rsize+1;
		bool check = (rcheck && lcheck);
		check = check && (root->data>lmax) && (root->data<rmin);
		if(check == true) {
			maxSize = max(maxSize, size);
		}
		ans.fi.fi=maxVal, ans.fi.se=minVal, ans.se.fi=check, ans.se.se=size;
		return ans;
	}

public:
    int largestBst(Node *root) {
    	int maxSize = 0;
    	ppp ans = maxBST(root, maxSize);
    	return maxSize;
    }
};

int main() {
	Solution solve;
	Node* root = takeInput();
	int ans = solve.largestBst(root);
	cout << ans << "\n";
	return 0;
}