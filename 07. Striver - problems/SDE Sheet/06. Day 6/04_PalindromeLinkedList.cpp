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
	ListNode* head = new ListNode();
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
	head = head->next; // remove dummy head
	return head;
}

class Solution {
	ListNode* reverseLL(ListNode* head) {
		ListNode* prev = NULL;
		ListNode* curr = head, *next = head;
		while(curr != NULL) {
			next = next->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}

	void printLL(ListNode* head) {
		ListNode* temp = head;
		while(temp != NULL) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << "\n";
		return;
	}

	bool isEqual(ListNode* head1, ListNode* head2) {
		ListNode* temp1 = head1, *temp2 = head2;
		while(temp1!=NULL && temp2!=NULL) {
			if(temp1->val != temp2->val) {
				cout << temp1->val << " " << temp2->val << "\n";
				return false; // Unequal nodes
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		return true;
	}

	ListNode* midLL(ListNode* head) {
		ListNode *fast=head, *slow=head;
		while(fast!=NULL && fast->next!=NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow; // For double mid, 2nd mid returned
	}

public:
	// Time : O(n)
    bool isPalindrome(ListNode* head) {
    	// printLL(head);
    	ListNode* mid = midLL(head);
        ListNode* head2 = reverseLL(mid);
        // printLL(head2);
        bool ans = isEqual(head, head2);
        return ans;
    }
};

int main() {
	Solution solve;
	ListNode* head = takeInput();
	bool ans = solve.isPalindrome(head);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}