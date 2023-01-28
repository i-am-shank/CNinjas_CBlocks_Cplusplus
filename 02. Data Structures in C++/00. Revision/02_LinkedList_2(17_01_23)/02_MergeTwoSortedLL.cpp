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
			// Tail of linked list
			// No more input needed.
			break;
		}
		Node* curr = new Node(ele);
		temp->next = curr;
		temp = temp->next;
	}
	head = head->next;
	return head;
}

void printLL(Node* head) {
	Node *temp = head;
	while(temp!=NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	return;
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2) {
    Node *temp1=head1, *temp2=head2;
    Node *head = new Node(0);
    Node *temp = head;
    while(temp1!=NULL && temp2!=NULL) {
    	if(temp1->data <= temp2->data) {
    		temp->next = temp1;
    		temp = temp->next;
    		temp1 = temp1->next;
    		temp->next = NULL; // Disconnecting..
    	}
    	else {
    		temp->next = temp2;
    		temp = temp->next;
    		temp2 = temp2->next;
    		temp->next = NULL; // Disconnecting..
    	}
    }
    if(temp1!=NULL) {
    	temp->next = temp1;
    	head = head->next;
    	return head;
    }
    else if(temp2!=NULL) {
    	temp->next = temp2;
    	head = head->next;
    	return head;
    }
    else{
    	head = head->next;
    	return head;
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node *head1=takeInput(), *head2=takeInput();
		Node* ans = mergeTwoSortedLinkedLists(head1, head2);
		printLL(ans);
		cout << "\n";
	}
	return 0;
}