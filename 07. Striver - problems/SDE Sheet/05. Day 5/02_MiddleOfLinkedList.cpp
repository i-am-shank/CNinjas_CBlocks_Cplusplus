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

class Solution {
public:
	// Time : O(n)
	// Space : O(n)
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast!=NULL && fast->next!=NULL) {
        	fast = fast->next->next;
        	slow = slow->next;
        }
        return slow; // If 2 mid-nodes .. 2nd mid-node returned
    }
};

int main() {
	ListNode* head = takeInput();
	Solution solve;
	ListNode* ans = solve.middleNode(head);
	cout << ans->val << "\n";
	return 0;
}