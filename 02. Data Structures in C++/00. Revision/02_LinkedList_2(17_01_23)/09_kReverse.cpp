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

Node* reverseLL(Node* head) {
	if(head==NULL || head->next==NULL) {
		return head;
	}
	Node* newHead = reverseLL(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}

Node *kReverse(Node *head, int k) {
	int i=0;
	Node* temp = head;
	while(i<k-1 && temp!=NULL) {
		temp = temp->next;
		i++;
	}
	if(temp==NULL || temp->next==NULL) {
		// Reverse whole current LL
		Node *ans = reverseLL(head);
		return ans;
	}
	else {
		Node *head2 = temp->next;
		temp->next = NULL;
		Node* head3 = kReverse(head2, k);
		Node* head4 = reverseLL(head);
		// head .. tail of head4
		head->next = head3;
		return head4;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		int k;
		cin >> k;
		Node* ans = kReverse(head, k);
		printLL(ans);
		if(ans != NULL) {
			cout << "\n";
		}
	}
	return 0;
}