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

int findNodeRec(Node *head, int n) {
	if(head == NULL) {
		return -1;
	}
	if(head->data == n) {
		return 0;
	}
	int ans1 = findNodeRec(head->next, n);
	if(ans1 == -1) {
		return -1;
	}
	else {
		return (1+ans1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		int n;
		cin >> n;
		int ans = findNodeRec(head, n);
		cout << ans << "\n";
	}
	return 0;
}