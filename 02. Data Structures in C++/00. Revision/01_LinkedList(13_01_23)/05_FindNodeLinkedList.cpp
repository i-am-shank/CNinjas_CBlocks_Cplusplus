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

int findNode(Node *head, int n){
    if(head == NULL) {
    	return -1;
    }
    if(head->data == n) {
    	return 0;
    }
    int smallAns = findNode(head->next, n);
    if(smallAns != -1) {
    	return (1+smallAns);
    }
    else {
    	return -1;
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node* head = takeInput();
		int n;
		cin >> n;
		int ans = findNode(head, n);
		cout << ans << "\n";
	}
	return 0;
}