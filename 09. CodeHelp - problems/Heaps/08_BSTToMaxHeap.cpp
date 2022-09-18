#include <bits/stdc++.h>
using namespace std;

struct Node {
public:
    int data;
    Node *left, *right;

    Node(int data) { // constructor
    	this->data = data;
    	left=NULL;
    	right=NULL;
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

void printTree(Node* root) {
	if(root == NULL) {
		return;
	}
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* front = q.front();
		q.pop();
		cout << front->data << " ";
		if(front->left != NULL) {
			q.push(front->left);
		}
		if(front->right != NULL) {
			q.push(front->right);
		}
	}
	return;
}

class Solution{
	// First traverse inorder.. always sorted array
	// As its a BST !!
	// Now place smaller elements in bottom.. & save larger for upper places
	// Post order traversal.. with the array corresponding values
	void postOrder(Node* root, vector<int>& arr, int &index) {
		if(root == NULL) {
			return;
		}
		postOrder(root->left, arr, index);
		postOrder(root->right, arr, index);
		root->data = arr[index];
		index++;
		return;
	}

	void inorder(Node* root, vector<int>& arr) {
		if(root == NULL) {
			return;
		}
		inorder(root->left, arr);
		arr.push_back(root->data);
		inorder(root->right, arr);
		return;
	}

  public:

    void convertToMaxHeapUtil(Node* root) {
    	Node* temp = root;
    	vector<int> arr;
    	inorder(temp, arr); // Array prepared
    	// Now construct tree .. arr is level-order traversal
    	int index = 0;
    	postOrder(root, arr, index);
    	return;
    }
};

int main() {
	Solution solve;
	Node* root = takeInput();
	solve.convertToMaxHeapUtil(root);
	printTree(root);
	cout << endl;
	return 0;
}