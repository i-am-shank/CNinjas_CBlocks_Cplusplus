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

void printLL(Node* head) {
	if(head == NULL) {
		return;
	}
	cout << head->data << " ";
	printLL(head->next);
	return;
}

Node* reverseLL(Node* head) {
	if(head==NULL || head->next==NULL) {
		return head;
	}
	Node* save = reverseLL(head->next);
	head->next->next = head;
	head->next = NULL;
	return save;
}

bool isPalindrome(Node *head) {
	if(head==NULL) {
		return true;
	}
    Node* fast=head, *slow=head;
    while(fast!=NULL && fast->next!=NULL) {
    	fast = fast->next->next;
    	slow = slow->next;
    }
    // printLL(slow);
    // cout << "\n";
    Node* curr = reverseLL(slow);
    // printLL(curr);
    // cout << "\n";
    Node* temp1=head, *temp2=curr;
    while(temp2!=NULL) {
    	if(temp1->data != temp2->data) {
    		return false;
    		// Matching failed
    	}
    	else {
    		temp2 = temp2->next;
    		temp1 = temp1->next;
    	}
    }
    return true;
    // All matched till here
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		bool ans = isPalindrome(head);
		cout << (ans == true ? "true" : "false") << "\n";
	}
	return 0;
}