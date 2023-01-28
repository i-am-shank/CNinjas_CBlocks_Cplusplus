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

Node *swapNodes(Node *head, int i, int j) {
	if(head==NULL || head->next==NULL || i==j) {
		// Nothing left to swap || No-swapping needed
		return head;
	}
	if(i==0 || j==0) {
		int x=max(i,j), idx=0;
		Node *temp = head;
		while(idx<x-1 && temp!=NULL) {
			temp = temp->next;
			idx++;
		}
		// Swap (temp->next) & (head)
		Node *save1 = temp->next;
		// save1  -->  becomes new head
		temp->next = head;
		Node *save2 = head->next;
		head->next = save1->next;
		save1->next = save2;
		return save1;
	}
	else {
		head->next = swapNodes(head->next, i-1, j-1);
		return head;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		int i, j;
		cin >> i >> j;
		Node* ans = swapNodes(head, i, j);
		printLL(ans);
		if(ans != NULL) {
			cout << "\n";
		}
	}
	return 0;
}