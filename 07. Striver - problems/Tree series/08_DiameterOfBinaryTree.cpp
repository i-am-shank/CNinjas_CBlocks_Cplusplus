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

#define pp pair<int,int>
#define fi first
#define se second
#define mp make_pair

class Solution {
	pp heightDia(Node* root) {
		if(root == NULL) {
			pp ans = mp(0,0);
			return ans;
		}
		pp lans = heightDia(root->left);
		pp rans = heightDia(root->right);
		int lh=lans.fi, ld=lans.se, rh=rans.fi, rd=rans.se;
		int h = 1 + max(lh, rh);
		int d = max(1+lh+rh , max(ld,rd));
		pp ans = mp(h,d);
		return ans;
	}

public:
    int diameter(Node* root) {
    	pp hd = heightDia(root);
    	return hd.se;
    }
};

int main() {
	Solution solve;
	Node* root = takeInput();
	int ans = solve.diameter(root);
	cout << ans << "\n";
	return 0;
}