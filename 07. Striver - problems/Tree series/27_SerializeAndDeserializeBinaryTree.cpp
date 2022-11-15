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
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        vector<int> arr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
        	int s = q.size();
        	while(s--) {
        		Node* front = q.front();
	        	q.pop();
	        	if(front == NULL) {
	        		arr.push_back(-1);
	        		continue;
	        	}
	        	else {
	        		arr.push_back(front->data);
	        		q.push(front->left);
	        		q.push(front->right);
	        	}
        	}
        }
        return arr;
    }

    //Function to deserialize a list and construct the tree.
    Node* deSerialize(vector<int> &arr) {
    	int n = arr.size();
    	if(n == 0) {
    		return NULL;
    	}
    	queue<Node*> q;
    	int i=1;
    	Node* root = new Node(arr[0]);
    	q.push(root);
    	while(!q.empty()) {
    		Node* front = q.front();
    		q.pop();
    		if(arr[i] != -1) {
    			Node* leftChild = new Node(arr[i]);
    			front->left = leftChild;
    			q.push(leftChild);
    		}
    		else {
    			front->left = NULL;
    		}
    		if(arr[i+1] != -1) {
    			Node* rightChild = new Node(arr[i+1]);
    			front->right = rightChild;
    			q.push(rightChild);
    		}
    		else {
    			front->right = NULL;
    		}
    		i+=2;
    	}
    	return root;
    }
};

void inorder(Node* root) {
	if(root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
	return;
}

int main() {
	Solution solve;
	Node* root = takeInput();
	vector<int> arr = solve.serialize(root);
	Node* root2 = solve.deSerialize(arr);
	inorder(root2);
	return 0;
}