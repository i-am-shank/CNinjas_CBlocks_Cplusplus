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

Node *reverseLinkedListRec(Node *head) {
	if(head==NULL || head->next==NULL) {
		return head;
	}
	Node *newHead = reverseLinkedListRec(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}

Node *reverseLinkedList(Node *head) {
    if(head==NULL || head->next==NULL) {
    	return head;
    }
    Node *prev=NULL, *curr=head, *next1=head;
    while(curr != NULL) {
    	next1 = curr->next;
    	curr->next = prev;
    	prev = curr;
    	curr = next1;
    }
    return prev;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		Node* ans = reverseLinkedListRec(head);
		printLL(ans);
		if(ans != NULL) {
			cout << "\n";
		}
	}
	return 0;
}