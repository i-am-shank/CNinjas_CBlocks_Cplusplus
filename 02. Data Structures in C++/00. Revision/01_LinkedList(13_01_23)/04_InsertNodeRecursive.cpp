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

Node* insertNode(Node *head, int i, int data) {
	if(head==NULL) {
		if(i!=0) {
			return head;
		}
		else {
			Node* curr = new Node(data);
			return curr;
		}
	}
	if(i == 0) {
		Node* curr = new Node(data);
		curr->next = head;
		return curr;
	}
	Node* ans = insertNode(head->next, i-1, data);
	head->next = ans;
	return head;
}

Node* insertNode2(Node *head, int i, int data) {
	if(i == 0) {
		Node* curr = new Node(data);
		curr->next = head;
		return curr;
	}
	Node* temp = head;
	while(temp!=NULL && i>1) {
		temp = temp->next;
		i--;
	}
	if(temp == NULL) {
		// i > length of LL
		return head;
	}
	else if(temp->next == NULL) {
		// i = length of LL
		// insert at tail
		Node* curr = new Node(data);
		temp->next = curr;
		return head;
	}
	else {
		Node* curr = new Node(data);
		Node* save = temp->next;
		temp->next = curr;
		curr->next = save;
		return head;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		int i, data;
		cin >> i >> data;
		Node* ans = insertNode(head, i, data);
		printLL(ans);
	}
	return 0;
}