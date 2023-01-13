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

void printReverse(Node *head) {
    if(head == NULL) {
    	return;
    }
    printReverse(head->next);
    cout << head->data << " ";
    return;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		printReverse(head);
		cout << "\n";
	}
	return 0;
}