#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
	// Time : O(n)
	// Space : O(1)
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head;
        while(next != NULL) {
        	next = next->next;
        	curr->next = prev;
        	prev = curr;
        	curr = next;
        }
        return prev;
    }
};

int main() {
	ListNode* head = takeInput();
	Solution solve;
	ListNode* ans = solve.reverseList(head);
	printLL(ans);
	return 0;
}