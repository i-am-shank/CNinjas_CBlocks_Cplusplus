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

void printIthNode(Node *head, int i) {
    Node* temp = head;
    while(temp!=NULL && i>0) {
    	temp = temp->next;
    	i--;
    }
    if(temp == NULL) {
    	return; // reached NULL
    }
    else {
    	cout << temp->data << "\n";
    	return;
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		int i;
		cin >> i;
		printIthNode(head, i);
	}
	return 0;
}