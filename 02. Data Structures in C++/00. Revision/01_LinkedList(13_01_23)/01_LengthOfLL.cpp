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
	int ele=0;
	while(true) {
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

int length(Node *head) {
    if(head == NULL) {
    	return 0;
    }
    return 1 + length(head->next);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		int ans = length(head);
		cout << ans << "\n";
	}
	return 0;
}