#include <bits/stdc++.h>
using namespace std;

// Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node* takeInput() {
	Node* head = new Node(0);
	Node* down = head;
	Node* right = head;
	int num;
	cin >> num;
	while(num--) {
		Node* 
	}
}

Node* takeInput() {
	Node* head = new Node(0);
	Node* down = head;
	int count;
	cin >> count;
	while(count--) {
		int data;
		cin >> data;
		Node* node = new Node(data);
		down->bottom = node;
		down = down->bottom;
	}
	head = head->bottom;
	Node* temp = head;
	int rightCount;
	cin >> rightCount;
	while(rightCount--) {
		Node* node = takeInput();
		temp->next = node;
		temp = temp->next;
	}
	return head;
}

Node* merge(Node* head1, Node* head2) {
	// head1 & head2 -> sorted order
	Node* head = new Node(0);
	Node* temp = head;
	Node* temp1 = head1, *temp2 = head2;
	while(temp1!=NULL && temp2!=NULL) {
		if(temp1->data <= temp2->data) {
			temp->bottom = temp1;
			temp = temp->bottom;
			temp1 = temp1->bottom;
		}
		else {
			temp->bottom = temp2;
			temp = temp->bottom;
			temp2 = temp2->bottom;
		}
	}
	if(temp1 != NULL) {
		temp->bottom = temp1;
	}
	else {
		temp->bottom = temp2;
	}
	head = head->bottom;
	return head;
}

Node *flatten(Node *root) {
	if(root==NULL || root->next==NULL) {
		return root;
	}
	root->next = flatten(root->next); // Merge-sort after LLs
	root = merge(root, root->next);
	return root;
}

int main() {
	Node* head = takeInput();

}