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
	ListNode* temp = head;
	int num;
	cin >> num;
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

class Solution {
public:
	// Time : O(n) .. max. whole LL needs to be traversed
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> check;
        ListNode* temp = head;
        while(temp != NULL) {
        	if(check.count(temp) != 0) {
        		// Cycle spotted.. same node can't be accesible twice
        		return true;
        	}
        	check.insert(temp);
        	temp = temp->next;
        }
        return false; // No cycle found.. whole LL traversed
    }
};

int main() {
	ListNode* head = takeInput();
	Solution solve;
	bool ans = solve.hasCycle(head);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}