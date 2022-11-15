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

class Solution{
public:
    vector<int> postOrder(Node* node) {
        vector<int> ans;
        if(node == NULL) {
        	return ans;
        }
        stack<Node*> stk;
        Node *curr=node, *temp=NULL;
        // left..left..  if NULL   --> right  left..left..
        while(curr!=NULL || !stk.empty()) {
        	if(curr != NULL) {
        		stk.push(curr);
        		curr = curr->left;
        	}
        	else {
        		temp = stk.top()->right; // Move right once
        		if(temp == NULL) {
        			// Both left & right are NULL
        			// Add current node
        			temp = stk.top();
        			ans.push_back(temp->data);
        			stk.pop();
        			// Now backtrack through stack, till possible
        			while(!stk.empty() && temp==stk.top()->right) {
        				temp = stk.top();
        				stk.pop();
        				ans.push_back(temp->data);
        			}
        		}
        		else { // If after 1-right move.. reached non-NULL
        			// Again move left..left..  (done by curr node)
        			curr = temp;
        		}
        	}
        }
        return ans;
    }
};

int main() {
	Solution solve;
	Node* node = takeInput();
	vector<int> ans = solve.postOrder(node);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}