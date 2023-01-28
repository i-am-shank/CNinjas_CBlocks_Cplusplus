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

Node* mergeSortedLLs(Node* head1, Node* head2) {
	Node* head = new Node(0);
	Node *temp = head;
	Node *temp1=head1, *temp2=head2;
	while(temp1!=NULL && temp2!=NULL) {
		if(temp1->data <= temp2->data) {
			temp->next = temp1;
			temp = temp->next;
			temp1 = temp1->next;
			temp->next = NULL; // Disconnect
		}
		else {
			temp->next = temp2;
			temp = temp->next;
			temp2 = temp2->next;
			temp->next = NULL;
		}
	}
	if(temp1 != NULL) {
		temp->next = temp1;
	}
	if(temp2 != NULL) {
		temp->next = temp2;
	}
	head = head->next;
	return head;
}

Node *mergeSort(Node *head) {
	if(head==NULL || head->next==NULL) {
		return head;
	}
	Node *fast=head, *slow=head;
	while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	Node* head1 = head;
	Node* head2 = slow->next;
	slow->next = NULL; // disconnect both halves
	Node *temp1=mergeSort(head1);
	Node *temp2=mergeSort(head2);
	Node* ans = mergeSortedLLs(temp1, temp2);
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		Node* ans = mergeSort(head);
		printLL(ans);
		if(ans != NULL) {
			cout << "\n";
		}
	}
	return 0;
}