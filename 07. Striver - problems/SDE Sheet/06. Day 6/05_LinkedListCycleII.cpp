#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* takeInput() {
	ListNode* head = new ListNode(0);
	int num;
	cin >> num;
	ListNode* temp = head;
	while(num--) {
		int data;
		cin >> data;
		ListNode* node = new ListNode(data);
		temp->next = node;
		temp = temp->next;
	}
	head = head->next; // remove dummy head
	return head;
}

class Solution {
public:
	// Time : O(n)
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> check;
        ListNode* temp = head;
        while(temp!=NULL) {
        	if(check.count(temp) > 0) {
        		return temp;
        		// Starting point of cycle
        	}
        	temp = temp->next;
        }
        return temp; // Will be NULL, if no cycle
    }
};

int main() {
	ListNode* head = takeInput();
	Solution solve;
	ListNode* ans = solve.detectCycle(head);
	cout << ans->val << "\n";
	return 0;
}