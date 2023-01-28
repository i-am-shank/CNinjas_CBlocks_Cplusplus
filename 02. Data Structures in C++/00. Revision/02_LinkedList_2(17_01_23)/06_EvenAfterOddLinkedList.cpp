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

Node *evenAfterOdd(Node *head) {
	Node *even = new Node(0);
	Node *odd = new Node(0);
	Node *tempe=even, *tempo=odd;
	Node *temp = head;
	while(temp != NULL) {
		if(temp->data % 2 == 0) {
			tempe->next = temp;
			tempe = tempe->next;
			temp = temp->next;
			tempe->next = NULL; // Disconnect
		}
		else {
			tempo->next = temp;
			tempo = tempo->next;
			temp = temp->next;
			tempo->next = NULL; // Disconnect
		}
	}
	even = even->next;
	odd = odd->next;
	if(odd != NULL) {
		tempo->next = even;
		return odd;
	}
	else {
		return even;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		Node* ans = evenAfterOdd(head);
		printLL(ans);
		if(ans != NULL) {
			cout << "\n";
		}
	}
	return 0;
}