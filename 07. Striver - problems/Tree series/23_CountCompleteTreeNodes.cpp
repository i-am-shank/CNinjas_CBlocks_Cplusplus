#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* takeInput() {
	int rootData;
	cin >> rootData;
	if(rootData == -1) {
		return NULL;
	}
	TreeNode* root = new TreeNode(rootData);
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()) {
		TreeNode* front = q.front();
		q.pop();
		int leftData, rightData;
		cin >> leftData >> rightData;
		if(leftData != -1) {
			TreeNode* leftChild = new TreeNode(leftData);
			q.push(leftChild);
			front->left = leftChild;
		}
		if(rightData != -1) {
			TreeNode* rightChild = new TreeNode(rightData);
			q.push(rightChild);
			front->right = rightChild;
		}
	}
	return root;
}

#define pp pair<int,int>
#define fi first
#define se second
#define mp make_pair

class Solution {
	int leftHeight(TreeNode* root) {
		if(root == NULL) {
			return 0;
		}
		return 1 + leftHeight(root->left);
	}

	int rightHeight(TreeNode* root) {
		if(root == NULL) {
			return 0;
		}
		return 1 + rightHeight(root->right);
	}

public:
	// Time : O(logN ^ 2)
	//   ..Traversing total of (logN) nodes only (2 nodes max. in each level)
	//   ..and calculating height of all of them (worst case)
	//   ..logN (height calculation) for logN nodes.
	
	// Space : O(logN) .. maximum all level nodes wait in recursion stack
    int countNodes(TreeNode* root) {
        if(root == NULL) {
        	return 0;
        }
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if(lh == rh) {
        // Subtree with current node as root, Complete Binary tree
        	int count = (1<<lh) - 1; // 2^h - 1
        	return count;
        }
        else {
        	return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};

int main() {
	TreeNode* root = takeInput();
	Solution solve;
	int ans = solve.countNodes(root);
	cout << ans << "\n";
	return 0;
}