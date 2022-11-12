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
			front->left = leftChild;
			q.push(leftChild);
		}
		if(rightData != -1) {
			TreeNode* rightChild = new TreeNode(rightData);
			front->right = rightChild;
			q.push(rightChild);
		}
	}
	return root;
}

class Solution {
	int maxPath(TreeNode* root, int &maxSum) {
		if(root == NULL) {
			return 0;
		}
		int lans = maxPath(root->left, maxSum);
		int rans = maxPath(root->right, maxSum);
		// max. Vertical-path from root till its leaves
		//    .. (must contain root)
		int vertMax = max(root->val, (root->val+max(lans,rans)));
		// max. Horizontal-path passing through root (having some left-nodes & right-nodes)
		//    .. (must contain root)
		int horzMax = root->val + lans + rans;
		// maxSum will be update for each node's (vertical max.) & (horizontal max.)
		maxSum = max(maxSum, max(vertMax, horzMax));
		return vertMax;
	}

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ans = maxPath(root, maxSum);
        return maxSum;
    }
};

int main() {
	TreeNode* root = takeInput();
	Solution solve;
	int ans = solve.maxPathSum(root);
	cout << ans << "\n";
	return 0;
}