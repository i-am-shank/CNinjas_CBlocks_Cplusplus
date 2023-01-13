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

int lengthLL(Node* head) {
	if(head == NULL) {
		return 0;
	}
	return 1 + lengthLL(head->next);
}

Node *appendLastNToFirst(Node *head, int n) {
    int len = lengthLL(head);
    if(n >= len) {
    	// No change needed
    	return head;
    }
    else {
    	int x = (len-n)-1;
    	Node* temp = head;
    	while(temp!=NULL && x>0) {
    		temp = temp->next;
    		x--;
    	}
    	if(temp==NULL || temp->next==NULL) {
    		return head;
    	}
    	else {
    		Node* curr = temp->next;
    		temp->next = NULL;
    		// The new head is :-
    		Node* temp2 = curr;
    		while(temp2->next != NULL) {
    			temp2 = temp2->next;
    		}
    		temp2->next = head;
    		return curr;
    	}
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		int n;
		cin >> n;
		Node* ans = appendLastNToFirst(head, n);
		printLL(ans);
	}
	return 0;
}