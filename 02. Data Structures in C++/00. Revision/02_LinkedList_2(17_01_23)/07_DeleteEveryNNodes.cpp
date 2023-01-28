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

Node *skipMdeleteN(Node *head, int M, int N) {
	if(M == 0) {
		return NULL;
	}
	Node *temp = head;
	while(temp != NULL) {
		// Retain M nodes
		Node* curr = temp;
		Node* tcurr = curr;
		int tm=M, tn=N;
		while(tcurr!=NULL && tm>1) {
			tcurr = tcurr->next;
			tm--;
		}
		Node* tskip = tcurr;
		if(tcurr == NULL) {
			break;
			// <= M nodes remaining
		}
		else {
			tskip = tcurr->next;
			tcurr->next = NULL;
			// Skip N nodes
			// .. by changing temp to next node
			while(tskip!=NULL && tn>=1) {
				tskip = tskip->next;
				tn--;
			}
			if(tskip == NULL) {
				break;
				// No nodes left to skip
			}
			else {
				// Connect after skipping
				tcurr->next = tskip;
				temp = tskip;
				// Ready for next iteration
			}
		}
	}
	// head = head->next;
	return head;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node *head = takeInput();
		int M, N;
		cin >> M >> N;
		Node* ans = skipMdeleteN(head, M, N);
		printLL(ans);
		if(ans != NULL) {
			cout << "\n";
		}
	}
	return 0;
}