#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* takeInput() {
	int num;
	cin >> num;
	ListNode* head = new ListNode();
	ListNode* temp = head;
	while(num--) {
		int data;
		cin >> data;
		ListNode* node = new ListNode(data);
		temp->next = node;
		temp = temp->next;
	}
	head = head->next; // removing dummy head
	return head;
}

void printLL(ListNode* head) {
	if(head == NULL) {
		return;
	}
	ListNode* temp = head;
	while(temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << "\n";
	return;
}

class Solution {
public:
	// Time : O(1)
    void deleteNode(ListNode* node) {
    	// Can't delete current node
    	// Can delete next node (as it's given.. is non-NULL)
    	// Delete next node.. replace value of next-node with current node's
        int data = node->next->val;
        node->val = data;
        node->next = node->next->next;
        return;
    }
};

int main() {
	ListNode* head = takeInput();
	int node;
	cin >> node;
	ListNode* delNode = head;
	while(delNode->val != node) {
		delNode = delNode->next;
	}
	Solution solve;
	solve.deleteNode(delNode);
	printLL(head);
	return 0;
}