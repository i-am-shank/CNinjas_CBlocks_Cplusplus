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
	Node* temp = head;
	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
	return;
}

Node *removeDuplicates(Node *head) {
    if(head == NULL) {
    	return head;
    }
    Node* temp = head->next;
    while(temp!=NULL && temp->data==head->data) {
    	temp = temp->next;
    }
    head->next = removeDuplicates(temp);
    return head;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		Node* ans = removeDuplicates(head);
		printLL(ans);
	}
	return 0;
}