#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

Node* takeInput() {
	Node* head = new Node(0);
	Node* temp = head;
	while(true) {
		int ele;
		cin >> ele;
		if(ele == -1) {
			head = head->next;
			return head;
		}
		Node* curr = new Node(ele);
		temp->next = curr;
		temp = temp->next;
	}
	head = head->next;
	return head;
}

Node* deleteNode(Node* head, int pos) {
	if(head == NULL) {
		return head;
		// No node left to be deleted
	}
	if(pos == 0) {
		return head->next;
	}
	if(head->next!=NULL && pos==1) {
		// Next node deleted
		head->next = head->next->next;
		return head;
	}
	head->next = deleteNode(head->next, pos-1);
	return head;
}

Node *deleteNode2(Node *head, int pos) {
	if(head == NULL) {
		return head;
	}
	if(pos == 0) {
		return head->next;
	}
    Node* temp = head;
    while(temp!=NULL && pos>1) {
    	temp = temp->next;
    	pos--;
    }
    if(temp==NULL || temp->next==NULL) {
    	return head;
    	// pos > length
    }
    else {
    	// Skip the next node
    	temp->next = temp->next->next;
    	return head;
    }
}

void printLL(Node* head) {
	Node* temp = head;
	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
	return;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		int pos;
		cin >> pos;
		Node* ans = deleteNode(head, pos);
		printLL(ans);
	}
	return 0;
}