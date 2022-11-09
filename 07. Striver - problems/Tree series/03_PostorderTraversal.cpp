#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
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

void postorderBT(Node* root, vector<int>& ans) {
	if(root == NULL) {
		return;
	}
	postorderBT(root->left, ans);
	postorderBT(root->right, ans);
	ans.push_back(root->data);
	return;
}

vector<int> postorder1Stack(Node* root) {
	vector<int> ans;
	if(root == NULL) {
		return ans;
	}
	stack<Node*> stk;
	Node *curr=root, *temp=NULL;
	// left..left..left  if NULL  right  left..left..left
	// Add node.. when both left & right == NULL
	while(curr!=NULL || !stk.empty()) {
		if(curr != NULL) {
			stk.push(curr);
			curr = curr->left;
		}
		else {
			temp = stk.top()->right; // move right (1 time)
			if(temp == NULL) { // Both left & right became NULL
				// Add the stk.top()
				temp = stk.top();
				stk.pop();
				ans.push_back(temp->data);
				// Now backtrack through stack.. till possible
				while(!stk.empty() && temp==stk.top()->right) {
					temp = stk.top();
					stk.pop();
					ans.push_back(temp->data);
				}
			}
			else { // if right is non-NULL again  left..left..left
				curr = temp;
			}
		}
	}
	return ans;
}

vector<int> postorderStack(Node* root) {
	vector<int> ans;
	stack<Node*> stk1, stk2;
	if(root == NULL) {
		return ans;
	}
	stk1.push(root);
	while(!stk1.empty()) {
		Node* top = stk1.top();
		stk1.pop();
		stk2.push(top);
		if(top->left != NULL) {
			stk1.push(top->left);
		}
		if(top->right != NULL) {
			stk1.push(top->right);
		}
	}
	while(!stk2.empty()) {
		Node* top = stk2.top();
		stk2.pop();
		ans.push_back(top->data);
	}
	return ans;
}

vector<int> postOrder(Node* root) {
	vector<int> ans;
	postorderBT(root, ans);
	return ans;
}

int main() {
	Node* root = takeInput();
	vector<int> ans = postOrder(root);
	vector<int> ans2 = postorderStack(root);
	vector<int> ans3 = postorder1Stack(root);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	for(int i=0; i<ans2.size(); i++) {
		cout << ans2[i] << " ";
	}
	cout << "\n";
	for(int i=0; i<ans3.size(); i++) {
		cout << ans3[i] << " ";
	}
	cout << "\n";
	return 0;
}