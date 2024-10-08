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
    Node *inOrderSuccessor(Node *root, Node *x) {
        Node* ans = NULL;
        Node* temp = root;
        while(temp != NULL) {
        	if(temp->data > x->data) {
        		ans = temp;
        		temp = temp->left;
        	}
        	else {
        		temp = temp->right;
        	}
        }
        return ans;
    }
};

int main() {
	Node* root = takeInput();
	Node* x = takeInput();
	Solution solve;
	Node* ans = solve.inOrderSuccessor(root, x);
	if(ans == NULL) {
		cout << -1 << "\n";
	}
	else {
		cout << ans->data << "\n";
	}
	return 0;
}