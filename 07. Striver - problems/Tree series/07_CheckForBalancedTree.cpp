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

#define pp pair<bool,int> // isBalanced , height
#define fi first
#define se second
#define mp make_pair

class Solution{
	pp balancedHeight(Node *root) {
		if(root == NULL) {
			pp ans = mp(true, 0);
			return ans;
		}
		pp lans = balancedHeight(root->left);
		pp rans = balancedHeight(root->right);
		int h = (1+max(lans.se, rans.se));
		bool check = (lans.fi && rans.fi); // balanced subtrees
		check = (check && (abs(lans.se-rans.se)<=1)); // diff. height <= 1
		pp ans = mp(check, h);
		return ans;
	}

public:
    bool isBalanced(Node *root) {
        pp ans = balancedHeight(root);
        return ans.fi;
    }
};

int main() {
	Solution solve;
	Node* root = takeInput();
	bool ans = solve.isBalanced(root);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}