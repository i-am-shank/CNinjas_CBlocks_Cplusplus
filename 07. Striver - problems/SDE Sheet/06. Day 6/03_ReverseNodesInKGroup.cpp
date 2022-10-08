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
	ListNode* head= new ListNode();
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

void printLL(ListNode* head) {
	ListNode* temp = head;
	while(temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << "\n";
	return;
}

class Solution {
	ListNode* reverseLL(ListNode* head) {
		ListNode *prev=NULL, *curr=head, *next=head;
		while(next != NULL) {
			next = next->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* head1 = head, *tail1= head;
        int i=1;
        while(tail1!=NULL && i<k) {
        	i++;
        	tail1 = tail1->next;
        }
        if(tail1 == NULL) {
        	return head; // No further reverse-k possible
        }
        else {
        	ListNode* head2 = tail1->next;
        	tail1->next = NULL;
        	ListNode* head3 = reverseLL(head1);
        	ListNode* tail3 = head3;
        	while(tail3->next != NULL) {
        		tail3 = tail3->next;
        	}
        	// tail3 -> tail of reversed LL (head3)
        	ListNode* head4 = reverseKGroup(head2, k);
        	tail3->next = head4;
        	return head3;
        }
    }
};

int main() {
	ListNode* head = takeInput();
	int k;
	cin >> k;
	Solution solve;
	ListNode* ans = solve.reverseKGroup(head, k);
	printLL(ans);
	return 0;
}