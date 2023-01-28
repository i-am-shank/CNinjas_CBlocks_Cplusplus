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

Node *midPoint(Node *head) {
    Node *fast=head, *slow=head;
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL) {
    	// As 1st mid of 2-middle nodes are required
    	// So adding the 3rd condition above.
    	fast = fast->next->next;
    	slow = slow->next;
    }
    return slow;
}

void printLL(Node* head) {
	if(head == NULL) {
		// Print nothing
		return;
	}
	else{
		cout << head->data << "\n";
		return;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		Node* ans = midPoint(head);
		// Print the (ans) linked-list node
		printLL(ans);
	}
	return 0;
}