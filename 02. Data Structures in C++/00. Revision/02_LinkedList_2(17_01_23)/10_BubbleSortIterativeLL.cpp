#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int data) { // constructor
		this->data = data;
		this->next = NULL;
	}
};

Node* takeInput() {
	Node* head = new Node(0);
	Node *temp = head;
	while(true) {
		int ele;
		cin >> ele;
		if(ele == -1) {
			// Tail of LL
			break;
		}
		Node *curr = new Node(ele);
		temp->next = curr;
		temp = temp->next;
	}
	head = head->next;
	return head;
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

Node *bubbleSort(Node *head) {
	if(head==NULL || head->next==NULL) {
		return head;
	}
	Node *head2 = bubbleSort(head->next);
	head->next = NULL;
	int idx=0;
	Node* temp=head2;
	while(temp!=NULL && temp->data<head->data) {
		temp = temp->next;
		idx++;
	}
	// cout << head->data << " - " << idx << "\n";
	if(idx == 0) { // Add at start
		head->next = head2;
		return head;
	}
	else { // Add in mid OR end
		int idx2=0;
		Node* temp2 = head2;
		while(idx2 < idx-1) {
			temp2 = temp2->next;
			idx2++;
		}
		temp2->next = head;
		head->next = temp;
		return head2;
	}
}

int main() {
	Node *head = takeInput();
	Node *ans = bubbleSort(head);
	printLL(ans);
	return 0;
}